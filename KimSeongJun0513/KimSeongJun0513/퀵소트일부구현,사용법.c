//pivot을 기준으로 앞쪽에서 큰값을 찾고 뒤쪽에서 작은 값을 찾는 구문을 완성하시오.

//큰값을 i 로 검색

//작은 값은 j로 검색


/*
#define swap(a,b) do{int t; t=a; a=b; b=t;}while(0)
int partition(int arr[], int s, int e)
{
	int i, j, pivot;
	i = s; //처음
	j = e + 1; // 마지막??
	pivot = arr[i];
	while (i < j) {

		//pivot보다 큰값을 찾는 구문
		while (pivot >= arr[++i])
		{

		}

		//pivot 보다 작거나 같은 값을 찾는 구문
			while (pivot < arr[--j])
			{

		}
		if (i < j) {
			
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[s], arr[j]);
	return j;
}



void qsort(int arr[], int s, int e)
{
	int mid;
	if (s < e) {
		mid = partition(arr, s, e);
		qsort(arr, s, mid - 1);
		qsort(arr, mid + 1, e);
	}
}

void print_sort(int *p, int cnt)
{
	int dx;
	for (dx = 0; dx < cnt; dx++)
		printf("%d ", p[dx]);
}

main()
{
	int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
	qsort(arri, 0, 9);
	print_sort(arri, sizeof(arri) / sizeof(arri[0]));
}

*/


//퀵소트 사용법


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printInt(int *arr, int size);
void printDbl(double *arr, int size);
void printstr(char(*arr)[7], int size);

int comp_i(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

//라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
int comp_d(const void* a, const void* b) {
	
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

}

//라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
int comp_s(const void* a, const void* b) {

	return strcmp((char*)a,(char*)b);

}




int main(void) {
	int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
	double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5 };
	char arrs[][7] = { "송용하","정우주","신재건","김민지",
		"홍선영","남정우","박정근","오형진",
		"조수빈","이영민" };
	qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
	printInt(arri, sizeof(arri) / sizeof(arri[0]));

	qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
	printDbl(arrd, sizeof(arrd) / sizeof(arrd[0]));

	//라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.

	qsort(arrs, sizeof(arrs) / sizeof(arrs[0]), sizeof(arrs[0]), comp_s);
	printstr(arrs, sizeof(arrs) / sizeof(arrs[0]));

	return 0;
}
void printInt(int *arr, int size) {
	int dx = 0;
	for (dx = 0; dx< size; ++dx) {
		printf("%d ", arr[dx]);
	}
	printf("\n");
}

void printDbl(double *arr, int size) {
	int dx = 0;
	for (dx = 0; dx< size; ++dx) {
		printf("%.1f  ", arr[dx]);
	}
	printf("\n");
}

void printstr(char (*arr)[7], int size) {
	int dx = 0;
	for (dx = 0; dx< size; ++dx) {
		printf("%s ", arr[dx]);
	}
	printf("\n");
}


