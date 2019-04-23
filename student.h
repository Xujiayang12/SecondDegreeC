#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define   STU_MAX_LEN  10
#define   STUSIZE sizeof(struct Student)

typedef struct Student {
    long long num;                   /* 每个学生的学号 */
    char name[STU_MAX_LEN];          /* 每个学生的姓名 */
    int sex;                         /* 每个学生的性别 1为男，0为女 */
    int age;                         /* 每个学生的年龄 */
    int dorm;                        /* 每个学生的宿舍号码 */
    long long phone;                 /* 每个学生的电话号码 */
    struct Student *next;
} Stu;

int getLineNum(const char *filename) {
    int c, l = 0;
    FILE *fp2 = fopen(filename, "r");
    while ((c = fgetc(fp2)) != EOF) if (c == '\n') l++;
    fclose(fp2);
    return l;
}

Stu *stu_creat(Stu *head) {
    if (getLineNum("student.txt") < 1) {
        Stu *p1, *p2 = NULL;
        int i = 1;
        while (1) {
            printf("输入1开始,其他则保存退出:");
            int n;
            scanf("%d", &n);
            if (n != 1) break;
            system("cls");
            p1 = (Stu *) malloc(STUSIZE);
            printf("请输入学生学号:");
            scanf("%lld", &p1->num);
            printf("请输入学生姓名:");
            scanf("%s", p1->name);
            printf("请输入学生性别(1为男,0为女):");
            scanf("%d", &p1->sex);
            printf("请输入学生年龄:");
            scanf("%d", &p1->age);
            printf("请输入学生宿舍号码:");
            scanf("%d", &p1->dorm);
            printf("请输入学生电话号码:");
            scanf("%lld", &p1->phone);
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
        Stu *p1, *p2 = head;
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
            p1 = (Stu *) malloc(STUSIZE);
            printf("请输入学生学号:");
            scanf("%lld", &p1->num);
            printf("请输入学生姓名:");
            scanf("%s", p1->name);
            printf("请输入学生性别(1为男,0为女):");
            scanf("%d", &p1->sex);
            printf("请输入学生年龄:");
            scanf("%d", &p1->age);
            printf("请输入学生宿舍号码:");
            scanf("%d", &p1->dorm);
            printf("请输入学生电话号码:");
            scanf("%lld", &p1->phone);
            p1->next = NULL;
            p2->next = p1;
            p2 = p1;
        }
    }
    return (head);
}

Stu *stu_creat1(int n) {
    Stu *head = NULL;
    Stu *p1, *p2;
    int i;
    for (i = 1; i < n + 1; i++) {
        p1 = (Stu *) malloc(STUSIZE);
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

Stu *stu_delete2(Stu *head, long long num) {
    Stu *p;
    p = head;
    if (head->num == num)
        return head->next;
    while (p->next != NULL) {
        if (num == p->next->num) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    return (head);
}

void stu_delete(Stu *head, long long num) {
    Stu *p;
    p = head;
    FILE *fp;
    int exist = 0;
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("\n打开open student.txt失败\n");
    }
    if (head != NULL) {
        do {
            if (p->num == num) {
                p = p->next;
                exist = 1;
                continue;
            } else {
                fprintf(fp, "%13lld%12s%2d%3d%5d%13lld\n", p->num, p->name, p->sex, p->age, p->dorm, p->phone);
                p = p->next;
            }
        } while (p != NULL);
    }
    if (exist == 0)
        printf("未找到该学生\n");
    else
        printf("删除成功\n");
    printf("\n保存成功\n");
    fclose(fp);
}


void stu_Write_File(Stu *head) {
    Stu *p;
    p = head;
    FILE *fp;
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("\n打开open student.txt失败\n");
        return;
    }
    if (head != NULL) {
        do {
            fprintf(fp, "%13lld%12s%2d%3d%5d%13lld\n", p->num, p->name, p->sex, p->age, p->dorm, p->phone);
            p = p->next;
        } while (p != NULL);
    }
    printf("\n保存成功\n");
    fclose(fp);
}


Stu *stu_Read_File(Stu *head) {
    Stu *p;
    FILE *fp;
    int i;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("\t打开student.txt失败\n");
        return NULL;
    }
    int l = getLineNum("student.txt");
    head = stu_creat1(l);  //创建了一个空链表，并且赋给head
    p = head;
    for (i = 0; i < l; i++) {
        fscanf(fp, "%13lld", &p->num);
        fscanf(fp, "%12s", p->name);
        fscanf(fp, "%2d", &p->sex);
        fscanf(fp, "%3d", &p->age);
        fscanf(fp, "%5d", &p->dorm);
        fscanf(fp, "%13lld\n", &p->phone);
        p = p->next;

    }
    fclose(fp);
    return head;
}

void stu_print(Stu *head) {
    Stu *p;
    p = head;
    if (head != NULL) {
        printf("\n******************************************************************************\n");
        printf("%13s %12s %2s %3s %5s %13s\n", "学号", "姓名", "性别", "年龄", "宿舍号", "手机号码");
        do {

            printf("%13lld %12s %2s %3d %5d %13lld\n", p->num, p->name, p->sex == 1 ? "男" : "女", p->age, p->dorm,
                   p->phone);
            p = p->next;
        } while (p != NULL);
        printf("\n******************************************************************************\n");
    }
}


char *get_name(long long stu_num) {
    Stu *p = NULL;
    p = stu_Read_File(p);
    while (p != NULL) {
        if (stu_num == p->num) {
            return p->name;
        }
        p = p->next;
    }
}

void get_stu_info(long long stu_num) {
    Stu *p = NULL;
    p = stu_Read_File(p);
    while (p != NULL) {
        if (stu_num == p->num) {
            printf("\n*                 学生基本信息               *\n\n");
            printf("姓名：%s,学号:%lld,性别：%s,年龄：%d,宿舍号：%d,手机号:%lld,\n\n", p->name, p->num, p->sex == 1 ? "男" : "女", p->age,
                   p->dorm, p->phone);
        }
        p = p->next;
    }
}
