#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>
//要定义的有：
//一个结构体为结构体pos，用于记录迷宫每个店的横纵坐标
//两个栈path和shortpath，记录通路的最短距离,栈内元素序列即是最短
//迷宫（迷宫地图，入口点）
#define N 10
#define Stack_size 100
typedef struct pos            //迷宫内每个点的坐标
{
	int row;
	int col;
}pos;


typedef struct Stack         //存放节点信息的栈
{
	pos* array;        //数组指针
	size_t  top;            //栈顶 
	size_t  size;            //最大容量
}Stack;

typedef struct maze          //迷宫
{
	int mz[N][N];
	pos entry;
	pos out;//入口点
}maze;

