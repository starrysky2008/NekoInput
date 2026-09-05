# NekoInput
### What's this
这是一个为fcitx5开发的插件，它的作用只有一个：给你的每句话后加一个喵  
程序会在你输入各种标点符号时在符号前插入一个“喵”  
就这么简单  

### How to use
首先克隆本仓库，然后运行以下命令
```shell
cmake -S . -B build
cmake --build build
sudo cmake --install build
```
然后重启你的fcitx
```shell
fcitx5-remote -r
```
正常情况下插件这时候就已经开始运行了  

### THEN HOW CAN I STOP THIS CREEPY ADDON
由于我很懒，我没有做任何配置项，但是我预留了一个魔法词汇  
如果你想暂时禁用这个插件，可以输入“禁用喵喵喵”（一次性打完引号内的内容，然后按空格）  
然后你应该就不会继续喵喵喵了  
想重新启用可以输入“启用喵喵喵”  
要永久禁用的话可以直接删掉你fcitx插件目录下的libNekoInput.so（一般情况下位于/usr/lib/fcitx5喵）  
（没错这就是这个插件的效果喵）