#include <stdio.h>

struct student1 {
    char lastName;//char�� ���� lastName
    int studentId;//int�� ���� studentId
    char grade;//char�� ���� grade

};//����ü �̸� student1

typedef struct {
    char lastName;//char�� ���� lastName
    int studentId;//int�� ���� studentId
    char grade;//char�� ���� grade
} student2;//����ü �̸� student2

int main(){
    struct student1 st1 = {'A', 100, 'A'};//student1����ü ���� st1�� ���� lastName, studentId, grade�� ���ʴ�� A, 100, A�� �ִ´�

    printf("[----- ������ 2022041021 ----- ]\n");

    printf("st1.lastName = %c\n", st1.lastName);//st1.lastName �� A ���
    printf("st1.studentId = %d\n", st1.studentId);//st1.studentId�� 100 ���
    printf("st1.grade = %c\n", st1.grade);//st1.grade�� A���

    student2 st2 = {'B', 200, 'B'};//student2����ü ���� st2�� ���� lastName, studentId, grade�� ���ʴ�� B, 200, B�� �ִ´�


    printf("\nst2.lastName = %c\n", st2.lastName);//st2.lastName�� B ���
    printf("st2.studentId = %d\n", st2.studentId);//st2.studentId�� 200 ���
    printf("st2,grade = %c\n", st2.grade);//st2.grade�� B ���

    student2 st3;//student2����ü ���� st3
    st3 = st2;//st3�� st2�� �ֱ�

    printf("\nst3.lastName = %c\n", st3.lastName);//st3.lastName�� B ���
    printf("st3.studentId = %d\n", st3.studentId);//st3.studentId�� 200���
    printf("st3.grade = %c\n", st3.grade);//st3.grade�� B���

    if ((st3.lastName == st2.lastName)&&(st3.grade == st2.grade)&&(st3.studentId == st2.studentId))//st3�� st2�� ������ ��ġ�ϴ� �� Ȯ���ϰ� ������ �������� ��ġ�ϴ��� Ȯ��
       printf("equal\n");
    else printf("not equal\n");

    return 0;
}