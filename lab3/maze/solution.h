#pragma once
#include"maze.h"
void StackInit(Stack* s)//ջ�ĳ�ʼ��
{
	assert(s);
	s->array = (pos*)malloc(sizeof(pos)*Stack_size);
	s->size = Stack_size;
	s->top = 0;

}

void StackPush(Stack* s, pos x)//��ջ
{
	assert(s);
	if (s->top == s->size)//ջ����
	{
		printf("����ʧ�ܣ������ں��ʵ�·����");
	}
	else
	{
		s->array[s->top] = x;
		(s->top)++;
	}
}


void StackPop(Stack* s)//��ջ
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

int StackEmpty(Stack* s)//�ж�ջ�Ƿ�Ϊ��
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

pos StackTop(Stack* s)//ȡջ��Ԫ��
{
	assert(s);


	int num = s->top;
	pos  i = s->array[(--num)];
	return i;

}

void mazeinit(maze *M,int b[])//�Թ���ʼ��
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
int can_stay(pos cur, maze *M)//�ж��Ƿ�����ջ
{
	if (cur.row >= 0 && cur.row < N&&cur.col >= 0 && cur.col < N //����Ϸ�
		&&M->mz[cur.row][cur.col] != 1 )   //�õ㲻ΪǽҲ��Ϊ�߹��ĵ�
	{
		return 1;
	}
	return 0;
}
void assign_pos(pos cur, maze **M)//���
{
	(*M)->mz[cur.row][cur.col]+=1;//�߹��ͼ�1
}
int check_exit(pos cur, maze *M)//����Ƿ񵽴����
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
	printf("�ҵ����ڣ�\n\n");
	printf("ջ��\n");
	for (size_t i = 0; i < s->top; i++)
	{
		printf("[%d %d]\n", s->array[i].row, s->array[i].col);
	}
	printf("ջ��\n\n");
	printf("·������Ϊ%u\n", s->top);
}
void solution(maze *M, pos cur, Stack *s)
{

	assert(M);
	//2.�ж���ǰ�������Ƿ�����ߡ�������Ϸ��Ҳ�Ϊ0��

	if (can_stay(cur, M))
	{
		//3.����Ϸ��򽫵�ǰ���ǳ��߹��Ĳ���ջ
		//��ά��һ��ջ���Լ�¼�߹���·����ջ�ĳ��Ⱦ���·���ĳ��ȣ�
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
	//4.�жϵ�ǰ���Ƿ��ǳ��ڣ��ǳ��ھ�return�����Թ������ڱ�ĳ��ڣ���
	//������ǳ��ڣ���˳ʱ��ķ����ϣ��ң��£���̽���ٽ���Ƿ�����ߣ���Ϊ0�Ҳ�Ϊ�Ѿ��߹��ĵ㣩��
	//���Եݹ���ʽ�ظ�����2-4.

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


	//5.��һ�����4�������Ѿ�̽������ͷ�����һ��ջ֡��
	StackPop(s);
	M->mz[cur.row][cur.col] = 0;//����
	return;
}
