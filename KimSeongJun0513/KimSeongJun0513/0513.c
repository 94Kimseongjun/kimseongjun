#include<stdio.h>
#pragma warning(disable: 4996)
/*
23-5 ������


*/

int main()
{
	/*
	FILE *fp;
	fp = fopen("a.txt", "w"); // a.txt �� ������ ���� ����
	fprintf(fp, "%d %s ", 26, "Kim");

	fclose(fp); //������ �������� ���� ����

	fp = fopen("a.txt", "r");
	int age;
	char name[50];

	fscanf(fp, "%d %s", &age, name);
	fclose(fp);

	fp = fopen("a.txt", "a"); // a.txt �� ������ ���� ����
	fprintf(fp, "%s\n", "Jun2");
	fclose(fp); //������ �������� ���� ����
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
		if (cnt != 100) // buf�� �� ��á�ٸ�
		{
			if (feof(frp) != 0) 
			{ 
				fwrite(buf, 1, cnt, fwp);//������ ����Ʈ���� ����
				puts("����Ϸ�\n");
				byte += cnt;
			
			} //0�� �ƴϸ� ������ ���̴�.
			else
			{
				puts("�������\n");
			}
			break;
		}

		fwrite(buf, 1, 100, fwp);
		byte += cnt;
	}

	//����� ����Ʈ ������ ����Ͻÿ�.

	printf("%d byte ���� �Ϸ�\n",byte);


	/*
	frp = fopen("a.txt", "r");
	fwp = fopen("b.txt", "w");

	*/

	/*
	char buf[100];

	while (fgets(buf, 100, frp))
	{
		printf("Ȯ��\n");
		fputc(buf, fwp);
	}
	*/


	/*
	int ch;

	while ((ch = fgetc(frp))!=-1) //����� �о��ٸ�
	{
		fputc(ch, fwp);
	}
	*/

	fclose(frp);
	fclose(fwp);

	return 0;
}


