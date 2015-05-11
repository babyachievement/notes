安装后要做的配置
========================


#1.给浏览器安装ve pandoc的安装

http://www.cnblogs.com/liuyangnuts/archive/2013/04/23/3038354.html 让pandoc输出pdf时支持中文

http://zhengmingpei.github.io/2015/02/13/pandoc/ Pandoc的使用

http://zhouyichu.com/misc/Pandoc.html    神器Pandoc的安装与使用



##2.安装中文字体
安装中文字体

将C:/windows/fonts下你喜欢的字体拷贝到/usr/share/fonts/windows目录下（需首先创建windows目录）

[c-sharp] view plaincopy
sudo mkdir /usr/share/fonts/windows  
然后将对应字体拷贝到该目录下（需使用管理员权限sudo执行）

执行以下几条命令更新系统字体缓存：

[c-sharp] view plaincopy
cd /usr/share/fonts/vista/  
sudo mkfontscale  
sudo mkfontdir  
sudo fc-cache -fv  

##3.写作
http://www.yangzhiping.com/tech/pandoc.html  Markdown写作进阶：Pandoc入门浅谈
