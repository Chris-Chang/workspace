# 解决sublime在编译出错或警告时额外显示系统path的问题
最近在配置sublime text3的C语言环境，但是发现每次运行程序时一旦程序出错或者出现警告。

折腾了半天，解决方案如下:

1. 找到sublime text3安装目录，在目录下找到`Packages`里的`Default.sublime-package`, 比如`Sublime Text 3\Packages\Default.sublime-package`

2. 解压`Default.sublime-package`包(改下后缀名为rar或zip即可解压),提取其中的exec.py文件
3. 将`exec.py`文件放到`C:\Users\{UserName}\AppData\Roaming\Sublime Text 3\Packages`路径下
4. 修改`exec.py`文件，将文件的`self.append_string(proc,self.debug_text)`注释掉
5. 重启Sublime Text
