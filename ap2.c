#include <stdio.h>
#include <stdlib.h>

void main(){
    int list[5];//int�� �迭 ����
    int *plist[5];//int�� ������ �迭 ����

    list[0] = 10;//list[0]�� ����
    list[1] = 11;//list[1]�� ����

    plist[0] = (int *)malloc(sizeof(int));//int�� ������ �����Ҵ�
    
    printf("[----- ������ 2022041021 ----- ]\n");
    
    printf("list[0] \t= %d\n", list[0]);//list[0]�� ���
    printf("list \t\t= %p\n", list);//list[0]�ּҰ� ���
    printf("&list[0] \t= %p\n", &list[0]);//list[0]�ּҰ� ���
    printf("list + 0 \t= %p\n", list+0);//list[0]�ּҰ� ���
    printf("list + 1 \t= %p\n", list+1);//list[1]�ּҰ� ���
    printf("list + 2 \t= %p\n", list+2);//list[2]�ּҰ� ���
    printf("list + 3 \t= %p\n", list+3);//list[3]�ּҰ� ���
    printf("list + 4 \t= %p\n", list+4);//list[4]�ּҰ� ���
    printf("&list[4] \t= %p\n", &list[4]);//list[4]�ּҰ� ���

    free(plist[0]);//�Ҵ� ����
}