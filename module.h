#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "course.h"

void ready_exit_module() {
    printf("���������ַ��˳���");
    int dd;
    scanf("%d", &dd);
    system("cls");
}

void ready_exit_module1() {
    printf("���������ַ��˳���");
    int dd;
    scanf("%d", &dd);
    system("cls");
}

void take_in_stu() {
    system("cls");
    int line_num = getLineNum("student.txt");
    if (line_num < 1) {
        Stu *new_stu = NULL;
        new_stu = stu_creat(new_stu);
        system("cls");
        stu_Write_File(new_stu);
        stu_print(new_stu);
        ready_exit_module();
    } else {
        Stu *old_stu = NULL;
        old_stu = stu_Read_File(old_stu);
        printf("��ȡ�ɹ�\n");
        stu_print(old_stu);
        old_stu = stu_creat(old_stu);
        system("cls");
        stu_Write_File(old_stu);
        stu_print(old_stu);
        ready_exit_module();
    }
}

void take_in_cou() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        Cou *new_cou;
        new_cou = cou_creat(new_cou);
        system("cls");
        cou_Write_File(new_cou);
        cou_print(new_cou);
        ready_exit_module();
    } else {
        Cou *old_cou;
        old_cou = cou_Read_File(old_cou);
        printf("��ȡ�ɹ�\n");
        cou_print(old_cou);
        old_cou = cou_creat(old_cou);
        system("cls");
        cou_Write_File(old_cou);
        cou_print(old_cou);
        ready_exit_module();
    }
}

void delete_stu() {
    system("cls");
    int line_num = getLineNum("student.txt");
    if (line_num < 1) {
        printf("Ŀǰû��ѧ����Ϣ��¼");
        ready_exit_module();
    } else {
        Stu *old_stu = NULL;
        old_stu = stu_Read_File(old_stu);
        printf("��ȡ�ɹ�\n");
        stu_print(old_stu);
        printf("������Ҫɾ����ѧ��ѧ�ţ�");
        long long delete_num;
        scanf("%lld", &delete_num);
        system("cls");
        stu_delete(old_stu, delete_num);
        stu_print(stu_delete2(old_stu, delete_num));
        ready_exit_module();
    }
}

void delete_cou() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        printf("Ŀǰû�пγ���ɼ���Ϣ��¼");
        ready_exit_module();
    } else {
        Cou *old_cou = NULL;
        old_cou = cou_Read_File(old_cou);
        printf("\t��ȡ�ɹ�\n");
        printf("������Ҫɾ����ѧ��ѧ�ţ�");
        long long stu_num;
        scanf("%lld", &stu_num);
        printf("������Ҫɾ����γ̵ı�ţ�");
        long class_num;
        scanf("%ld", &class_num);
        system("cls");
        cou_delete(old_cou, class_num, stu_num);
        cou_print(cou_delete2(old_cou, class_num, stu_num));
        ready_exit_module();
    }
}

void get_class() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        printf("û�м�¼");
        ready_exit_module();
    } else {
        Cou *old_cou;
        old_cou = cou_Read_File(old_cou);
        system("cls");
        int class_num;
        printf("�������ѯ�İ༶��:");
        scanf("%d", &class_num);
        class_print(old_cou, class_num);
        ready_exit_module();
    }
}

void get_course() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        printf("û�м�¼");
        ready_exit_module();
    } else {
        Cou *old_cou;
        old_cou = cou_Read_File(old_cou);
        system("cls");
        long num;
        printf("�������ѯ�Ŀγ̴���:");
        scanf("%d", &num);
        course_print(old_cou, num);
        ready_exit_module();
    }
}

void get_student() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        printf("û�м�¼");
        ready_exit_module();
    } else {
        Cou *old_cou = NULL;
        old_cou = cou_Read_File(old_cou);
        system("cls");
        long long stunum;
        printf("�������ѯ��ѧ��ѧ��:");
        scanf("%lld", &stunum);
        get_stu_info(stunum);
        student_print(old_cou, stunum);
        no_pass_print(stunum);
        ready_exit_module();
    }
}

void get_all_stu() {
    system("cls");
    int line_num = getLineNum("student.txt");
    if (line_num < 1) {
        printf("û�м�¼");
        ready_exit_module();
    } else {
        Stu *old_stu = NULL;
        old_stu = stu_Read_File(old_stu);
        printf("��ȡ�ɹ�\n");
        stu_print(old_stu);
        ready_exit_module();
    }
}

void get_all_cou() {
    system("cls");
    int line_num = getLineNum("course.txt");
    if (line_num < 1) {
        printf("û�м�¼");
        ready_exit_module();
    } else {
        Cou *old_cou = NULL;
        old_cou = cou_Read_File(old_cou);
        system("cls");
        cou_print(old_cou);
        ready_exit_module();
    }
}
