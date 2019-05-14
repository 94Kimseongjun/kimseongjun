
//다음 이름을 2차원 배열에 넣고 다음 정렬을 이용하여 정렬 하시오
//

/*
주석처리 : Ctr + K + C

주석해제 : Ctrl + K + U
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)


void isort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		j = i;
		while (a[j - 1] > t && j > 0)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}


void stringsort(char a[][7], int n)
{
	int i, j;
	char t[7];
	for (i = 1; i < n; i++)
	{
	
		strcpy(t, a[i]);

		j = i;
		while (strcmp(a[j-1],t)>0 && j>0)
		{
			strcpy(a[j], a[j - 1]);
			j--;
		}
	
		strcpy(a[j], t);
	}
}



int main()
{
	int i;
	char name[][7] = { "정영진","이경진","김성준","김태원","이인석","김영완",
	"김종혁","장영수","박경수","김태형","김건희","박희웅",
	"김현우","이혜주","조용민","김세한","장인상" };

	//int arr[] = { 3,4,1,5,2 };
	//isort(arr, 5);

	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d", arr[i]);
	//}


	stringsort(name,17);

	for (i = 0; i < 17; i++)
	{
		printf("%s\n", name[i]);
	}



}