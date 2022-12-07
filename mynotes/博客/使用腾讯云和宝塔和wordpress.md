# 网站地址 <https://dlclass.xyz>  
# 采用腾讯云搭建网站 
视频教程    
<https://www.bilibili.com/video/BV1rU4y1J785/?spm_id_from=333.337.search-card.all.click&vd_source=0ad4afe3558555f705183a5f8094b675> 

文字教程    
 <https://ycirving.com/posts/birthday03/>   
## 1.云服务器选择    
选择腾讯云轻量应用服务器 2核2g  
操作系统选择cent os 7.6  

## 2.辅助软件    
使用宝塔进行管理    
<https://www.bt.cn/new/download.html>  
使用wordpress进行搭建   

使用xshell在本地进行管理    
<https://www.xshell.com/zh/xshell/>    
*使用免费版即可*    

## 3.初步建站    
在服务器上安装宝塔（需在腾讯云防火墙中开放宝塔所用端口）    
在宝塔应用软件中使用word press建站   
建议后面对访问端口进行修改  

## 4.word press相关  
word press提示更新php版本    
可从宝塔软件商城中跟新（记得在页面设置中切换php版本） 

## 5.域名和dns解析   
从腾讯云购买域名 使用腾讯云的dnsport服务提供dns解析 

### 1.443端口无法连通    
在防火墙中开通即可 (网页出现404也可能是由于没有ssl证书)   

### 2.申请ssl证书并部署  
可在腾讯云申请免费ssl证书 并使用宝塔云进行部署  

### 3.顺序问题   
在没有域名前就利用wordpress一键生成网站 会导致使用域名访问时出现问题    
*应该是文件路径的问题*  
目前采取重新一键生成的方式解决  

## 6.使用xshell连接服务器    
*教程*   
<https://blog.csdn.net/xww1977/article/details/118088867>    
建议采用ssh密钥连接 安全性更高  
公钥存储在实例上（可在腾讯云上直接创建密钥对 私钥会自动下载到本地）  
将本地的私钥导入到xshell即可        
## 7.备案
腾讯云网站上可快捷备案 注意备案期间要关站（删除dns解析记录）