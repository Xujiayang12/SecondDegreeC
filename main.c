#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "module.h"

int menu() {
    printf("                               ��ӭ����������ϵͳ                              \n");
    printf("******************************************************************************\n");
    printf("���ܲ˵���\n");
    printf("                1.  ¼��ѧ����Ϣ\n");
    printf("                2.  ¼��ɼ���Ϣ\n");
    printf("                3.  ���༶ѧ��ѡ����������Գɼ�\n");
    printf("                4.  ���γ�ͳ��ѧ�����������Գɼ�\n");
    printf("                5.  ��ѯѧ������ѧ�ּ�������ɼ�\n");
    printf("                6.  ɾ��ѧ����Ϣ\n");
    printf("                7.  ɾ���ɼ���Ϣ\n");
    printf("                8.  �鿴����ѧ����Ϣ\n");
    printf("                9.  �鿴���гɼ���Ϣ\n");
    printf("                0.  �˳�\n\n");
    printf("��������Ҫ�Ĺ��ܱ�ţ�");
    int i;
    scanf("%d", &i);
    switch (i) {
        case 0:
            exit(0);
            break;
        case 1:
            take_in_stu();
            menu();
            break;
        case 2:
            take_in_cou();
            menu();
            break;
        case 3:
            get_class();
            menu();
            break;
        case 4:
            get_course();
            menu();
            break;
        case 5:
            get_student();
            menu();
            break;
        case 6:
            delete_stu();
            menu();
            break;
        case 7:
            delete_cou();
            menu();
            break;
        case 8:
            get_all_stu();
            menu();
            break;
        case 9:
            get_all_cou();
            menu();
            break;
    }
}

int main() {
    menu();
    return 10;
}
