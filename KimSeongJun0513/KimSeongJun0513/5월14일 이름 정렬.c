
//���� �̸��� 2���� �迭�� �ְ� ���� ������ �̿��Ͽ� ���� �Ͻÿ�
//

/*
�ּ�ó�� : Ctr + K + C

�ּ����� : Ctrl + K + U
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
	char name[][7] = { "������","�̰���","�輺��","���¿�","���μ�","�迵��",
	"������","�念��","�ڰ��","������","�����","�����",
	"������","������","�����","�輼��","���λ�" };

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