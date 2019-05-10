# CSAPP

## 编译和链接

- 编译： `gcc -c csapp.c`

- 编译： `gcc -c hello.c`

- 链接： `gcc -o main csapp.o hello.o -lpthread`，生成可执行文件`main`，运行main文件即可

做第8章实验，依赖`lpthread`。