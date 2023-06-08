#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

//함수 선언//
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);

int quickSort(int *a, int n);


int hashCode(int key);

int hashing(int *a, int **ht);

int search(int *ht, int key);


int main()
{
	char command;//명령어 입력받을 char형 변수 command
	int *array = NULL;//배열에 사용할 int형 포인터 변수 array
	int *hashtable = NULL;//해시테이블에 사용할 int형 포인터 변수 hashtable
	int key = -1;//int형 변수 key -1로 초기화
	int index = -1;//int형 변수 index -1로 초기화

	srand(time(NULL));//난수 초기화

	do{
        printf("[----- [윤혜준] [2022041021] -----]\n");
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");//명령 입력받기
		scanf(" %c", &command);//command변수에 입력받은 명령 저장

		switch(command) {
		case 'z': case 'Z'://z나 Z를 명령으로 받은 경우
			initialize(&array);//배열 초기화
			break;
		case 'q': case 'Q'://q나 Q를 명령으로 받은 경우
			freeArray(array);//배열 할당 해제
			break;
		case 's': case 'S'://s나 S를 명령으로 받은 경우
			selectionSort(array);//선택 정렬하기
			break;
		case 'i': case 'I'://i나 I를 명령으로 받은 경우
			insertionSort(array);//삽입 정렬하기
			break;
		case 'b': case 'B'://b나 B를 명령으로 받은 경우
			bubbleSort(array);//버블 정렬하기
			break;
		case 'l': case 'L'://l이나 L을 명령으로 받은 경우
			shellSort(array);//셸 정렬하기
			break;
		case 'k': case 'K'://k나 K를 명령으로 받은 경우
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);//매개 변수로 array값 받아서 배열 출력하기
			quickSort(array, MAX_ARRAY_SIZE);//매개 변수로 array랑 MAX_ARRAY_SIZE받아 퀵솔트 함수 실행
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H'://h나 H를 명령으로 받은 경우
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);//매개 변수로 array값 받아서 배열 출력하기
			hashing(array, &hashtable);//매개 변수로 array랑 hashtable받아서 해싱 실행
			printArray(hashtable);//매개 변수로 hashtable값 받아서 배열 출력하기
			break;

		case 'e': case 'E'://e나 E를 명령으로 받은 경우
			printf("Your Key = ");
			scanf("%d", &key);//key값 입력받아서 변수에 저장
			printArray(hashtable);//매개 변수로 hashtable값 받아서 배열 출력하기
			index = search(hashtable, key);//hashtable에서 key값 가지는 인덱스 찾기
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);//찾은 인덱스값 key값, hash값이랑 같이 출력
			break;

		case 'p': case 'P'://p나 P를 명령으로 받은 경우
			printArray(array);//매개 변수로 array값 받아서 배열 출력하기
			break;
		default://그외 값을 명령으로 입력받은 경우 없다고 출력하기
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');//z나 Z를 명령으로 받은 경우 loop탈출

	return 1;
}

int initialize(int** a)//초기화 함수
{
	int *temp = NULL;

	if(*a == NULL) {//테이블이 비어있을 경우
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp; 
	} else//그외의 경우
		temp = *a;//*a값을 가지는 변수 temp 초기화

	for(int i = 0; i < MAX_ARRAY_SIZE; i++)//MAX_ARRAY_SIZE번 loop를 반복하면서 temp배열에 0부터 MAX_ARRAY_SIZE-1까지중 임의의 값 넣기
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}

int freeArray(int *a)//동적할당 해제
{
	if(a != NULL)//비어있지 않을 경우 
		free(a);
	return 0;
}

void printArray(int *a)//배열 출력
{
	if (a == NULL) {//배열이 비어있을 경우 출력할 게 없다는 메시지 출력
		printf("nothing to print.\n");
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)//MAX_ARRAY_SIZE번 loop를 반복하면서 배열 원소별 인덱스랑 배열 값들 출력
		printf("a[%02d] ", i);
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);
	printf("\n");
}


int selectionSort(int *a)//매개 변수로 int형 포인터 변수 a 받아서 선택정렬
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);//현재 배열 출력

	for (i = 0; i < MAX_ARRAY_SIZE; i++)//MAX_ARRAY_SIZE번 반복하면서 최소값 찾기
	{
		minindex = i;
		min = a[i];
		for(j = i+1; j < MAX_ARRAY_SIZE; j++)//MAX_ARRAY_SIZE번 반복하면서 최솟값 찾기
		{
			if (min > a[j])//새로운 최솟값 찾으면 최솟값 교체
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}

int insertionSort(int *a)//int형 포인터 변수 a받아서 삽입 정렬
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);//현재 배열 상태 출력

	for(i = 1; i < MAX_ARRAY_SIZE; i++)//MAX_ARRAY_SIZE번 반복하면서 변수 정렬하기
	{
		t = a[i];
		j = i;
		while (a[j-1] > t && j > 0)//정렬되지 않은 변수 발견하면 변수 정렬하기
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = t;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int bubbleSort(int *a)//int형 포인터 변수 a 받아서 버블 정렬하기
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for(i = 0; i < MAX_ARRAY_SIZE; i++)//MAX_ARRAY_SIZE번 반복하면서 순서대로 정렬하기
	{
		for (j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j-1] > a[j])//앞의 원소가 뒤의 원소보다 큰 경우 순서대로 되게 정렬
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int shellSort(int *a)//int형 포인터 변수 a 받아서 셸 정렬하기
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++)
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j];
				k = j;
				while (k > h-1 && a[k-h] > v)
				{
					a[k] = a[k-h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int quickSort(int *a, int n)//int형 포인터 변수 a랑 int형 변수 n 받아서 퀵 정렬하기
{
	int v, t;
	int i, j;

	if (n > 1)
	{
		v = a[n-1];
		i = -1;
		j = n - 1;

		while(1)
		{
			while(a[++i] < v);
			while(a[--j] > v);

			if (i >= j) break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i);
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

int hashCode(int key) {//key값을 MAX_HASH_TABLE_SIZE로 나눈 나머지 구하기
   return key % MAX_HASH_TABLE_SIZE;
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL;

	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable; 
	} else {
		hashtable = *ht;
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;

	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);

		if (hashtable[hashcode] == -1)
		{
			hashtable[hashcode] = key;
		} else 	{

			index = hashcode;

			while(hashtable[index] != -1)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
			}
			hashtable[index] = key;
		}
	}

	return 0;
}

int search(int *ht, int key)//ht주소에 위치한 해시 테이블에서 key값 가지는 데이터의 인덱스 값 구하기
{
	int index = hashCode(key);

	if(ht[index] == key)
		return index;

	while(ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE;
	}
	return index;
}


