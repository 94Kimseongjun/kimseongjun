#include<stdio.h>
#pragma warning(disable: 4996)
/*
23-5 열거형


*/

int main()
{
	/*
	FILE *fp;
	fp = fopen("a.txt", "w"); // a.txt 가 없으면 새로 만듬
	fprintf(fp, "%d %s ", 26, "Kim");

	fclose(fp); //파일이 쓰여지는 것을 보장

	fp = fopen("a.txt", "r");
	int age;
	char name[50];

	fscanf(fp, "%d %s", &age, name);
	fclose(fp);

	fp = fopen("a.txt", "a"); // a.txt 가 없으면 새로 만듬
	fprintf(fp, "%s\n", "Jun2");
	fclose(fp); //파일이 쓰여지는 것을 보장
	*/

	FILE *frp, *fwp;

	frp = fopen("3.jpg", "rb");
	fwp = fopen("4.jpg", "wb");

	char buf[100];
	int cnt;
	int byte=0;
	while (1)
	{
		cnt = fread(buf, 1, 100, frp);
		if (cnt != 100) // buf가 다 안찼다면
		{
			if (feof(frp) != 0) 
			{ 
				fwrite(buf, 1, cnt, fwp);//마지막 바이트까지 복사
				puts("복사완료\n");
				byte += cnt;
			
			} //0이 아니면 파일의 끝이다.
			else
			{
				puts("복사실패\n");
			}
			break;
		}

		fwrite(buf, 1, 100, fwp);
		byte += cnt;
	}

	//복사된 바이트 수까지 출력하시오.

	printf("%d byte 복사 완료\n",byte);


	/*
	frp = fopen("a.txt", "r");
	fwp = fopen("b.txt", "w");

	*/

	/*
	char buf[100];

	while (fgets(buf, 100, frp))
	{
		printf("확인\n");
		fputc(buf, fwp);
	}
	*/


	/*
	int ch;

	while ((ch = fgetc(frp))!=-1) //제대로 읽었다면
	{
		fputc(ch, fwp);
	}
	*/

	fclose(frp);
	fclose(fwp);

	return 0;
}


