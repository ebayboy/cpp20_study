
+ 删除目录下所有二进制文件: find . -type f  | xargs file --mime-type  | grep application | awk -F: '{ print $1}' | xargs rm
+ 计算文件行数(最下面有total总行数)： find . -name "*.c" | xargs  wc -l | sort  -n -k1
