#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "student.h"

#define   COU_MAX_LEN  100                       /* 字符串最大长度 */
#define   COUSIZE sizeof(struct Course)

typedef struct Course {
    long num;                        /* 课程编号 */
    char name[COU_MAX_LEN];          /* 课程名称 */
    long long stu_num;               /* 学生学号 */
    int class_num;                   /* 学生班级 */
    int test_grade;                  /* 考试成绩 */
    int usual_grade;                 /* 平时成绩 */
    int final_grade;                 /* 综合成绩 */
    int credit;                      /*  学分   */
    int retake;                      /* 是否重修,重修次数 */
    struct Course *next;
} Cou;


Cou *cou_creat(Cou *head) {
    char course_name[COU_MAX_LEN];
    long course_num;
    int course_credit;
    printf("首先输入课程信息，请输入课程编号:");
    scanf("%ld", &course_num);
    printf("请输入课程名称:");
    scanf("%s", course_name);
    printf("请输入课程学分:");
    scanf("%d", &course_credit);
    printf("现在开始批量录入学生成绩!");
    if (getLineNum("course.txt") < 1) {
        Cou *p1, *p2;
        int i = 1;
        while (1) {
            printf("输入1开始,其他退出:");
            int n;
            scanf("%d", &n);
            if (n != 1) break;
            system("cls");
            p1 = (Cou *) malloc(COUSIZE);
            printf("请输入学生学号:");
            scanf("%lld", &p1->stu_num);
            printf("请输入学生班级:");
            scanf("%d", &p1->class_num);
            printf("请输入学生考试成绩:");
            scanf("%d", &p1->test_grade);
            printf("请输入学生平时成绩:");
            scanf("%d", &p1->usual_grade);
            printf("请输入学生综合成绩:");
            scanf("%d", &p1->final_grade);
            printf("是否重修，若否填0,若是填写重修次数:");
            scanf("%d", &p1->retake);
            p1->num = course_num;
            strcpy(p1->name, course_name);
            p1->credit = course_credit;
            p1->next = NULL;
            if (i == 1) {
                head = p2 = p1;
            } else {
                p2->next = p1;
                p2 = p1;
            }
            i++;
        }
    } else {
        Cou *p1, *p2 = head;
        while (NULL != p2->next)  // 目的是找到最后一个节点，最后一个节点的p指向NULL
        {
            p2 = p2->next;
        }
        while (1) {
            printf("输入1开始,其他退出:");
            int n;
            scanf("%d", &n);
            if (n != 1) break;
            system("cls");
            p1 = (Cou *) malloc(COUSIZE);
            printf("请输入学生学号:");
            scanf("%lld", &p1->stu_num);
            printf("请输入学生班级:");
            scanf("%d", &p1->class_num);
            printf("请输入学生考试成绩:");
            scanf("%d", &p1->test_grade);
            printf("请输入学生平时成绩:");
            scanf("%d", &p1->usual_grade);
            printf("请输入学生综合成绩:");
            scanf("%d", &p1->final_grade);
            printf("是否重修，若否填0,若是填写重修次数:");
            scanf("%d", &p1->retake);
            p1->num = course_num;
            strcpy(p1->name, course_name);
            p1->credit = course_credit;
            p1->next = NULL;
            p2->next = p1;
            p2 = p1;
        }
    }
    return (head);
}

Cou *cou_creat1(int n) {
    Cou *head = NULL;
    Cou *p1, *p2;
    int i;
    for (i = 1; i < n + 1; i++) {
        p1 = (Cou *) malloc(COUSIZE);
        p1->next = NULL;
        if (i == 1) {
            head = p2 = p1;
        } else {
            p2->next = p1;
            p2 = p1;
        }
    }
    return (head);
}

//void cou_delete(Cou *head, long num, long stunum) {
//    Cou *p = head->next;
//    while (p->next != NULL) {
//        if (num == p->next->num && stunum == p->next->stu_num) {
//            p->next = p->next->next;
//            break;
//        }
//        p = p->next;
//        printf("%ld", p->stu_num);
//    }
//}

