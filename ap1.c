#include <stdio.h>
#include <stdlib.h>

void main(){
    int list[5];//int �� �迭 ����
    int *plist[5] = {NULL,};//int�� ������ �迭 ����

    plist[0] = (int *)malloc(sizeof(int));//int�� �����Ҵ�

    list[0] = 1;
    list[1] = 100;

    *plist[0] = 200;

    printf("[----- ������ 2022041021 ----- ]\n");
    
    printf("list[0] = %d\n", list[0]);//list[0]�� ���
    printf("&list[0] = %p\n", &list[0]);//list[0]�ּҰ� ���
    printf("list = %p\n", list);//list[0]�ּҰ� ���
    printf("&list = %p\n", &list);//list[0]�ּҰ� ���

    printf("--------------------\n");
    printf("list[1] = %d\n", list[1]);//list[1]�� ���
    printf("&list[1] = %p\n", list[1]);//list[1]�ּҰ� ���
    printf("*(list+1) = %d\n", *(list+1));//list[1]�� ���
    printf("list+1 = %p\n", list+1);//list[1]�ּҰ� ���
     
    printf("--------------------\n");
    printf("*plist[0] = %d\n", *plist[0]);//plist[0]�� ���
    printf("&plist[0] = %p\n", &plist[0]);//plist[0]�ּҰ� ���
    printf("&plist = %p\n", &plist);//plist[0]�ּҰ� ���
    printf("plist = %p\n", plist);//plist[0]�ּҰ� ���
    printf("plist[0] = %p\n", plist[0]);//plist[0]�� ���
    printf("plist[1] = %p\n", plist[1]);//plist[0]�����Ҵ�� �� �ּ� ���
    printf("plist[2] = %p\n", plist[2]);//�Ҵ� �ȵż� �ּ� ����
    printf("plist[3] = %p\n", plist[3]);//�Ҵ� �ȵż� �ּ� ����
    printf("plist[4] = %p\n", plist[4]);//�Ҵ� �ȵż� �ּ� ����

    free(plist[0]);//�Ҵ� ����
}