
# 基本需求

增加一个nuc指定模板的功能

# 基本假设

使用现有的poc 以cve编号作为索引

# 需要的修改

表autopenetration_task_main_config根据main_task_id找到对应的主任务中有plugin_choose这个字段 值为3表示使用自定义poc
使用poc_conf字段存放需要使用的poc cve 每个cve用逗号隔开

# 遇到的问题

## 编译阶段

编译找不到动态库 makefile按标准名称查找 但是动态库可能不是标准名称 需要添加软连接
提示undefined 可能是类中的静态成员未在类外初始化 也可能是登录root是使用的su 而不是su - 导致环境变量出现问题

## 数据库

main_task_id 有的数据表是varchar（32）有的是bigint（20） （autopenetration_ipserver_result）

## 权限相关

虽然makefile有更改生成的文件为可执行文件 但是移动后权限可能发生改变
python_sftp 可能无法写入远程文件夹 因为没有远程文件夹的访问权限
