# 1.权限相关
```java
sudo -i 
//获得root权限（用于权限不够的情况）
exit
//退出root
```
# 2.安装相关
```java
sudo apt install 
//后面加上想安装的软件包名
sudo dpkg -i *.deb
//安装deb软件 *代表所有
sudo apt update
//更新软件列表
sudo apt upgrade
//更新本机已有并且软件列表里有的软件
```
# 3.文件操作
## 1. 列出当前文件夹所有文件，确定当前文件夹
```java
ls -al
//列出当前文件夹所有文件
pwd
//显示当前文件夹目录
```
## 2.进入文件夹
```java
cd home/workspace
//cd后面加上地址
cd ..
//返回上一级
```
## 3.在当前文件夹创建新文件夹
```java
mkdir workspace
//mkdir 后面加文件夹名
```
## 4.解压
```java
tar -zxvf hit-oslab-linux-20110823.tar.gz \
-C /home/shiyanlou/
//-C后面是想解压到的地址
//补充资料<https://blog.csdn.net/example440982/article/details/51712973>
```
## 5.打开并以文本形式编辑
```java
sudo gedit 
//使用gedit以文本形式打开文件
```

