# cpp20_study
cpp20_study

# c20协程(https://zhuanlan.zhihu.com/p/569480618)
# advanced-cpp20-programming
+ [github C++开源项目排行榜](https://www.githubs.cn/top/C%2B%2B)
+ [996icu](https://github.com/996icu/996.ICU/blob/master/README_CN.md)
+ [C++面试知识总结](https://github.com/huihut/interview)
+ [CPlusPlusThings]（https://github.com/Light-City/CPlusPlusThings）
+ [现代C++](https://changkun.de/modern-cpp/zh-cn/00-preface/)
+ [spodlog用法](https://blog.csdn.net/haojie_superstar/article/details/89383433?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-19.control&dist_request_id=1328730.643.16167433128441371&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-19.control)
+ [leecode cpp](https://github.com/haoel/leetcode/tree/master/algorithms/cpp)
+ [9大web服务框架](https://www.linuxlinks.com/free-open-source-cplusplus-web-frameworks/)
+ [C++之future和promise](https://zhuanlan.zhihu.com/p/595537357)

## 近期TODO：
+ cpp adv 5

+ 增加增加的web安全的深入 
	+ sql注入学习
	+ modsecurity : 

+ 学习drogon: 可以哦在基于http的二次应用开发(nginx可替代方案)
	+ drogon使用方法
	+ drogon架构
	+ drogon详细代码走读


# TODO:
+ drogon学习
+ lua学习
+ study ngx_cpp_module
+ study ngx_http_cppjieba_module
+ stream + lua
+ skynet server
+ nginx + cpp20开发
+ cpp20 tcp 协程并发服务
+ cpp20 http 协程并发服务
+ vsocde PlantUML使用入门
+ muduo网络库性能最高(比libevent2性能略高, 部分调用C头文件)
+ handy C++11网络库(相当于muduo的C++11轻量化版本）

+ dpdk + cpp开发
+ 学习handy网络库, 成为开源贡献者
+ 学习skynet

# 代码行数
+ drogon: 最够的web框架, 比fasthttp快2倍
+ handy: 2444
+ skynet: 核心代码5590行, 2000行C代码service, 3000行lua service
+ nginx 20w, http 10w
+ dpvs: 核心代码51811

# 产品方向
## 负载均衡
	+ c/cpp(lua没用)
	+ (ALB)docker L7: nginx
	+ (ALB)docker L4: stream(支持SSL证书及卸载、会话保持等ALB L7特性)
	+ (NLB): dpdk实现, 支持会话保持
	+ L4/L7前置物理机: dpdk
	+ 容器： dpdk在容器里跑意义不大
	+ 阿里云ALB只支持http/https， 不支持tcp（推测只用了nginx的7层) , NLB用了dpdk
    + 京东云ALB支持http/https/tcp/udp/tls等(用了nignx的4/7层）, NLB用了dpdk

## WAF
	+ nginx + lua
	+ golang(cpp用处不大)

## 传统安全网关（nginx + lua + cpp)
	+ 负载均衡
	+ WAF

## DONE
	+ nginx + lua test [Done]
	+ google test 压测 && 单元测试 [done]


## 手脚架：
	+ [My编程脚手架](git@github.com:ebayboy/cpp_frame.git)
	+ benchmark
	+ gtest

## 专精开发
	+ C++ server
	+ lua 在skynet game server开发中也有应用

## 技术方向：
	+ skynet C + lua修炼
	+ drogon C++14/17/20修炼


