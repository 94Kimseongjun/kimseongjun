#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

int Rsum(int n)
{
	if(n==1) // �������
	{
		return n;
	}
	else
	{
		return (n + Rsum(n - 1));
	}

}

void till_z(char a)
{
	
		if (a == 122) { printf("%c", a); return 0; }
		else
		{
			printf("%c ", a);
			a++;
			return  till_z(a);
		}
	
}


void till_a(char a,char temp)
{

	/*
  char temp = 'A';
	printf("%c temp�� Ȯ�� \n", temp);
	if (temp)
	{
		return 0;
	}
	else
	{
	
	printf("%c ", temp);
	temp += 1;
	return  till_a(temp);*/


	int num;
	num = a - temp;

	if (a < 65) return 0;

	else {
	printf("%c", a-num);
	a--;
	temp++;
	return till_a(a,temp);
	}


}



void bprint(void)
{
	int c;

	if ((c = getchar())!= '\n')
		bprint();

	putchar(c);
}


/*

int fibo(int n)
{
int fir,sec,c,dx;
fir=1;sec=1;
for(dx=2;dx<=n;dx++)
{
c=fir+sec;
fir=sec; //n-2
sec=c; //n-1
}
return sec;
}

*/



int fibo(int n)
{
	if (n == 0 || n == 1) return 1;

	else
		return fibo(n - 1) + fibo(n - 2);

}

int main()
{
	//�Ǻ���ġ ����

	//printf("%d",Rsum(4500));
	
//����2�� �ҹ��ڸ� �Է¹޾� �� ���ڷκ��� 'z'���� ����ϴ� ���α׷��� ����Լ��� ����
	//A 65 ~ z 90
	// a 97~ z 122
	//till_z('a');


	char temp = 'A';
	till_a('X',temp);

	// ���� 3�� �빮�ڸ� �Է¹޾� 'A'���� �� ���ڱ��� ����ϴ� ���α׷��� ����Լ��� ����
}

