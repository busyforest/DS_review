# Makefile

# 编译器
CC = gcc
CFLAGS = -Wall -g

# 公共库
LIBSRC = stack.c
LIBOBJ = $(LIBSRC:.c=.o)

# 找到当前目录下所有 .c 文件，排除 stack.c
SRCS = $(filter-out $(LIBSRC), $(wildcard *.c))

# 对应的可执行文件（去掉后缀）
PROGS = $(SRCS:.c=)

all: $(PROGS)

# 规则：每个可执行文件依赖于对应的 .c 和 stack.o
$(PROGS): %: %.c $(LIBOBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

# 生成 stack.o
$(LIBOBJ): $(LIBSRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGS) $(LIBOBJ) *.o