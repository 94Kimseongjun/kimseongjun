/*

//1. list - (array, linked list)�������ִ� �ڷᱸ��
//1-0. Sorting(����),����,����, ����(����, ��)
//                 ��,����, Ʈ������, �������, �ⱳ����
// c:algorithm(qsort(), bsearch())
//1-1. circular list, double list(������Ŀ��)
//2. stack - LIFO
//3. queue - FIFO(������)
//4. tree - ����Ʈ��, -> ��������Ʈ��, -> �ڵ� AVL, red-black T
//4-1. Ž��
//4-2. hash-Tree�� �籸��
//5. graph - �ּҺ�뽺�д�Ʈ��, �ִܰŸ��˰���-> A-star


typedef struct _list List;
struct _list {
int key;
struct _list* next;
};//�ڱ���������ü
List* head, * tail;//�� ��� �̸�

void init_list (void) // ���, �� �� �迭
{
head = (List *) malloc (sizeof (List)); // ���� ���
���� = (List *) malloc (sizeof (List)); // ���� ���
�Ӹ� -> ���� = ����;
���� -> ���� = ����;
}
void insert_list (int data)
{
List * nw;
nw = (List *) malloc (sizeof (List));
nw-> key = data;
nw-> ���� = �Ӹ� -> ����;
head-> next = nw;
}

void print_list (void)
{
List * wk;
wk = head-> next;

while (wk! = tail) {
printf ( "% d \ n", wk-> key);
wk = wk-> next;
}
// printf ( "% d \ n", wk-> key);

// wk = wk-> next;

// printf ( "% d \ n", wk-> key);


// printf ( "% d \ n", head-> next-> key);
// printf ( "% d \ n", head-> next-> next-> key);
}

��� * find_list (int find)
{
List * wk;
wk = head-> next;

while (wk-> key! = find && wk! = tail)
{
wk = wk-> next;
}

if (wk! = tail)
puts ( "succ");
else
puts ( "fail");

return wk;
}

void delete_list (int del)
{
List * wk;
wk = head;
while (wk-> next-> key! = del && wk-> next! = tail)
wk = wk-> next;

���� (! wk-> ���� = ����) // �߰��� ã�Ҵٸ�
{
��� * �� = wk-> ����;
wk-> ���� = wk-> ���� -> ����;

���� (���̱�);
}
}
void ordered_insert (int data)
{
List * pre, * cmp;
pre = �Ӹ�;
cmp = �Ӹ� -> ����;

while (cmp->key < data && cmp != tail)
{
pre = pre->next;
cmp = cmp->next;
}
List* nw = (List*)malloc(sizeof(List));
nw->key = data;
pre->next = nw;
nw->next = cmp;
}
int main(){
//��� �ڷᱸ���� �ݵ�� �ʱ�ȭ�� �ʿ�
init_list(); //��հ� ������ �����
//insert_list(5);//ù��° ����(ù��° ���)
//insert_list(3);
//print_list();
//find_list(7); //5�� ã�� find�Լ��� �����Ͻÿ�.
//     //���ϰ��� ã�� ����� �ּҷ�
//              //��ã�Ҵٸ� tail�� �ּҸ� ����
//delete_list(3);
ordered_insert(3);
ordered_insert(4);
ordered_insert(1);
ordered_insert(5);
ordered_insert(2);

print_list ();

}












// int main ()
// {
// char ** p;
//
// int cnt;
// char buff [100];
// printf ( "����?");
// scanf ( "% d", & cnt);
// getchar ();
// p = (char **) malloc (sizeof (char *) * cnt);
//
(size_t i = 0; i <cnt; i ++) {
// printf ( "% d ��° ������", i + 1);
// gets (buff);
// p [i] = (char *) malloc (sizeof (char) * strlen (buff) + 1);
// strcpy (p [i], buff);
//}
// (size_t i = 0; i <cnt; i ++)
// puts (p [i]);
//
// (size_t i = 0; i <cnt; i ++)
// free (p [i]);
// ���� (p);
//
//
}}
// int main ()
// {
// char ** p;
//
// p = (char **) malloc (sizeof (char *) * 1);
//
// * p = (char *) malloc (sizeof (char) * 3);
//
// ** p = 'A';
//
// printf ( "% c", ** p);
//
// ���� (* p);
//
// ���� (p);
//
//
//}

//�ڽ��� ���ּҸ� �Է� �޾Ƽ�
//���ּ� ���� ��ŭ heap�� �Ҵ�ް�
//�ְ� ����غ���
//int main()
//{
// char address[100];
//
// gets(address);
//
// char* p;
// p = (char*)malloc(sizeof(char) * strlen(address) + 1);
//
// strcpy(p, address);
//
// puts(p);
//
// free(p);//�����Ҵ��� �޸𸮸� �ݳ��ϴ� ����
//
//
//}


//
// int main ()
// {
// // int a [5];
// // int * p;
// // p = a;
// // * p = 10;
//
// // int * k;
// // k = malloc (20);
// // * k = 10;
//
//
//
//}
//

























// char buf[100];
// int byte = 0;
// int cnt;
// while (1) {
//  cnt = fread(buf, 1, 100, frp);
//  if (cnt != 100)//buf�� �� ��á�ٸ�
//  {
//   if (feof(frp) != 0)//0�̾ƴϸ� ������ ���̴�.
//   {
//    fwrite(buf, 1, cnt, fwp); //������ 91����Ʈ
//    byte += cnt;
//    puts("����Ϸ�");
//   }else{
//    puts("���� ����");
//   }
//   break;
//  }
//  fwrite(buf, 1, 100, fwp);
//  byte += 100;
//  //����� ����Ʈ ������ ����Ͻÿ�.
// }
// printf("����� ����Ʈ  %d\n", byte);
//
// //char buf[100];
//
// //while (fgets(buf, 100, frp))
// // fputs(buf, fwp);
// //int ch;
// //while ((ch = fgetc(frp))!=-1) //����� �о��ٸ� while�� ����.
// // fputc(ch, fwp);
//
//
// fclose(frp);
// fclose(fwp);
//
//}
//







// ���Ͽ� bit {
// int a;
// char b [4];
//};
//
// int main ()
// {
// ���Ͽ� ��Ʈ p;
// pa = 0x12345678;
//
// printf ( "% x \ n", pb [0]);
//}


//struct bonnet {
// int engine;
// int piston;
// char pipe;
//};
//struct car {  //���� �ٸ� Ÿ���� ���� ����
// struct bonnet bn; //int engine; //���� -> �������
// char handle;
// float wheel;
// char carName[10];//�迭, ������, �Լ�(x) -> �Լ�������(0)
//};
//int main(){
// struct car bus;// ����ü�� ����  //int a; //int�� ����
// bus.bn.engine = 500; // . ������� ������
//
// printf("%d\n", bus.bn.engine);
//
//
//
//
//}

//struct num {
// int fir;
// int sec;
//};
//struct num2 {
// int fir;
// char sec[10];
//};
//struct num3 {
// int fir;
// char *sec;
//};
//main()
//{
// struct num3 e = { 200,"zzzz" };
// struct num3 f;
// f = e;
//
//
// struct num a = { 1,2 };
// struct num b;
// b = a;//����ü�� ���Կ����ڷ� ���� ����
// struct num2 c = { 100, "aaaa" };
// struct num2 d;
// d = c;
//}

//
//void func1(int a, int b){
// pf("%d", a + b);
//
//}
//void func2(struct num *p) {
//
// pf("%d", p->fir * p->sec);
//}
//void func3(struct num* p) {
//
// p->fir + p->sec + (p + 1)->fir + (p + 1)->sec;
// (*p).fir +      +(*(p + 1)).fir + ;
// p[0].fir +      + p[1].fir      +
//}
//main(){
// struct num a = { 1,2 }, b = { 3,4 }, c[2] = { 5,6,7,8 };
// func1(a.fir, a.sec);//����ü��� ���� ������ ��
// func2(&b);//����ü �����ּ� ������ ��
// func3(c);//����ü �迭�ּ� ������ ��
//}



























//




//struct car {  //���� �ٸ� Ÿ���� ���� ����
// int engine; //���� -> �������
// char handle;
// float wheel;
// char carName[10];//�迭, ������, �Լ�(x) -> �Լ�������(0)
//};
//int main()
//{
// struct car bus;// ����ü�� ����  //int a; //int�� ����
//
// bus.engine = 500; // . ������� ������
// bus.handle = 'B';
// bus.wheel = 35.5f;
//
// printf("%d\n", bus.engine);
//
// scanf("%d", &bus.engine);
//
// printf("%d\n", bus.engine);
//
//
//
//}

//1 2 3 4 5

//���� �� �� ����

//ȫ�浿 010-1111-2222 22
//�踻�� 010-2222-3333 21












//int(*p)[3]    /*int�� 3��¥�� �迭�� ����Ű�� ������ p (����)*/
//int* p[3]  /*int�� �ּҸ� ��� 3��¥�� �迭  (����)*/ 
//int* p()  /*int�ּҸ� �����ϴ� �Լ� p  (�Լ�)*/
//int (*p)() /*int�����ϴ� �Լ��� ����Ű�� ������(����) */
//int* (*p)() /*int�ּҸ����ϴ� �Լ��� ����Ű�� ������(����) */
//int (*p[3])() /*�Լ������� �迭  */
//func()[i]  /*�Լ��� ���ϰ��� �迭�� ó��  */
//func[i]()  /*�Լ������� �迭�� i��° �Լ� ȣ��  */

