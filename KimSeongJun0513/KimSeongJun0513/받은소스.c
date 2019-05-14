/*

//1. list - (array, linked list)순서가있는 자료구조
//1-0. Sorting(정렬),버블,선택, 삽입(간삽, 쉘)
//                 퀵,병합, 트리정렬, 기수정렬, 기교정렬
// c:algorithm(qsort(), bsearch())
//1-1. circular list, double list(리눅스커널)
//2. stack - LIFO
//3. queue - FIFO(선착순)
//4. tree - 이진트리, -> 균형이진트리, -> 자동 AVL, red-black T
//4-1. 탐색
//4-2. hash-Tree의 재구성
//5. graph - 최소비용스패닝트리, 최단거리알고리즘-> A-star


typedef struct _list List;
struct _list {
int key;
struct _list* next;
};//자기참조구조체
List* head, * tail;//각 기둥 이름

void init_list (void) // 기둥, 선 패 계열
{
head = (List *) malloc (sizeof (List)); // 왼쪽 기둥
꼬리 = (List *) malloc (sizeof (List)); // 가장 기둥
머리 -> 다음 = 꼬리;
꼬리 -> 다음 = 꼬리;
}
void insert_list (int data)
{
List * nw;
nw = (List *) malloc (sizeof (List));
nw-> key = data;
nw-> 다음 = 머리 -> 다음;
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

목록 * find_list (int find)
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

만약 (! wk-> 다음 = 꼬리) // 중간에 찾았다면
{
목록 * 죽 = wk-> 다음;
wk-> 다음 = wk-> 다음 -> 다음;

무료 (죽이기);
}
}
void ordered_insert (int data)
{
List * pre, * cmp;
pre = 머리;
cmp = 머리 -> 다음;

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
//모든 자료구조는 반드시 초기화가 필요
init_list(); //기둥과 빨래줄 만들기
//insert_list(5);//첫번째 빨래(첫번째 노드)
//insert_list(3);
//print_list();
//find_list(7); //5를 찾는 find함수를 구현하시오.
//     //리턴값은 찾은 노드의 주소로
//              //못찾았다면 tail의 주소를 리턴
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
// printf ( "能文?");
// scanf ( "% d", & cnt);
// getchar ();
// p = (char **) malloc (sizeof (char *) * cnt);
//
(size_t i = 0; i <cnt; i ++) {
// printf ( "% d 번째 문장은", i + 1);
// gets (buff);
// p [i] = (char *) malloc (sizeof (char) * strlen (buff) + 1);
// strcpy (p [i], buff);
//}
// (size_t i = 0; i <cnt; i ++)
// puts (p [i]);
//
// (size_t i = 0; i <cnt; i ++)
// free (p [i]);
// 무료 (p);
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
// 무료 (* p);
//
// 무료 (p);
//
//
//}

//자신의 집주소를 입력 받아서
//집주소 길이 만큼 heap을 할당받고
//넣고 출력해보기
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
// free(p);//동적할당한 메모리를 반납하는 동작
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
//  if (cnt != 100)//buf가 다 안찼다면
//  {
//   if (feof(frp) != 0)//0이아니면 파일의 끝이다.
//   {
//    fwrite(buf, 1, cnt, fwp); //마지막 91바이트
//    byte += cnt;
//    puts("복사완료");
//   }else{
//    puts("복사 실패");
//   }
//   break;
//  }
//  fwrite(buf, 1, 100, fwp);
//  byte += 100;
//  //복사된 바이트 수까지 출력하시오.
// }
// printf("복사된 바이트  %d\n", byte);
//
// //char buf[100];
//
// //while (fgets(buf, 100, frp))
// // fputs(buf, fwp);
// //int ch;
// //while ((ch = fgetc(frp))!=-1) //제대로 읽었다면 while로 들어가라.
// // fputc(ch, fwp);
//
//
// fclose(frp);
// fclose(fwp);
//
//}
//







// 유니온 bit {
// int a;
// char b [4];
//};
//
// int main ()
// {
// 유니온 비트 p;
// pa = 0x12345678;
//
// printf ( "% x \ n", pb [0]);
//}


//struct bonnet {
// int engine;
// int piston;
// char pipe;
//};
//struct car {  //서로 다른 타입을 묶는 구조
// struct bonnet bn; //int engine; //변수 -> 멤버변수
// char handle;
// float wheel;
// char carName[10];//배열, 포인터, 함수(x) -> 함수포인터(0)
//};
//int main(){
// struct car bus;// 구조체형 변수  //int a; //int형 변수
// bus.bn.engine = 500; // . 멤버지정 연산자
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
// b = a;//구조체를 대입연산자로 복사 가능
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
// func1(a.fir, a.sec);//구조체멤버 각각 던져서 합
// func2(&b);//구조체 변수주소 던져서 곱
// func3(c);//구조체 배열주소 던져서 합
//}



























//




//struct car {  //서로 다른 타입을 묶는 구조
// int engine; //변수 -> 멤버변수
// char handle;
// float wheel;
// char carName[10];//배열, 포인터, 함수(x) -> 함수포인터(0)
//};
//int main()
//{
// struct car bus;// 구조체형 변수  //int a; //int형 변수
//
// bus.engine = 500; // . 멤버지정 연산자
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

//에이 비 씨 디이

//홍길동 010-1111-2222 22
//김말순 010-2222-3333 21












//int(*p)[3]    /*int형 3개짜리 배열을 가리키는 포인터 p (배포)*/
//int* p[3]  /*int형 주소를 담는 3개짜리 배열  (포배)*/ 
//int* p()  /*int주소를 리턴하는 함수 p  (함수)*/
//int (*p)() /*int리턴하는 함수를 가리키는 포인터(함포) */
//int* (*p)() /*int주소리턴하는 함수를 가리키는 포인터(함포) */
//int (*p[3])() /*함수포인터 배열  */
//func()[i]  /*함수의 리턴값을 배열로 처리  */
//func[i]()  /*함수포인터 배열중 i번째 함수 호출  */

