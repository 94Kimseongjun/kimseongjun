#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

// �ڽ��� ���ּҸ� �Է� �޾Ƽ� 
// ���ּ� ���� ��ŭ heap�� �Ҵ�ް�
//�ְ� ����غ���

int main()
{
	/*
	int a[5];
	int* p;
	p = a;
	*p = 10;

	int* k;
	k = (int *)malloc(sizeof(int)*5);
	*k = 10;
	*/

	/*
	char address[100];
	//scanf("%[^\n]", address);
	gets_s(address);
	int len = strlen(address);

	char* p;
	p = (char *)malloc(sizeof(char) * len+1); //������ NULL ���� ����
	//	p = address;
	strcpy(p, address);
	printf("%s", p);

	free(p);

	return 0;
	*/


	/*

	char** p;
	p = (char **)malloc(sizeof(char*) * 1);
	*p = (char *)malloc(sizeof(char) * 3);
	**p = 'A';
	//printf("%d %d %d", p, *p, **p);
	printf("%c",**p);


	free(*p);
	free(p);
	*/


	/*
	
	
	char str[100];
	char** p;
	int num, i = 0;
	printf("���ϴ� ������ ������ �Է��ϼ���:");

	scanf("%d", &num);

	p = (char **)malloc(sizeof(char*)*num);

	for (i = 0; i < num; i++)
	{

		printf("%d ��° ������?", i + 1);
		scanf("%s", str);
		*p = (char *)malloc(sizeof(char)*strlen(str));
		strcpy(*p, str);
		printf("%s\n", *p);
		**p++;
	}



	for (i = 0; i < num; i++)
	{
		printf("%s\n", *p + i);
	}

	for (i = 0; i < num; i++)
	{
		free(*p + i);
	}
	free(p);
	
	*/
	
	char **p;
	int cnt,i;
	char buf[100];

	printf("���ϴ� ������ ����?");
	scanf("%d", &cnt);
	getchar();

	p = (char**)malloc(sizeof(char*) * cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("%d��° ������?", i + 1);
		gets_s(buf);
		*(p+i) = (char *)malloc(sizeof(char)*strlen(buf) + 1);
		strcpy(*(p+i), buf);
	}

	for (i = 0; i < cnt; i++)
	{
		puts(*(p+i));
	}

	for (i = 0; i < cnt; i++)
	{
		free(*(p + i));
	}

	free(p);

}
