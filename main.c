#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "module.h"

int menu() {
    printf("                               欢迎进入教务管理系统                              \n");
    printf("******************************************************************************\n");
    printf("功能菜单：\n");
    printf("                1.  录入学生信息\n");
    printf("                2.  录入成绩信息\n");
    printf("                3.  按班级学生选课情况及考试成绩\n");
    printf("                4.  按课程统计学生名单及考试成绩\n");
    printf("                5.  查询学生已修学分及不及格成绩\n");
    printf("                6.  删除学生信息\n");
    printf("                7.  删除成绩信息\n");
    printf("                8.  查看所有学生信息\n");
    printf("                9.  查看所有成绩信息\n");
    printf("                0.  退出\n\n");
    printf("输入你需要的功能编号：");
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
