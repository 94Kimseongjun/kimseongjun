//다음 구조체를 라이브러리 qsort를 상용하여 itemname의 오름차순으로 정렬하시오
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _sales
{
	char itemname[20];
	int unitprice;
	int count;
	int amount;
}Sales;

int prd_item(const void* a, const void* b)
{
	return strcmp(((Sales*)a)->itemname, ((Sales*)b)->itemname);
	//return strcmp((char*)a, (char*)b); //운좋게 된 케이스 구조체의 첫번째 변수가 itemname이라서 가능
}

//다음 구조체포인터 배열을 라이브러리 qsort를 상용하여 name의 오름차순으로 정렬하시오
#pragma warning (disable:4996)

typedef struct _node node;

struct _node {
 char name[10];
 struct _node* next;
};
//int gg = 0;
int cmp_node(const void* a, const void* b)
{

	/*
	node *ptA = (node *)a;
	node *ptB = (node *)b;

	if((strcmp(ptA->name, ptB->name)<0)) return 1;
	else return 0;
	
*/

	return strcmp((*(node **)a)->name, (*(node **)b)->name);

}
node* p, * q;

main()
{
	/*	Sales prd[5] = {
		{ "ccc", 10,90,900 },
		{ "aaa", 20,80,1600 },
		{ "ddd", 30,70,2100 },
		{ "eee", 40,60,2400 },
		{ "bbb", 50,50,2500 }
	};
	int dx;

	qsort(prd, 5, sizeof(prd[0]), prd_item);


	for (dx = 0; dx < 5; dx++)
		printf("%s %d %d %d\n", prd[dx].itemname,
			prd[dx].unitprice, prd[dx].count, prd[dx].amount);
	
	*/
 node* k[5];

 p = (node*)malloc(sizeof(node));
 strcpy(p->name, "ccc");
 p->next = NULL;
 q = (node*)malloc(sizeof(node));
 strcpy(q->name, "ddd");
 q->next = NULL;


 k[0] = p;
 k[1] = q;
 k[2] = (node*)malloc(sizeof(node));
 strcpy(k[2]->name, "bbb");
 k[3] = (node*)malloc(sizeof(node));
 strcpy(k[3]->name, "aaa");



 qsort(k, 4, sizeof(node*), cmp_node);

 puts("\n-----");
 printf("%s\n", k[0]->name);
 printf("%s\n", k[1]->name);
 printf("%s\n", k[2]->name);
 printf("%s\n", k[3]->name);

 
}