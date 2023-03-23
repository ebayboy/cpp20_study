/*
使用 epoll 写的回射服务器
将从client中接收到的数据再返回给client
*/
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

using namespace std;

#define MAXLINE 100
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5000
#define INFTIM 1000

void setnonblocking(int sock) {
    int opts;
    opts = fcntl(sock, F_GETFL);
    if (opts < 0) {
	perror("fcntl(sock,GETFL)");
	exit(1);
    }
    opts = opts | O_NONBLOCK;
    if (fcntl(sock, F_SETFL, opts) < 0) {
	perror("fcntl(sock,SETFL,opts)");
	exit(1);
    }
}

int main(int argc, char *argv[]) {
    int i, maxi, listenfd, connfd, sockfd, epfd, nfds, portnumber;
    ssize_t n;
    char line[MAXLINE];
    socklen_t clilen;
    string szTemp("");

    if (2 == argc) {
	if ((portnumber = atoi(argv[1])) < 0) {
	    fprintf(stderr, "Usage:%s portnumber\a\n", argv[0]);
	    return 1;
	}
    } else {
	fprintf(stderr, "Usage:%s portnumber\a\n", argv[0]);
	return 1;
    }
    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    struct epoll_event events[20];  // 单次epoll_wait最多读取事件数量

    // 1. create epfd
    epfd = epoll_create(256);

    // 2. create listenfd
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    setnonblocking(listenfd);

    // 3. create epoll_event
    struct epoll_event ev;
    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;  // 监听读取事件 | ET 模式

    // 4. add listenfd + event to epfd
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    bzero(&serveraddr, sizeof(serveraddr)); /*配置Server socket的相关信息 */
    serveraddr.sin_family = AF_INET;
    char *local_addr = (char *)"127.0.0.1";
    inet_aton(local_addr, &(serveraddr.sin_addr));  // htons(portnumber);
    serveraddr.sin_port = htons(portnumber);
    bind(listenfd, (sockaddr *)&serveraddr, sizeof(serveraddr));

    // 5. listen
    listen(listenfd, LISTENQ);

    maxi = 0;

    for (;;) {
	// 6. 等待epoll事件的发生
	// 返回需要处理的事件数目nfds，如返回0表示已超时。
	nfds = epoll_wait(epfd, events, 20, 500);

	// 7. 遍历 && 处理所发生的所有事件
	for (i = 0; i < nfds; ++i) {
	    // 8. 处理新连接
	    // 如果新监测到一个SOCKET用户连接到了绑定的SOCKET端口，建立新的连接。
	    if (events[i].data.fd == listenfd) {
		connfd = accept(listenfd, (sockaddr *)&clientaddr, &clilen);
		if (connfd < 0) {
		    perror("connfd < 0");
		    exit(1);
		}
		// setnonblocking(connfd);
		char *str = inet_ntoa(clientaddr.sin_addr);
		cout << "accapt a connection from " << str << endl;

		// 设置用于读操作的文件描述符
		ev.data.fd = connfd;

		// 设置用于注册的读操作事件
		ev.events = EPOLLIN | EPOLLET;

		// 注册ev
		epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev); /* 添加 */
	    }

	    // 9. EPOLLIN 数据读事件
	    // 如果是已经连接的用户，并且收到数据，那么进行读入。
	    else if (events[i].events & EPOLLIN) {
		cout << "EPOLLIN" << endl;
		if ((sockfd = events[i].data.fd) < 0) {
		    continue;
		}
		if ((n = recv(sockfd, line, sizeof(line), 0)) < 0) {
		    // Connection
		    // Reset:你连接的那一端已经断开了，而你却还试着在对方已断开的socketfd上读写数据！
		    if (errno == ECONNRESET) {
			close(sockfd);
			events[i].data.fd = -1;
		    } else
			std::cout << "readline error" << std::endl;
		} else if (n == 0)  // 读入的数据为空
		{
		    close(sockfd);
		    events[i].data.fd = -1;
		}

		szTemp = "";
		szTemp += line;
		szTemp = szTemp.substr(
		    0, szTemp.find('\r')); /* remove the enter key */
		memset(line, 0, 100);	   /* clear the buffer */
		// line[n] = '\0';
		cout << "Readin: " << szTemp << endl;

		// 设置用于写操作的文件描述符
		ev.data.fd = sockfd;

		// 设置用于注册的写操作事件
		ev.events = EPOLLOUT | EPOLLET;

		// 修改sockfd上要处理的事件为EPOLLOUT
		epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev); /* 修改 */

	    }
	    // 10. 处理EPOLL_OUT 写事件
	    else if (events[i].events & EPOLLOUT)  // 如果有数据发送

	    {
		sockfd = events[i].data.fd;
		szTemp = "Server:" + szTemp + "\n";
		send(sockfd, szTemp.c_str(), szTemp.size(), 0);

		// 设置用于读操作的文件描述符
		ev.data.fd = sockfd;

		// 设置用于注册的读操作事件
		ev.events = EPOLLIN | EPOLLET;

		// 修改sockfd上要处理的事件为EPOLIN
		epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev); /* 修改 */
	    }
	}  //(over)处理所发生的所有事件
    }	   //(over)等待epoll事件的发生

    close(epfd);

    return 0;
}

