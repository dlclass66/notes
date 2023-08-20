awk -F "[:,]"
    '/Server version:/{print "serverVersion:" $NF}
    /Server number:/{print "serverName:" $NF}
    /OS Name:/{print "osName:" $(NF - 2) "\n" "osVersion:" $NF}'
    nowcoder.txt

'要求从日志中提取指定内容 注意正则匹配会把一行当作一个字符串 $NF 表示最后一个字段 $(NF - 2) 表示倒数第3个字段'