Cou *cou_delete2(Cou *head, long num, long long stunum) {
    Cou *p;
    p = head;
    if (head->num == num && head->stu_num == stunum)
        return head->next;
    while (p->next != NULL) {
        if (num == p->next->num && stunum == p->next->stu_num) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    return (head);
}

Cou *cou_delete(Cou *head, long num, long long stunum) {
    Cou *p;
    p = head;
    FILE *fp;
    int exist = 0;
    if ((fp = fopen("course.txt", "w")) == NULL) {
        printf("\n打开open course.txt失败\n");
        return 0;
    }
    if (head->next != NULL) {
        do {
            if (p->stu_num == stunum && p->num == num) {
                p = p->next;
                exist = 1;
                continue;
            } else {
                fprintf(fp, "%13ld%50s%13lld%3d%5d%5d%5d%3d%2d\n", p->num, p->name, p->stu_num, p->class_num,
                        p->test_grade,
                        p->usual_grade, p->final_grade, p->credit, p->retake);
                p = p->next;
            }
        } while (p != NULL);
    }
    if (exist == 0)
        printf("未找到要删除的记录\n");
    else
        printf("删除成功\n");
    printf("\n保存成功\n");
    fclose(fp);
}


void cou_Write_File(Cou *head) {
    Cou *p;
    p = head;
    FILE *fp;
    if ((fp = fopen("course.txt", "w")) == NULL) {
        printf("\n打开open course.txt失败\n");
    }
    if (head->next != NULL) {
        do {
            fprintf(fp, "%13ld%50s%13lld%3d%5d%5d%5d%3d%2d\n", p->num, p->name, p->stu_num, p->class_num, p->test_grade,
                    p->usual_grade, p->final_grade, p->credit, p->retake);
            p = p->next;
        } while (p != NULL);
    }
    printf("\n保存成功\n");
    fclose(fp);
}


//int getLineNum(const char *filename) {
//    int c, l = 0;
//    FILE *fp2 = fopen(filename, "r");
//    while ((c = fgetc(fp2)) != EOF) if (c == '\n') l++;
//    fclose(fp2);
//    return l;
//}

Cou *cou_Read_File(Cou *head) {
    Cou *p;
    FILE *fp;
    int i;
    if ((fp = fopen("course.txt", "r")) == NULL) {
        printf("\t打开course.txt失败\n");
        return NULL;
    }
    int l = getLineNum("course.txt");
    head = cou_creat1(l);  //创建了一个空链表，并且赋给head
    p = head;
    for (i = 0; i < l; i++) {
        fscanf(fp, "%13ld", &p->num);
        fscanf(fp, "%50s", p->name);
        fscanf(fp, "%13lld", &p->stu_num);
        fscanf(fp, "%3d", &p->class_num);
        fscanf(fp, "%5d", &p->test_grade);
        fscanf(fp, "%5d", &p->usual_grade);
        fscanf(fp, "%5d", &p->final_grade);
        fscanf(fp, "%5d\n", &p->credit);
        fscanf(fp, "%2d\n", &p->retake);
        p = p->next;

    }
    fclose(fp);
    return head;
}

void cou_print(Cou *head) {
    Cou *p;
    p = head;
    if (head != NULL) {
        printf("\n******************************************************************************\n");
        printf("%13s %12s %13s %3s %5s %5s %5s %3s %5s\n\n", "课程编码", "课程名称", "学生学号", "班级", "考试成绩", "平时成绩", "综合成绩", "学分",
               "是否重修");
        do {

            printf("%13ld %12s %13lld %3d %5d %5d %5d %5d %5d\n", p->num, p->name, p->stu_num, p->class_num,
                   p->test_grade,
                   p->usual_grade, p->final_grade, p->credit, p->retake);
            p = p->next;
        } while (p != NULL);
        printf("\n******************************************************************************\n");
    }
}

void class_print(Cou *head, int class_num) {
    Cou *p;
    p = head;
    if (head != NULL) {
        printf("\n******************************************************************************\n");
        printf("%12s %13s %3s %5s %5s %5s %3s %5s\n\n", "课程名称", "学生学号", "班级", "考试成绩", "平时成绩", "综合成绩", "学分",
               "是否重修");
        do {
            if (p->class_num == class_num) {
                printf("%13s %12s %13lld %3d %5d %5d %5d %5d %5d\n", get_name(p->stu_num), p->name, p->stu_num,
                       p->class_num,
                       p->test_grade,
                       p->usual_grade, p->final_grade, p->credit, p->retake);
                p = p->next;
            } else {
                p = p->next;
            }
        } while (p != NULL);
        printf("\n******************************************************************************\n");
    }
}

void course_print(Cou *head, long num) {
    Cou *p;
    p = head;
    if (head != NULL) {
        printf("\n******************************************************************************\n");
        printf("%13s %12s %13s %3s %5s %5s %5s %3s %5s\n\n", "学生姓名", "课程名称", "学生学号", "班级", "考试成绩", "平时成绩", "综合成绩", "学分",
               "是否重修");
        do {
            if (p->num == num) {
                printf("%13s %12s %13lld %3d %5d %5d %5d %5d %5d\n", get_name(p->stu_num), p->name, p->stu_num,
                       p->class_num,
                       p->test_grade,
                       p->usual_grade, p->final_grade, p->credit, p->retake);
                p = p->next;
            } else {
                p = p->next;
            }
        } while (p != NULL);
        printf("\n******************************************************************************\n");
    }
}

void no_pass_print(long long num) {
    Cou *p;
    Cou *head;
    head = cou_Read_File(p);
    p = head;
    if (head != NULL) {
        printf("不及格课程:\n");
        do {
            if (num == p->stu_num && p->final_grade < 60) {
                printf("名称:%30s 编号:%ld 学分:%d\n", p->name, p->num, p->credit);
                p = p->next;
            } else {
                p = p->next;
            }
        } while (p != NULL);
        printf("\n******************************************************************************\n");
    }
}

void student_print(Cou *head, long long num) {
    Cou *p;
    p = head;
    int had_get_credit = 0;
    if (head != NULL) {
        printf("\n******************************************************************************\n");
        printf("%30s %s %s %s %s %s %s %s\n\n", "课程名称", "学生学号", "班级", "考试成绩", "平时成绩", "综合成绩", "学分",
               "是否重修");
        do {
            if (num == p->stu_num) {
                printf("%30s %13lld %3d %5d %5d %5d %5d %5d\n", p->name, p->stu_num,
                       p->class_num,
                       p->test_grade,
                       p->usual_grade, p->final_grade, p->credit, p->retake);
                int final = p->final_grade;
                if (p->final_grade >= 60) {
                    had_get_credit += p->credit;
                }
                p = p->next;
            } else {
                p = p->next;
            }
        } while (p != NULL);
        printf("\n 已经获得的学分：%d", had_get_credit);
        printf("\n******************************************************************************\n");
    }
}


