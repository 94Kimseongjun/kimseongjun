#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

/*

�ڷᱸ��

1. list - ������ �ִ� �ڷᱸ��, array,linked list

	1-0. Sorting(����), ����,����,����(��������, ��),��,����,Ʈ������,�������,�����ȯ����
	c:algorithm(qsort(), bsearch())
	1-1. circular list, double list(������ Ŀ��),



2. stack - LIFO

3. queue - FIFO

4. tree - ����Ʈ��, -> ��������Ʈ��, -> �ڵ� AVL, red-black(������)
	4-1. Ž��
	4-2. hash-Tree�� �籸��

5. graph - �ּҺ�뽺�д�Ʈ��, �ִܰŸ��˰���-> A-star




*/


//�� ���� ���̳��

typedef struct _list List;

struct _list
{
	int key;
	struct _list* next; //�ڱ����� ����ü
};

List* head, *tail; //�� ��� �̸�

void init_list(void)
{
	head = (List*)malloc(sizeof(List)); //���� ���
	tail = (List*)malloc(sizeof(List)); // ������ ���
	head->next = tail;
	tail->next = tail;
}

void insert_List(int data) // �� �տ� ����
{
	List *nw = (List*)malloc(sizeof(List));
	nw->key = data;
	nw->next = head->next;
	head->next = nw;
}

void insert_List_tail(int data) // �� �ڿ� ����
{
	List *wk;
	wk = head->next;
	while (wk->next != tail)
	{
		wk = wk->next;
	}

	List *nw = (List*)malloc(sizeof(List));
	nw->key = data;
	nw->next = tail;
	wk->next = nw;

}

void print_List(void)
{
	List *wk;
	wk = head->next;
	while (wk != tail)
	{
		printf("%d\t", wk->key);
		wk = wk->next;
	}
	printf("\n---------------------------------------------------------------------------------------------------\n");

}

List* find_List(int data)
{
	List *wk;
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

	while (wk->key != data && wk != tail)
	{
		wk = wk->next;
	}

	if (wk != tail)
	{
		puts("����");
	}
	else
	{
		puts("����");
	}
	return wk;
}

void delete_List(int data)
{

	/*

	//���� § �ڵ�

	List *wk;
	List *temp;
	wk = head->next;
	temp = head; //ù��°�� ���ﶧ
	while (wk->key != data && wk != tail)
	{
		temp = wk;
		wk = wk->next;
	}
	temp->next = wk->next;
	wk->next = NULL;
	free(wk);

	*/

	//����� �ڵ�

	List *wk;
	wk = head;
	while (wk->next->key != data && wk->next != tail)
	{
		wk = wk->next;
	}

	if (wk->next != tail)// �߰��� ã��
	{
		List* kill = wk->next;
		wk->next = wk->next->next;
		free(kill);
	}
	else
	{
		printf("�����Ϸ��� �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}

void move_to_front(int data) // ��带 ã�Ƽ� �� ������ �ű��
{
	List *wk;
	List *temp;
	wk = head;
	int cnt = 0;


	while (wk->next->key != data && wk->next != tail)
	{
		wk = wk->next;
		cnt++;
	}

	if (cnt == 0)
	{
		printf("�̹� ù ��° ����Դϴ�.\n");
		return 0;
	}

	if (wk->next != tail && cnt!=0)// �߰��� ã��
	{
		temp = wk->next;
		wk->next = temp->next;
		temp->next = head->next;
		head->next = temp;
		printf("%d��(��) �� ������ �ű�ϴ�.\n\n", data);
	}
	else
	{
		printf("������ ã�� ����.\n\n");
	}

}

void swap(int data) // �տ����� ����
{
	List *wk;
	List *temp;
	List *temp2;
	int cnt = 0;
	wk = head;

	while (wk->next->key != data && wk->next != tail)
	{
		temp2 = wk;
		wk = wk->next;
		cnt++;
	}

	if (wk->next != tail && cnt != 0)// �߰��� ã��
	{
		temp = wk->next;
		wk->next = temp->next;
		temp->next = wk;
		temp2->next = temp;
	}
	else
	{
		printf("������ ã�� ����.\n\n");
		return 0;
	}

	if (cnt == 0)
	{
		printf("ù ��° ���� ������ �� �����ϴ�.\n");
	}
	else
	{
		printf("%d��(��) �� ���� �����մϴ�.\n\n", data);
	}
}

//Frequency Counter �������� ī��Ʈ ���� ã�� ������ŭ ������


void ordered_insert(int data)
{
	List *pre, *cmp;
	pre = head;
	cmp = head->next;

	while (cmp->key <= data && cmp!=tail)

	{
		pre = pre->next;
		cmp = cmp->next;
	}

	List *nw = (List*)malloc(sizeof(List));

	nw->key = data;
	pre->next = nw;
	nw->next = cmp;

}

void delete_all_List()
{
	/*
	List *wk;
	wk = head->next;

	while (wk != tail)
	{
		List* kill = wk;
		wk= wk->next;
		free(kill);
	}
	head->next = tail;
	*/

	List * kill;
	kill = head->next;
	List * help;
	while (kill != tail)
	{
		help = kill;
		kill = kill->next;
		free(help);
	}
	head->next = tail;

}

int main()
{
	//��� �ڷᱸ���� �ݵ�� �ʱ�ȭ�� �ʿ�

	init_list(); //��հ� ������ �����

	int i = 0;

	for (i = 0; i < 10; i++)
	{
		insert_List(i + 1); //ù ��° ���
	}

	print_List();
	puts("");
	//find_List(7); //5�� ã�� find �Լ� �����ϱ� ���ϰ��� ã�� ����� �ּ� , �� ã�Ҵٸ� tail�� �ּҸ� ����

	//delete_List(30);

	for (i = 0; i < 10; i++)
	{
		move_to_front(i+1);
		print_List();
	}

	puts("");

	for (i = 0; i < 10; i++)
	{
		printf("���� �� "); print_List();
		swap(i + 1);
		printf("���� �� "); print_List();
		printf("\n\n");
	}

	move_to_front(5);
	print_List();

	move_to_front(1);
	print_List();

	move_to_front(8);
	print_List();

	move_to_front(10);
	print_List();

	swap(11);
	for (i = 0; i < 10; i++)
	{
		delete_List(i + 1);
	}
	printf("���� ��\n\n");
	print_List();
	printf("---------------------------------------------------------------\n\n");
	ordered_insert(1);
	ordered_insert(6);
	ordered_insert(10);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(4);
	ordered_insert(2);
	ordered_insert(1);

	print_List();

	delete_all_List();
	printf("all ���� ��\n\n");
	print_List();

	ordered_insert(1);
	ordered_insert(6);
	ordered_insert(10);
	ordered_insert(8);
	print_List();

}