// char * func (void) {// char * : char 형 주소를 
// return "abcd"; 
// 
int main() {
	// (size_t i = 0; i <2; i ++) { 
	// printf ( "% c", func () [i]); 
	//} 
	//}




	// typedef unsigned int uint; // uint 사용자 정의 유형 
	// 
	typedef int(*ppp) (int, int); // myfuncPP; // 사용자 정의 유형 
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
		// p = &ch; //p는 어떤 형태의 주소도 담는다.
		// //printf("%c\n", *p); //알고있는 주소로 부터 몇 바이트를 가져올지 X
		// printf("%c\n", *(char*)p);//값(char형주소로)p
		// 
		// int a = 100;
		// p = &a;
		// printf("%d\n", *(int*)p);//값(int형주소로)p
		//
		// p = func; //p로 func을 호출하시오.
		// ((void (*)(void))p)();
		//
		//       //func();
		//}










		// int add (int a, int b) {리턴 a + b; } 
		// 
		int temp(int(*p_func) (int, int), int a, int b) {
		//  
		// p_func (a, b)를 반환합니다. 
		//} 
		// void main () 
		// { 
		// int a = 10, b = 5; 
		//  
		//의 printf ( "% D \ 없음"임시 (A, B)에 추가); // 범용 함수 구현할 때 사용되는 방법 
		//} 
		// 무효 감기 (무효) // 클라이언트 코드 
		// { 
		/ / puts("콜드");
		//} 
		// void hot (void) // 클라이언트 코드 
		// { 
		// puts ( "hot"); 
		//} 
		// 
		// 무효 에어컨 (무효 (* P) (무효)) // 서버 코드 
		// { 
		// p를 (); // 다시 전화 
		//} 
		// (INT 주) // 클라이언트 코드 
		/ / {
			// aircon(hot);//function call // server에 client를 알려준다.
			// aircon(cold);
			//}




			// int add (int a, int b) {리턴 a + b; } 
			// int sub (int a, int b) {return a - b; } 
			// int mul (int a, int b) {return a * b; } 
			// int dvv (int a, int b) {return a / b; } 
			// 
			// int main () 
			// { 
			// int i; // 
			int(*p[4]) (int, int) = { add, sub, mul, dvv }; // c99 표준에서 변수가 없다. 
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
				// p = 추가; 
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