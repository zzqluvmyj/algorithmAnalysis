#include"solution.h"

void simplemaze()
{
	Stack path;
	maze M;
	int a[] = { 1,1,8,8 };
	StackInit(&path);
	mazeinit(&M,a);
	mazeprint(&M);
	solution(&M, M.entry, &path);
	mazeprint(&M);
}

int main()
{
	simplemaze();
	system("pause");
	return 0;
}