# crt startup code

crt是指 c runtime library
启动码函数会先于main执行 其中会调用main 不建议自己写
启动码程序的主要功能有以下两个

1. 使crt正确初始化
2. 使静态对象的构造函数可以在正确的时机执行

linux系统可以再gcc 编译命令后加上-e 后面加上函数名 指定进入点
windods 的vc大概有三个版本的启动码函数 第一个是文字版的 第二个是图形化界面的 第三个是动态链接库（dll）的

# 简单的内存管理 把大小相同的区块串在一起

## 主要动作

主要有九个动作 第八个是调用main（）

### heap_init

堆初始化 需要sbh 初始化（small block heap）现在这一部分已经是由操作系统管理了
旧版（小于1k的由sbh处理）先申请一个crt堆 然后进行下一步 debug模式下得到的区块都会被组织成一个双向链表

#### sbh

会在crt的heap中先申请16个header

### ioinit

在debug模式下会先加上debug所需的数据 算出大小 从sbh申请区块
