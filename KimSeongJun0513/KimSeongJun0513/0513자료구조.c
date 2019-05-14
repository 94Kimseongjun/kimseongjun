#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

/*

자료구조

1. list - 순서가 있는 자료구조, array,linked list

	1-0. Sorting(정렬), 버블,선택,삽입(간접삽입, 쉘),퀵,병합,트리정렬,기수정렬,기수교환정렬
	c:algorithm(qsort(), bsearch())
	1-1. circular list, double list(리눅스 커널),



2. stack - LIFO

3. queue - FIFO

4. tree - 이진트리, -> 균형이진트리, -> 자동 AVL, red-black(리눅스)
	4-1. 탐색
	4-2. hash-Tree의 재구성

5. graph - 최소비용스패닝트리, 최단거리알고리즘-> A-star




*/


//양 끝에 더미노드

typedef struct _list List;

struct _list
{
	int key;
	struct _list* next; //자기참조 구조체
};

List* head, *tail; //각 기둥 이름

void init_list(void)
{
	head = (List*)malloc(sizeof(List)); //왼쪽 기둥
	tail = (List*)malloc(sizeof(List)); // 오른쪽 기둥
	head->next = tail;
	tail->next = tail;
}

void insert_List(int data) // 맨 앞에 삽입
{
	List *nw = (List*)malloc(sizeof(List));
	nw->key = data;
	nw->next = head->next;
	head->next = nw;
}

void insert_List_tail(int data) // 맨 뒤에 삽입
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
			printf("%d를 찾았습니다.\n", data);
			printf("%d는 %d번째 노드\n", data,cnt);
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
		puts("성공");
	}
	else
	{
		puts("실패");
	}
	return wk;
}

void delete_List(int data)
{

	/*

	//내가 짠 코드

	List *wk;
	List *temp;
	wk = head->next;
	temp = head; //첫번째꺼 지울때
	while (wk->key != data && wk != tail)
	{
		temp = wk;
		wk = wk->next;
	}
	temp->next = wk->next;
	wk->next = NULL;
	free(wk);

	*/

	//강사님 코드

	List *wk;
	wk = head;
	while (wk->next->key != data && wk->next != tail)
	{
		wk = wk->next;
	}

	if (wk->next != tail)// 중간에 찾음
	{
		List* kill = wk->next;
		wk->next = wk->next->next;
		free(kill);
	}
	else
	{
		printf("삭제하려는 데이터가 존재하지 않습니다.\n");
	}
}

void move_to_front(int data) // 노드를 찾아서 맨 앞으로 옮기기
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
		printf("이미 첫 번째 노드입니다.\n");
		return 0;
	}

	if (wk->next != tail && cnt!=0)// 중간에 찾음
	{
		temp = wk->next;
		wk->next = temp->next;
		temp->next = head->next;
		head->next = temp;
		printf("%d을(를) 맨 앞으로 옮깁니다.\n\n", data);
	}
	else
	{
		printf("데이터 찾기 실패.\n\n");
	}

}

void swap(int data) // 앞에꺼랑 스왑
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

	if (wk->next != tail && cnt != 0)// 중간에 찾음
	{
		temp = wk->next;
		wk->next = temp->next;
		temp->next = wk;
		temp2->next = temp;
	}
	else
	{
		printf("데이터 찾기 실패.\n\n");
		return 0;
	}

	if (cnt == 0)
	{
		printf("첫 번째 노드는 스왑할 수 없습니다.\n");
	}
	else
	{
		printf("%d을(를) 앞 노드와 스왑합니다.\n\n", data);
	}
}

//Frequency Counter 프리퀀시 카운트 많이 찾은 개수만큼 앞으로


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
	//모든 자료구조는 반드시 초기화가 필요

	init_list(); //기둥과 빨래줄 만들기

	int i = 0;

	for (i = 0; i < 10; i++)
	{
		insert_List(i + 1); //첫 번째 노드
	}

	print_List();
	puts("");
	//find_List(7); //5를 찾는 find 함수 구현하기 리턴값은 찾은 노드의 주소 , 못 찾았다면 tail의 주소를 리턴

	//delete_List(30);

	for (i = 0; i < 10; i++)
	{
		move_to_front(i+1);
		print_List();
	}

	puts("");

	for (i = 0; i < 10; i++)
	{
		printf("스왑 전 "); print_List();
		swap(i + 1);
		printf("스왑 후 "); print_List();
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
	printf("삭제 후\n\n");
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
	printf("all 삭제 후\n\n");
	print_List();

	ordered_insert(1);
	ordered_insert(6);
	ordered_insert(10);
	ordered_insert(8);
	print_List();

}