// char * func (void) {// char * : char �� �ּҸ� 
// return "abcd"; 
// 
int main() {
	// (size_t i = 0; i <2; i ++) { 
	// printf ( "% c", func () [i]); 
	//} 
	//}




	// typedef unsigned int uint; // uint ����� ���� ���� 
	// 
	typedef int(*ppp) (int, int); // myfuncPP; // ����� ���� ���� 
								  // 
	int func(int a, int b)
		// { 
		// printf ( "% d \ n", a + b); 
		//} 
		// 
		// int main () 
		// { 
		//  
		// uint a; // unsigned int a; 
		// 
		// int (* p) (int, int) = func; 
		// ppp p = func; 
		// 
		// p (10, 20); 
		//}





		//
		//void func(void)
		//{
		// puts("func");
		//}
		//int main()
		//{
		// char ch = 'A';
		// void* p;
		// p = &ch; //p�� � ������ �ּҵ� ��´�.
		// //printf("%c\n", *p); //�˰��ִ� �ּҷ� ���� �� ����Ʈ�� �������� X
		// printf("%c\n", *(char*)p);//��(char���ּҷ�)p
		// 
		// int a = 100;
		// p = &a;
		// printf("%d\n", *(int*)p);//��(int���ּҷ�)p
		//
		// p = func; //p�� func�� ȣ���Ͻÿ�.
		// ((void (*)(void))p)();
		//
		//       //func();
		//}










		// int add (int a, int b) {���� a + b; } 
		// 
		int temp(int(*p_func) (int, int), int a, int b) {
		//  
		// p_func (a, b)�� ��ȯ�մϴ�. 
		//} 
		// void main () 
		// { 
		// int a = 10, b = 5; 
		//  
		//�� printf ( "% D \ ����"�ӽ� (A, B)�� �߰�); // ���� �Լ� ������ �� ���Ǵ� ��� 
		//} 
		// ��ȿ ���� (��ȿ) // Ŭ���̾�Ʈ �ڵ� 
		// { 
		/ / puts("�ݵ�");
		//} 
		// void hot (void) // Ŭ���̾�Ʈ �ڵ� 
		// { 
		// puts ( "hot"); 
		//} 
		// 
		// ��ȿ ������ (��ȿ (* P) (��ȿ)) // ���� �ڵ� 
		// { 
		// p�� (); // �ٽ� ��ȭ 
		//} 
		// (INT ��) // Ŭ���̾�Ʈ �ڵ� 
		/ / {
			// aircon(hot);//function call // server�� client�� �˷��ش�.
			// aircon(cold);
			//}




			// int add (int a, int b) {���� a + b; } 
			// int sub (int a, int b) {return a - b; } 
			// int mul (int a, int b) {return a * b; } 
			// int dvv (int a, int b) {return a / b; } 
			// 
			// int main () 
			// { 
			// int i; // 
			int(*p[4]) (int, int) = { add, sub, mul, dvv }; // c99 ǥ�ؿ��� ������ ����. 
															//  
			(i = 0; i <4; i++)
				// { 
				// printf ( "% d \ n", p [i] (10, 5)); 
				//} 
				//}

				// int add (int a, int b) {return a + b;} 
				// int sub (int a, int b) {return a - b; } 
				// int mul (int a, int b) {return a * b; } 
				// int dvv (int a, int b) {return a / b; } 
				// 
				// int () 
				// { 
				// int (* p) (int, int); 
				// p = �߰�; 
				// printf ( "% d \ n", p (10, 5)); 
				// p = sub; 
				// printf ( "% d \ n", p (10, 5)); 
				// p = mul; 
				// printf ( "% d \ n", p (10, 5)); 
				// p = dvv; 
				// printf ( "% d \ n", p (10, 5)); 
				// 
				//}



*/