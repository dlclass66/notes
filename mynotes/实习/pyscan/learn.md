
# 基本介绍

自动化 多线程执行渗透任务全流程操作的工具

# 开发需求

给工具增加一个工作线程 可以使用nuc进行漏洞检测

# 现有软件架构

只讨论与漏洞检测相关的部分

## 线程架构

python_scan.py 是主进程 也就是执行入口 有四个工作线程

1. task_thread 端口检测线程
2. dirsearch_task_thread 目录爆破线程
3. vulcheck_task_thread 漏洞检测线程
4. vulexp_task_thread 漏洞利用线程

## 代码结构

这4个工作线程的对应的文件在utils文件夹中 其对应的调用在spaceMaptask中

## 工作流程

在项目的同一目录下.\TaskInfo\task\vulcheck 里面存放扫描任务的要求 使用json格式 
示例如下

```json
{
    "task_id":"1",  
    "scanner_id":"1",  
    "args":"3",  //决定了使用哪种方式进行扫描
    "target":"172.25.231.39",
    "severity":"medium" //扫描漏洞级别
}
```

vulcheck_task_monitor 这个函数会解析文件内容 调用函数执行任务 执行完的结果会被被保存到./result/vulcheck/

# 添加方式

给vulcheck_task_monitor增加一个调用函数 调用nuclei进行扫描 然后通过task_info里的args字段判断是否要调用nuclei
添加了一个按漏洞级别筛选poc的字段

# 待完善部分

增加一个进度条显示功能