#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)


/*

=====  M E N U  =====
1. ������Ȳ ���
2. ������Ȳ ��������
3. ��ǰ ã��
4. ��ǰ ����
5. ������Ȳ �迭
6. ����
7. ����
=====================
�޴��� �����Ͻÿ�  :1



============================================
�Ｚ���� �¶���  ���� ��Ȳ
============================================
��ǰ��          �ܰ�    ����       �ݾ�
--------------------------------------------
1             DVD          65      12        780
2           LEDTV         260     221      57460
3        ������A7        1022    1654    1690388
4        ������s7         190    2034     386460
5      ����û����         191    3045     581595
6      ��ġ�����         456      30      13680
7         ��Ʈ��5         798     875     698250
8      �巳��Ź��         863     396     341748
9    ������������         122     324      39528
10    ��Ƽ��������       1653    1980    3272940
11  ���ĵ�����ǳ��         46     809      37214
12    �����������       1187     303     359661
13      �Ϲݼ�Ź��        489     421     205869
14    �Ϲݿ�������        173      26       4498
15    �Ϲ��������        338      78      26364
16        �������        458      77      35266
17      ���ڷ�����         88      55       4840
18            ����        920     123     113160
19      ����û�ұ�        183     456      83448
--------------------------------------------
���� �հ�           7953149
============================================

=====  M E N U  =====
1. ������Ȳ ���
2. ������Ȳ ��������
3. ��ǰ ã��
4. ��ǰ ����
5. ������Ȳ �迭
6. ����
7. ����
=====================
�޴��� �����Ͻÿ�  : 2



================
���Ϸγ������� �ϼ�
================

================

=====  M E N U  =====
1. ������Ȳ ���
2. ������Ȳ ��������
3. ��ǰ ã��
4. ��ǰ ����
5. ������Ȳ �迭
6. ����
7. ����
=====================
�޴��� �����Ͻÿ�  : 3


�˻���ǰ �Է� : DVD
============================================
��ǰ��          �ܰ�    ����       �ݾ�
--------------------------------------------
DVD    65      12        780
============================================

=====  M E N U  =====
1. ������Ȳ ���
2. ������Ȳ ��������
3. ��ǰ ã��
4. ��ǰ ����
5. ������Ȳ �迭
6. ����
7. ����
=====================
�޴��� �����Ͻÿ�  : 6

���Ĺ���� �����Ͻÿ�
(��ǰ��=0, �ݾ�=1, �Ǹŷ�=2, �Ǹűݾ�=3) : 1
���Ĺ���� �����Ͻÿ�
(��������=0, ��������=1) : 1

============================================
�Ｚ���� �¶��� ���� ��Ȳ
============================================
��ǰ��  �ܰ�    ����       �ݾ�
--------------------------------------------
��Ƽ��������  1653    1980    3272940
�����������  1187     303     359661
������A7  1022    1654    1690388
����   920     123     113160
�巳��Ź��   863     396     341748
��Ʈ��5   798     875     698250
�Ϲݼ�Ź��   489     421     205869
�������   458      77      35266
��ġ�����   456      30      13680
�Ϲ��������   338      78      26364
LEDTV   260     221      57460
����û����   191    3045     581595
������s7   190    2034     386460
����û�ұ�   183     456      83448
�Ϲݿ�������   173      26       4498
������������   122     324      39528
���ڷ�����    88      55       4840
DVD    65      12        780
���ĵ�����ǳ��    46     809      37214
--------------------------------------------
���� �հ�           7953149
============================================

*/

typedef struct _items items;

struct _items
{
	//��ǰ��          �ܰ�    ����       �ݾ�
	char item_name[20];
	int price; //����
	int num; //�ȸ� ����

	struct _itmes* next;

};
items* head, *tail;

void init_list(void)
{
	head = (items*)malloc(sizeof(items)); //���� ���
	tail = (items*)malloc(sizeof(items)); // ������ ���
	head->next = tail;
	tail->next = tail;
}


void print_List(void)
{
	items *wk;
	wk = head->next;
	while (wk != tail)
	{
		printf("��ǰ��:%s �ܰ�:%d �ȸ�����:%d\n", wk->item_name, wk->price, wk->num);
		wk = wk->next;
	}
	printf("\n---------------------------------------------------------------------------------------------------\n");

}

items* find_List(char *data)
{
	items *wk;
	wk = head->next;
	int cnt = 1;

	/*
	while (wk != tail)
	{
	if (wk->key == data)
	{
	printf("%d�� ã�ҽ��ϴ�.\n", data);
	printf("%d�� %d��° ���\n", data,cnt);
	break;
	}
	wk = wk->next;
	cnt++;
	}

	*/

	while (strcmp(wk->item_name, data) && wk != tail)
	{
		wk = wk->next;
	}

	if (wk != tail)
	{
		//puts("����");
	}
	else
	{
		puts("����");
	}
	return wk;
}



