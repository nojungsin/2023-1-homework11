#include <stdio.h>

#define MAX_SIZE 100//MAX_SIZE 100���� ����

float sum1(float list[], int);//sum1�Լ� ����
float sum2(float *list, int);//sum2�Լ� ����
float sum3(int n, float *list);//sum3�Լ� ����

float input[MAX_SIZE], answer;//float�� �迭 input, ���� answer ����
int i;
void main(void){
    for (i=0; i < MAX_SIZE; i++)//MAX_SIZE��ŭ �ݺ��ϸ鼭 input[i]�� i�� �ֱ�
        input[i] = i;
    
    printf("[----- ������ 2022041021 ----- ]\n");

    printf("--------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]�ּҰ� ���

    answer = sum1(input, MAX_SIZE);//answer�� sum1(input, MAX_SIZE)�� �ֱ�
    printf("The sum is : %f\n\n", answer);//answer�� ���

    printf("--------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]�ּҰ� ���

    answer = sum2(input, MAX_SIZE);//answer�� sum1(input, MAX_SIZE)�� �ֱ�
    printf("The sum is : %f\n\n", answer);//answer�� ���

    printf("--------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]�ּҰ� ���

    answer = sum3(MAX_SIZE, input);//answer�� sum3(input, MAX_SIZE)�� �ֱ�
    printf("The sum is : %f\n\n", answer);//answer�� ���

}

float sum1(float list[], int n){
    printf("list \t= %p\n", list);//list[0]�ּҰ� ���
    printf("&list \t= %p\n\n", &list);//list�ּҰ� ���

    int i;//int�� ���� i
    float tempsum = 0;//float�� ���� tempsum
    for (i=0; i<n; i++)
      tempsum += list[i];
    return tempsum;
}//������ list�迭�̶� n���� �ޱ�. n��ŭ �ݺ��ϸ鼭 list[i]������ �� ���ؼ� ���� ���� tempsum�� ������ tempsum�� return

float sum2(float *list, int n){
    printf("list \t= %p\n", list);//list[0]�ּҰ� ���
    printf("&list \t= %p\n\n", &list);//list�ּҰ� ���

    int i;//int�� ���� i
    float tempsum = 0;//float�� ���� tempsum
    for (i=0; i<n; i++)
      tempsum += *(list+i);
    return tempsum;
}//������ list�����Ͷ� n���� �ް�, n��ŭ �ݺ��ϸ鼭 list�������� �� ĭ�� �Űܰ��鼭 ���� ������ �� ���ؼ� ���� ���� tempsum�� ������ tempsum�� return

float sum3(int n, float *list){
    printf("list \t= %p\n", list);//list[0]�ּҰ� ���
    printf("&list \t= %p\n\n", &list);//list�ּҰ� ���

    int i;//int�� ���� i
    float tempsum = 0;//float�� ���� tempsum
    for (i=0; i<n; i++)
      tempsum += *(list+i);
    return tempsum;
}//������ n������ list������ �ް�, n��ŭ �ݺ��ϸ鼭 list�������� �� ĭ�� �Űܰ��鼭 ���� ������ �� ���ؼ� ���� ���� tempsum�� ������ tempsum�� return