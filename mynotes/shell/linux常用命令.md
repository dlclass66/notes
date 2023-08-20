
# 常用工具

## awk

### 基本命令格式

awk 动作 文件名
-f 表示分割符 "[]" []里面放置过滤分割符号

## ps

ps -ef查看所有进程 一般要搜索特定名称的进程 ps -ef | grep mysql
ps -aux --sort=-pcpu | head -11 按cpu使用率排序 显示前10 -u参数可以指定用户
