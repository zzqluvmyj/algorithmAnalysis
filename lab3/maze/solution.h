#pragma once
#include"maze.h"
void StackInit(Stack* s)//栈的初始化
{
	assert(s);
	s->array = (pos*)malloc(sizeof(pos)*Stack_size);
	s->size = Stack_size;
	s->top = 0;

}

void StackPush(Stack* s, pos x)//入栈
{
	assert(s);
	if (s->top == s->size)//栈已满
	{
		printf("查找失败，不存在合适的路径！");
	}
	else
	{
		s->array[s->top] = x;
		(s->top)++;
	}
}


void StackPop(Stack* s)//出栈
{
	assert(s);
	if (s->top == 0)
	{
		printf("the stack is empty");
	}
	else
	{
		s->top--;
	}
}

int StackEmpty(Stack* s)//判断栈是否为空
{
	if (s->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

pos StackTop(Stack* s)//取栈顶元素
{
	assert(s);


	int num = s->top;
	pos  i = s->array[(--num)];
	return i;

}

void mazeinit(maze *M,int b[])//迷宫初始化
{
	assert(M);
	int a[N][N] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
	};
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			M->mz[i][j] = a[i][j];
			if (a[i][j] == 1) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	M->entry.row = b[0];
	M->entry.col = b[1];
	M->out.row = b[2];
	M->out.col = b[3];
}

void mazeprint(maze *M)
{
	assert(M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d  ", (M->mz)[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int can_stay(pos cur, maze *M)//判断是否能入栈
{
	if (cur.row >= 0 && cur.row < N&&cur.col >= 0 && cur.col < N //坐标合法
		&&M->mz[cur.row][cur.col] != 1 )   //该点不为墙也不为走过的点
	{
		return 1;
	}
	return 0;
}
void assign_pos(pos cur, maze **M)//标记
{
	(*M)->mz[cur.row][cur.col]+=1;//走过就加1
}
int check_exit(pos cur, maze *M)//检查是否到达出口
{
	if ((cur.row == 1) || (cur.row == N - 2) || (cur.col == 1) || (cur.col == N - 2))
	{
		if ((cur.row == M->out.row) && (cur.col == M->out.col)) {
			return 1;
		}
	}
	return 0;
}

void print_stack(Stack *s)
{
	printf("找到出口！\n\n");
	printf("栈顶\n");
	for (size_t i = 0; i < s->top; i++)
	{
		printf("[%d %d]\n", s->array[i].row, s->array[i].col);
	}
	printf("栈底\n\n");
	printf("路径长度为%u\n", s->top);
}
void solution(maze *M, pos cur, Stack *s)
{

	assert(M);
	//2.判定当前点坐标是否可以走。（坐标合法且不为0）

	if (can_stay(cur, M))
	{
		//3.如果合法则将当前点标记成走过的并入栈
		//（维护一个栈可以记录走过的路径，栈的长度就是路径的长度）
		assign_pos(cur, &M);
		StackPush(s, cur);
	}
	else
	{
		return;
	}
	if (check_exit(cur, M))
	{
		print_stack(s);
		return;
	}
	//4.判断当前点是否是出口，是出口就return（该迷宫不存在别的出口），
	//如果不是出口，以顺时针的方向（上，右，下，左）探测临界点是否可以走（不为0且不为已经走过的点），
	//并以递归形式重复步骤2-4.

	//up
	pos up = cur;
	up.row -= 1;
	solution(M, up, s);

	//right
	pos right = cur;
	right.col += 1;
	solution(M, right, s);

	//down
	pos down = cur;
	down.row += 1;
	solution(M, down, s);

	//left
	pos left = cur;
	left.col -= 1;
	solution(M, left, s);


	//5.当一个点的4个方向都已经探测过，就返回上一层栈帧。
	StackPop(s);
	M->mz[cur.row][cur.col] = 0;//回溯
	return;
}
