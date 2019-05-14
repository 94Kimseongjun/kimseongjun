#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

struct engine {
	int piston;
	int fan;
	int pipe;
};

struct car {
	struct engine *sedan, *sports;
};

void hyundai(struct car *man)
{
	struct engine *p;
	p = man->sedan;

	/*
	man->sedan->piston = 50;
	man->sedan->fan = 30;
	man->sedan->pipe = 20;
	*/

	p->piston = 50;
	p->fan = 30;
	p->pipe = 20;
}

void main()
{
	struct car hi;
	hi.sedan = (struct engine *)malloc(sizeof(struct engine));
	hyundai(&hi);
	printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan, hi.sedan->pipe);
}