#include <stdio.h>

struct student {
    char lastName[13];//char�� ũ�� 13�� �迭 lastName
    int studentId;//int�� ���� studentId
    short grade;//short�� ���� grade
};

int main(){
    struct student pst;//student����ü ���� pst����

    printf("[----- ������ 2022041021 ----- ]\n");

    printf("size of student = %ld\n", sizeof(struct student));//struct student ũ�� ���
    printf("size of int = %ld\n", sizeof(int));//intũ�� ���
    printf("size of short = %ld\n", sizeof(short));//shortũ�� ���

    return 0;
}