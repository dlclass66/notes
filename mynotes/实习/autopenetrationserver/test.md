
# 对项目进行基本测试

# 环境配置

## 编译服务器

地址126

## 数据库

地址 53：3306 数据库名 dl_test

## nacos

地址 43:8848/nacos 用户名 nacos 命名空间 dl_test

## 任务下发程序运行位置

127 centos

## 靶机

165：45389 windows(无法使用docker)更换
192 centos 安装gnome桌面环境

## 扫描器

127：22

## 可以改进的地方

1. 环境变量读取的地方也可能出错 可以增加异常捕捉
2. taskdir可能不存在 可以先判断是否存在 不存在就创建
3. 有时候会文件会没有执行权限 可以在makefile中更改生成文件的权限
