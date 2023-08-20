
# 基本介绍

一个python自动化脚本 使用指定漏洞exp进行攻击 默认payload reverse——tcp 自动执行后渗透 并且保存结果

# 基本思路

根据python程序的参数 动态生成rc文档（msfconsole可以自动执行 支持每行一个命令或者内嵌ruby脚本）然后msf执行这些命令

# 遇到的问题

1. 后渗透的命令需要在msf的meterpreter 这个session中执行 而不是在msfconsole中执行 这就不能使用最开始的rc文档解决 解决方案 使用spool将命令行结果全部输出到指定文件 但是会有乱码 可读性较差 需要后期处理 一种方法是使用cat命令查看
2. 找到了session对应的命令和执行结果在数据库中的执行结果 database msf table session_events 但是只有手动输入的记录会在里面 如果是autorunscript执行的结果不会在里面