void print_all()
{
	items *wk;
	int i = 1;
	wk = head->next;

	printf("============================================\n�Ｚ���� �¶���  ���� ��Ȳ\n== == == == == == == == == == == == == == == == == == == == == ==\n");
	printf("��ȣ\t��ǰ��\t�ܰ�\t�ǸŰ���\t�ݾ�\n");
	printf("-----------------------------------------------------\n");

	while (wk != tail)
	{
		printf("%d\t%s\t%d\t%d\t%d\n", i, wk->item_name, wk->price, wk->num, wk->num*wk->price);
		wk = wk->next;
		i++;
	}
}

void print_all_k(items **k)
{
	int i = 0;
	for (i = 0; i < 19; i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n", i + 1, k[i]->item_name, k[i]->price, k[i]->num, (k[i]->num) * (k[i]->price));

	}
}

void arrcopy(items **k)
{
	items *wk;
	int i = 0;
	wk = head->next;
	while (wk != tail)
	{
		k[i] = wk;
		wk = wk->next;
		printf("%d\t%s\t%d\t%d\t%d\n", i + 1, k[i]->item_name, k[i]->price, k[i]->num, (k[i]->num) * (k[i]->price));
		i++;
	}


}

int sort_item_name(const void* a, const void* b)
{
	return strcmp((*(items **)a)->item_name, (*(items **)b)->item_name);
}

int sort_item_name_2(const void* a, const void* b)
{
	return strcmp((*(items **)b)->item_name, (*(items **)a)->item_name);
}

int sort_price(const void* a, const void* b)
{
	if (((*(items **)b)->price) < ((*(items **)a)->price)) return -1;
	if (((*(items **)b)->price) > ((*(items **)a)->price)) return 1;
	else return 0;
}



/*
if ((*(double*)a < *(double*)b) )
{
return -1;
}
if ((*(double*)a > *(double*)b))
{
return 1;
}
else return 0;
//return (*(double*)a - *(double*)b);

*/

int main()
{
	items* k[20];
	items i;
	items * temp;
	FILE *fp;

	init_list();

	fp = fopen("item.txt", "r");

	while (!feof(fp))
	{
		items *nw = (items*)malloc(sizeof(items));
		nw->next = head->next;
		head->next = nw;
		fscanf(fp, "%s %d", &i.item_name, &i.price);
		strcpy(nw->item_name, i.item_name);
		nw->price = i.price;
		nw->num = 0;

	}
	fclose(fp);

	//print_List();

	fp = fopen("sales.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s %d", &i.item_name, &i.num);
		find_List(i.item_name)->num = i.num;

	}

	fclose(fp);

	//print_List();


	arrcopy(k);



	int q = 0;
	int q2 = 0;
	char search[20];
	while (1) {
		printf("=====  M E N U  =====\n");
		printf("1.������Ȳ ���\n");
		printf("2.������Ȳ ��������\n");
		printf("3.��ǰ ã��\n");
		printf("4.��ǰ ����\n");
		printf("5.������Ȳ �迭\n");
		printf("6.����\n");
		printf("7.����\n");
		scanf("%d", &q);
		switch (q)
		{
		case 1: print_all(); break;
		case 3:

			printf("�˻� ��ǰ �Է�:");
			scanf("%s", search);
			temp = find_List(search);
			printf("============================================\n�Ｚ���� �¶���  ���� ��Ȳ\n== == == == == == == == == == == == == == == == == == == == == ==\n");
			printf("��ǰ��\t�ܰ�\t�ǸŰ���\t�ݾ�\n");
			printf("-----------------------------------------------------\n");
			printf("%s\t%d\t%d\t%d\n", temp->item_name, temp->price, temp->num, temp->num*temp->price);

			break;

		case 6:

			printf("���ı����� �����Ͻÿ�\n");
			printf("(��ǰ��=0, �ܰ�=1, �ǸŰ���=2, �Ǹűݾ�=3):");
			scanf("%d", &q);

			
			printf("���Ĺ���� �����Ͻÿ�.\n(��������=0, ��������=1):");
			scanf("%d", &q2);

			switch (q2)
			{
			case 0: if (q == 0)
			{
				qsort(k, 19, sizeof(items*), sort_item_name);  print_all_k(k);
			}
					if (q == 1)
					{
						qsort(k, 19, sizeof(items*), sort_price);  print_all_k(k);
					}

					break;
			case 1:if (q == 0)
			{
				qsort(k, 19, sizeof(items*), sort_item_name_2);  print_all_k(k);
			}
				   break;
			default:
				break;
			}


			break;
		case 7: return 0;
		default:
			break;
		}
	}
}