#include <stdio.h>
#include <stdlib.h>

void main(){

    int **x;//int�� ���������� ���� x

    printf("[----- ������ 2022041021 ----- ]\n");

    printf("sizeof(x) = %lu\n", sizeof(x));//xũ�� ���
    printf("sizeof(*x) = %lu\n", sizeof(*x));//*xũ�� ���
    printf("sizeof(**X) = %lu\n", sizeof(**x));//**xũ�� ���
}