#include <zmq.hpp>
#include <iostream>

using namespace std;

//g++ -c  zmq_test.cpp -std=c++20 -I /usr/local/libzmq/include/ -I /usr/local/cppzmq/include/
//g++ zmq_test.o -std=c++20 -lzmq -L /usr/local/libzmq/lib/ -o zmq_test
int main()
{
	cout << "zmq start ...\n";
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
	cout << "zmq end!\n";
}
