#include <stdio.h>

void print_one(int *ptr, int rows);//print_onc�Լ� ����

int main(){
    int one[] = {0, 1, 2, 3, 4};//int�� �迭�� ���ʴ�� 0, 1, 2, 3, 4�� ����

    printf("[----- ������ 2022041021 ----- ]\n");

    printf("one = %p\n", one);//one[0]�ּҰ� ���
    printf("&one = %p\n", &one);//one�ּҰ� ���
    printf("&one[0] = %p\n", &one[0]);//one[0]�ּҰ� ���
    printf("\n");

    printf("--------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("--------------------\n");
    print_one(&one[0], 5);

    printf("--------------------\n");
    printf(" print_one(one, 5) \n");
    printf("--------------------\n");
    print_one(one, 5);

    return 0;

}

void print_one(int *ptr, int rows){
    int i;
    printf("Address \t Contents\n");
    for (i=0; i< rows; i++)
       printf("%p \t %5d\n", ptr + i, *(ptr+i));//�Է¹��� �Լ� ptr�� ���ʴ�� i��ŭ ���� ���� �ּҰ��� �� ���� ����� �� ���
    printf("\n");
}