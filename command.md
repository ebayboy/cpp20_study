
+ 删除目录下所有二进制文件: find . -type f  | xargs file --mime-type  | grep application | awk -F: '{ print $1}' | xargs rm

