
# 基本介绍

自动化 多线程执行渗透任务全流程操作的工具

# 开发需求

给工具增加一个工作线程 可以使用nuc进行漏洞检测

# 现有软件架构

python_scan.py 是主进程 也就是执行入口 有四个工作线程

1. task_thread 端口检测线程
2. dirsearch_task_thread 目录爆破线程
3. vulcheck_task_thread 漏洞检测线程
4. vulexp_task_thread 漏洞利用线程