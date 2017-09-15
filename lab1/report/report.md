# 实验一：写一个hello world小程序
## 实验思路
1. 创建github repository  
2. 创建本地工作目录并从github上clone出项目  
3. 使用vim创建hello.c  
4. 使用gcc编译hello.c  
5. push到github  
6. 学习使用Markdown并撰写实验报告

## 具体过程
1. 打开 [github](http://github.com/)，创建一个名叫[ase](https://github.com/lzjustc/ase)的repository。
2. 在linux的shell中使用su获取root权限，并输入以下命令：
``` shell
cd /home/lzj
mkdir ase
```
创建了工作目录，然后进入目录，从github上clone项目。
```shell
cd ase
git clone git@github.com:lzjustc/ase.git
```
![image](/lab1/report/git clone.png)  
![image](/lab1/report/shell1.png)
3. 使用vim创建hello.c
``` shell
vim hello.c
```
![image](/lab1/report/vim.png)  
4. 使用gcc编译hello.c并执行编译后的程序
``` shell
ls
gcc -o hello hello.c
./ hello
```
![image](/lab1/report/shell2.png)  
5. 把```hello.c```加入版本库并push到我的github上
``` shell
git add hello.c
git commit -m "hello world"
git push
```
![image](/lab1/report/git.png)  
6. 撰写实验报告  
大功告成！

## 遇到的困难及处理过程
我之前是学能源的，听说windows是最烂的开发环境，既然转行到软件工程，又买不起Mac，只好就安装了Ubuntu。以前安装Ubuntu的过程也算艰辛，没想到第一个实验就是在Linux下做的，233    
被大神洗脑说bash不好用，装了fish，没用过bash，也就不明白bash是怎么个不好用。  
不会github怎么能说自己是搞IT的？github从入门到。。最好不要放弃233  
github遇见问题就是SSH-Key了，clone过程遇到以下提示：  
![image](/lab1/report/key denied.png)  
后来在github官网和百度的帮助下，成功解决，如图  
![image](/lab1/report/key2.png)  
之后的问题是写报告，学习了一下markdown语法，遇到的问题也不少。结论：看文档是万能的。  
![image](/lab1/report/github.png)  

## 重现实验的具体操作
删除本地目录之后，重新在github里clone项目，编译运行成功，实验成功！  
![image](/lab1/report/review.png)






