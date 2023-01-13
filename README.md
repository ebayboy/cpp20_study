# cpp20_study
cpp20_study

# c20协程(https://zhuanlan.zhihu.com/p/569480618)
# advanced-cpp20-programming
# [现代C++](https://changkun.de/modern-cpp/zh-cn/00-preface/)

# DONE
+ [C++之future和promise](https://zhuanlan.zhihu.com/p/595537357)


# TODO:
+ nginx + lua [Done]
+ nginx + cpp20开发
+ cpp20 tcp 协程并发服务
+ cpp20 http 协程并发服务
+ dpdk + cpp开发

# 方向
## 负载均衡
	+ c/cpp(lua没用)
	+ (ALB)docker L7: nginx
	+ (ALB)docker L4: stream(支持SSL证书及卸载、会话保持等ALB L7特性)
	+ (NLB): dpdk实现, 支持会话保持
	+ L4/L7前置物理机: dpdk
	+ 容器： dpdk在容器里跑意义不大
	+ 
## WAF
	+ nginx + lua
	+ golang(cpp用处不大)

## 传统安全网关（nginx + lua + cpp)
	+ 负载均衡
	+ WAF

