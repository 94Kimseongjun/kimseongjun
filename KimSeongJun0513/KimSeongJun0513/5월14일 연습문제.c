#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)


/*

=====  M E N U  =====
1. 매출현황 출력
2. 매출현황 내보내기
3. 상품 찾기
4. 상품 삭제
5. 매출현황 배열
6. 정렬
7. 종료
=====================
메뉴를 선택하시오  :1



============================================
삼성전자 온라인  매출 현황
============================================
상품명          단가    개수       금액
--------------------------------------------
1             DVD          65      12        780
2           LEDTV         260     221      57460
3        갤럭시A7        1022    1654    1690388
4        갤럭시s7         190    2034     386460
5      공기청정기         191    3045     581595
6      김치냉장고         456      30      13680
7         노트북5         798     875     698250
8      드럼세탁기         863     396     341748
9    레이져프린터         122     324      39528
10    멀티형에어컨       1653    1980    3272940
11  스탠드형선풍기         46     809      37214
12    업소형냉장고       1187     303     359661
13      일반세탁기        489     421     205869
14    일반용제습기        173      26       4498
15    일반형냉장고        338      78      26364
16        전기오븐        458      77      35266
17      전자레인지         88      55       4840
18            지펠        920     123     113160
19      진공청소기        183     456      83448
--------------------------------------------
매출 합계           7953149
============================================

=====  M E N U  =====
1. 매출현황 출력
2. 매출현황 내보내기
3. 상품 찾기
4. 상품 삭제
5. 매출현황 배열
6. 정렬
7. 종료
=====================
메뉴를 선택하시오  : 2



================
파일로내보내기 완성
================

================

=====  M E N U  =====
1. 매출현황 출력
2. 매출현황 내보내기
3. 상품 찾기
4. 상품 삭제
5. 매출현황 배열
6. 정렬
7. 종료
=====================
메뉴를 선택하시오  : 3


검색상품 입력 : DVD
============================================
상품명          단가    개수       금액
--------------------------------------------
DVD    65      12        780
============================================

=====  M E N U  =====
1. 매출현황 출력
2. 매출현황 내보내기
3. 상품 찾기
4. 상품 삭제
5. 매출현황 배열
6. 정렬
7. 종료
=====================
메뉴를 선택하시오  : 6

정렬방법을 선택하시오
(상품명=0, 금액=1, 판매량=2, 판매금액=3) : 1
정렬방법을 선택하시오
(오름차순=0, 내림차순=1) : 1

============================================
삼성전자 온라인 매출 현황
============================================
상품명  단가    개수       금액
--------------------------------------------
멀티형에어컨  1653    1980    3272940
업소형냉장고  1187     303     359661
갤럭시A7  1022    1654    1690388
지펠   920     123     113160
드럼세탁기   863     396     341748
노트북5   798     875     698250
일반세탁기   489     421     205869
전기오븐   458      77      35266
김치냉장고   456      30      13680
일반형냉장고   338      78      26364
LEDTV   260     221      57460
공기청정기   191    3045     581595
갤럭시s7   190    2034     386460
진공청소기   183     456      83448
일반용제습기   173      26       4498
레이져프린터   122     324      39528
전자레인지    88      55       4840
DVD    65      12        780
스탠드형선풍기    46     809      37214
--------------------------------------------
매출 합계           7953149
============================================

*/

typedef struct _items items;

struct _items
{
	//상품명          단가    개수       금액
	char item_name[20];
	int price; //가격
	int num; //팔린 개수

	struct _itmes* next;

};
items* head, *tail;

void init_list(void)
{
	head = (items*)malloc(sizeof(items)); //왼쪽 기둥
	tail = (items*)malloc(sizeof(items)); // 오른쪽 기둥
	head->next = tail;
	tail->next = tail;
}


void print_List(void)
{
	items *wk;
	wk = head->next;
	while (wk != tail)
	{
		printf("제품명:%s 단가:%d 팔린개수:%d\n", wk->item_name, wk->price, wk->num);
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
	printf("%d를 찾았습니다.\n", data);
	printf("%d는 %d번째 노드\n", data,cnt);
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
		//puts("성공");
	}
	else
	{
		puts("실패");
	}
	return wk;
}



void print_all()
{
	items *wk;
	int i = 1;
	wk = head->next;

	printf("============================================\n삼성전자 온라인  매출 현황\n== == == == == == == == == == == == == == == == == == == == == ==\n");
	printf("번호\t상품명\t단가\t판매개수\t금액\n");
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
		printf("1.매출현황 출력\n");
		printf("2.매출현황 내보내기\n");
		printf("3.상품 찾기\n");
		printf("4.상품 삭제\n");
		printf("5.매출현황 배열\n");
		printf("6.정렬\n");
		printf("7.종료\n");
		scanf("%d", &q);
		switch (q)
		{
		case 1: print_all(); break;
		case 3:

			printf("검색 상품 입력:");
			scanf("%s", search);
			temp = find_List(search);
			printf("============================================\n삼성전자 온라인  매출 현황\n== == == == == == == == == == == == == == == == == == == == == ==\n");
			printf("상품명\t단가\t판매개수\t금액\n");
			printf("-----------------------------------------------------\n");
			printf("%s\t%d\t%d\t%d\n", temp->item_name, temp->price, temp->num, temp->num*temp->price);

			break;

		case 6:

			printf("정렬기준을 선택하시오\n");
			printf("(상품명=0, 단가=1, 판매개수=2, 판매금액=3):");
			scanf("%d", &q);

			
			printf("정렬방법을 선택하시오.\n(오름차순=0, 내림차순=1):");
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