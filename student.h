#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define   STU_MAX_LEN  10
#define   STUSIZE sizeof(struct Student)

typedef struct Student {
    long long num;                   /* ÿ��ѧ����ѧ�� */
    char name[STU_MAX_LEN];          /* ÿ��ѧ�������� */
    int sex;                         /* ÿ��ѧ�����Ա� 1Ϊ�У�0ΪŮ */
    int age;                         /* ÿ��ѧ�������� */
    int dorm;                        /* ÿ��ѧ����������� */
    long long phone;                 /* ÿ��ѧ���ĵ绰���� */
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
            printf("����1��ʼ,�����򱣴��˳�:");
            int n;
            scanf("%d", &n);
            if (n != 1) break;
            system("cls");
            p1 = (Stu *) malloc(STUSIZE);
            printf("������ѧ��ѧ��:");
            scanf("%lld", &p1->num);
            printf("������ѧ������:");
            scanf("%s", p1->name);
            printf("������ѧ���Ա�(1Ϊ��,0ΪŮ):");
            scanf("%d", &p1->sex);
            printf("������ѧ������:");
            scanf("%d", &p1->age);
            printf("������ѧ���������:");
            scanf("%d", &p1->dorm);
            printf("������ѧ���绰����:");
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
        while (NULL != p2->next)  // Ŀ�����ҵ����һ���ڵ㣬���һ���ڵ��pָ��NULL
        {
            p2 = p2->next;
        }
        while (1) {
            printf("����1��ʼ,�����˳�:");
            int n;
            scanf("%d", &n);
            if (n != 1) break;
            system("cls");
            p1 = (Stu *) malloc(STUSIZE);
            printf("������ѧ��ѧ��:");
            scanf("%lld", &p1->num);
            printf("������ѧ������:");
            scanf("%s", p1->name);
            printf("������ѧ���Ա�(1Ϊ��,0ΪŮ):");
            scanf("%d", &p1->sex);
            printf("������ѧ������:");
            scanf("%d", &p1->age);
            printf("������ѧ���������:");
            scanf("%d", &p1->dorm);
            printf("������ѧ���绰����:");
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
        printf("\n��open student.txtʧ��\n");
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
        printf("δ�ҵ���ѧ��\n");
    else
        printf("ɾ���ɹ�\n");
    printf("\n����ɹ�\n");
    fclose(fp);
}


void stu_Write_File(Stu *head) {
    Stu *p;
    p = head;
    FILE *fp;
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("\n��open student.txtʧ��\n");
        return;
    }
    if (head != NULL) {
        do {
            fprintf(fp, "%13lld%12s%2d%3d%5d%13lld\n", p->num, p->name, p->sex, p->age, p->dorm, p->phone);
            p = p->next;
        } while (p != NULL);
    }
    printf("\n����ɹ�\n");
    fclose(fp);
}


Stu *stu_Read_File(Stu *head) {
    Stu *p;
    FILE *fp;
    int i;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("\t��student.txtʧ��\n");
        return NULL;
    }
    int l = getLineNum("student.txt");
    head = stu_creat1(l);  //������һ�����������Ҹ���head
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
        printf("%13s %12s %2s %3s %5s %13s\n", "ѧ��", "����", "�Ա�", "����", "�����", "�ֻ�����");
        do {

            printf("%13lld %12s %2s %3d %5d %13lld\n", p->num, p->name, p->sex == 1 ? "��" : "Ů", p->age, p->dorm,
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
            printf("\n*                 ѧ��������Ϣ               *\n\n");
            printf("������%s,ѧ��:%lld,�Ա�%s,���䣺%d,����ţ�%d,�ֻ���:%lld,\n\n", p->name, p->num, p->sex == 1 ? "��" : "Ů", p->age,
                   p->dorm, p->phone);
        }
        p = p->next;
    }
}
