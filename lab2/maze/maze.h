#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>
//Ҫ������У�
//һ���ṹ��Ϊ�ṹ��pos�����ڼ�¼�Թ�ÿ����ĺ�������
//����ջpath��shortpath����¼ͨ·����̾���,ջ��Ԫ�����м������
//�Թ����Թ���ͼ����ڵ㣩
#define N 10
#define Stack_size 100
typedef struct pos            //�Թ���ÿ���������
{
	int row;
	int col;
}pos;


typedef struct Stack         //��Žڵ���Ϣ��ջ
{
	pos* array;        //����ָ��
	size_t  top;            //ջ�� 
	size_t  size;            //�������
}Stack;

typedef struct maze          //�Թ�
{
	int mz[N][N];
	pos entry;
	pos out;//��ڵ�
}maze;

