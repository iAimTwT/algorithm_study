#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生信息结构体
struct student {
    char xuehao[12];        // 学号
    char xingming[20];      // 姓名
    float yuwen;            // 语文成绩
    float shuxue;           // 数学成绩
    float yingyu;           // 英语成绩
    float zongfen;          // 总分
    struct student *next;   // 指向下一个学生的指针
};


// 输入学生信息
void inputStudentInfo(struct student **head) {
    struct student *newStudent = (struct student*)malloc(sizeof(struct student));

    printf("请输入学号: ");
    scanf("%s", newStudent->xuehao);
    printf("请输入姓名: ");
    scanf("%s", newStudent->xingming);
    printf("请输入语文成绩: ");
    scanf("%f", &newStudent->yuwen);
    printf("请输入数学成绩: ");
    scanf("%f", &newStudent->shuxue);
    printf("请输入英语成绩: ");
    scanf("%f", &newStudent->yingyu);

    newStudent->next = *head;
    *head = newStudent;
}

// 计算总分
void calculateTotalScores(struct student *head) {
    struct student *current = head;
    while (current != NULL) {
        current->zongfen = current->yuwen + current->shuxue + current->yingyu;
        current = current->next;
    }
}

// 冒泡排序按总分排序，并输出全部学生信息
void sortStudentsByTotalScore(struct student **head) {
    if (*head == NULL) return;

    int swapped;
    struct student *ptr1;
    struct student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->zongfen < ptr1->next->zongfen) {
                // 交换数据
                char tempXuehao[12];
                char tempXingming[20];
                float tempYuwen, tempShuxue, tempYingyu, tempZongfen;

                strcpy(tempXuehao, ptr1->xuehao);
                strcpy(ptr1->xuehao, ptr1->next->xuehao);
                strcpy(ptr1->next->xuehao, tempXuehao);

                strcpy(tempXingming, ptr1->xingming);
                strcpy(ptr1->xingming, ptr1->next->xingming);
                strcpy(ptr1->next->xingming, tempXingming);

                tempYuwen = ptr1->yuwen;
                ptr1->yuwen = ptr1->next->yuwen;
                ptr1->next->yuwen = tempYuwen;

                tempShuxue = ptr1->shuxue;
                ptr1->shuxue = ptr1->next->shuxue;
                ptr1->next->shuxue = tempShuxue;

                tempYingyu = ptr1->yingyu;
                ptr1->yingyu = ptr1->next->yingyu;
                ptr1->next->yingyu = tempYingyu;

                tempZongfen = ptr1->zongfen;
                ptr1->zongfen = ptr1->next->zongfen;
                ptr1->next->zongfen = tempZongfen;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    // 输出全部学生信息
    struct student *current = *head;
    while (current != NULL) {
        printStudentInfo(current);
        current = current->next;
    }
}


// 按学号查找学生
struct student* searchStudentById(struct student *head, const char *id) {
    struct student *current = head;
    while (current != NULL) {
        if (strcmp(current->xuehao, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 按姓名查找学生
struct student* searchStudentByName(struct student *head, const char *name) {
    struct student *current = head;
    while (current != NULL) {
        if (strcmp(current->xingming, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 打印学生信息
void printStudentInfo(struct student *student) {
    if (student == NULL) {
        printf("学生信息为空\n");
        return;
    }

    printf("学号: %s\n", student->xuehao);
    printf("姓名: %s\n", student->xingming);
    printf("语文成绩: %.2f\n", student->yuwen);
    printf("数学成绩: %.2f\n", student->shuxue);
    printf("英语成绩: %.2f\n", student->yingyu);
    printf("总分: %.2f\n", student->zongfen);
}

// 释放链表
void freeList(struct student *head) {
    struct student *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct student *head = NULL;
    int choice;
    char id[12];
    char name[20];

    while (1) {
        printf("\n1. 输入学生信息\n");
        printf("2. 按总分排序\n");
        printf("3. 按学号查找\n");
        printf("4. 按姓名查找\n");
        printf("5. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudentInfo(&head);
                break;
            case 2:
                calculateTotalScores(head);
                sortStudentsByTotalScore(&head);
                printf("学生信息已按总分排序\n");
                break;
            case 3:
                printf("请输入要查找的学号: ");
                scanf("%s", id);
                struct student *studentById = searchStudentById(head, id);
                if (studentById) {
                    printStudentInfo(studentById);
                } else {
                    printf("未找到该学号的学生\n");
                }
                break;
            case 4:
                printf("请输入要查找的姓名: ");
                scanf("%s", name);
                struct student *studentByName = searchStudentByName(head, name);
                if (studentByName) {
                    printStudentInfo(studentByName);
                } else {
                    printf("未找到该姓名的学生\n");
                }
                break;
            case 5:
                freeList(head);
                return 0;
            default:
                printf("无效选择，请重新选择\n");
        }
    }

    return 0;
}