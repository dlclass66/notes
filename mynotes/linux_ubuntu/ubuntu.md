
# 1.ubuntu安装java开发环境
## 1.安装jdk
教程
<https://blog.csdn.net/qq_42557044/article/details/124935468>
## 2.安装eclipse
教程        
<http://www.bjpowernode.com/hot/369.html>   
利用文中提到的创建快捷方式的方式也可以为其他程序所用
*不过创建的只是下载器*
# 2. ubuntu自动化
## 1.脚本
教程    
<https://blog.csdn.net/qq_41501216/article/details/88626104>
脚本文件的第一行表示要使用的终端
## 2.创建链接
*ln 命令待深入学习*
### 1.在桌面放置文件夹链接
ctrl + shift +鼠标左键拖动文件夹到桌面
# 3.命令
[常用命令](../计算机基础知识/linux_ubuntu命令.md)
# 4.使ubuntu更为易用的操作
[操作](../计算机基础知识/操作系统.md#2使ubuntu更为易用的操作)
# 5.ubuntu安装c/cpp开发环境
## 1.gcc和g++
* *利用build-essential安装*
```java
sudo apt install build-essential
```
* 多版本共存 *使用update-alternatives*
<http://www.linuxeye.com/Linux/alternatives.html> *update-alternatives的简单介绍*
 ```java
 ls /usr/bin/gcc*
 //查看已安装的gcc版本
 ls /usr/bin/g++*
 //查看已安装的g++版本 
 sudo update-alternatives --config gcc
 //编辑使用的gcc版本
 sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 50
 //增加g++的可用版本并设置优先级
 ```