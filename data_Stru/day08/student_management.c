#include <stdio.h>
#include <stdlib.h>

struct student
{
    char snumber[12];
    char sname[20];
    float chinese;
    float math;
    float english;
    float totalpoints;
}stu[40];

void inputStudent(int n){
    for (int i = 0; i < n; i++)
    {
        printf("请依次输入学生%d的学号,姓名,语文成绩,数学成绩,英语成绩:",i+1);
        scanf("%s %s %f %f %f",&stu[i].snumber,&stu[i].sname,&stu[i].chinese,&stu[i].math,&stu[i].english);
        stu[i].totalpoints = stu[i].chinese + stu[i].math + stu[i].english;
        printf("\n");
    }
}

void printfStudent(int n){
    for (int i = 0; i < n; i++)
    {
        printf("学号:%s\t姓名:%s\t语文:%f\t数学:%f\t英语:%f\t总分:%f\t\n",stu[i].snumber,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].totalpoints);
    }

}

//交换函数
void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

//分割函数
int partition(struct student arr[], int low, int high) {
    int pivot = arr[high].totalpoints;
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j].totalpoints <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

//快速排序单元
void quicksortUnit(struct student arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksortUnit(arr, low, pi - 1);
        quicksortUnit(arr, pi + 1, high);
    }
}

void sortStudent(int n){
    quicksortUnit(stu, 0, n - 1);
    printfStudent(n);
}

void findStudentByNumber(int n, char* number) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stu[i].snumber, number) == 0) {
            printf("找到的学生信息:\n");
            printf("学号:%s\t姓名:%s\t语文:%.2f\t数学:%.2f\t英语:%.2f\t总分:%.2f\n",
                   stu[i].snumber, stu[i].sname, stu[i].chinese, stu[i].math, stu[i].english, stu[i].totalpoints);
            return;
        }
    }
    printf("未找到学号为 %s 的学生\n", number);
}

void findStudentByName(int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stu[i].sname, name) == 0) {
            printf("找到的学生信息:\n");
            printf("学号:%s\t姓名:%s\t语文:%.2f\t数学:%.2f\t英语:%.2f\t总分:%.2f\n",
                   stu[i].snumber, stu[i].sname, stu[i].chinese, stu[i].math, stu[i].english, stu[i].totalpoints);
            return;
        }
    }
    printf("未找到姓名为 %s 的学生\n", name);
}

int main(){
    int n;
    printf("请输入学生数量:");
    scanf("%d",&n);
    inputStudent(n);
    sortStudent(n);

    char searchNumber[12];
    printf("请输入要查找的学生学号:");
    scanf("%s", searchNumber);
    findStudentByNumber(n, searchNumber);

    char searchName[20];
    printf("请输入要查找的学生姓名:");
    scanf("%s", searchName);
    findStudentByName(n, searchName);
    system("pause");
    return 0;
}