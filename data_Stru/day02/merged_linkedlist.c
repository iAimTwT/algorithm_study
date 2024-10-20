#include<stdio.h>
#include<stdlib.h>

//定义单链表
typedef struct node
{
    int data;
    struct node *next;

}Node;

//尾插法
Node* createLinkedList(int n){
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp = NULL;

    for(int i = 0; i < n; i++) {
        // 分配内存空间并为节点赋值
        temp = (Node*)malloc(sizeof(Node));
        printf("输入第%d个元素的值: ", i+1);
        int value;
        scanf("%d", &value);
        temp->data = value;
        temp->next = NULL;  // 将新节点的下一个节点指向NULL

        // 如果链表为空，则将新节点设为头节点
        if(head == NULL) {
            head = temp;
            tail = temp;
        } else {
            // 否则，将新节点连接到尾部，并更新尾指针
            tail->next = temp;
            tail = temp;
        }
    }
    return head;// 返回链表的头指针
}


//显示链表
void displayLinkedList(Node *head){
    Node *p = head;
    printf("链表元素为: ");
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

// 合并两个递减有序链表
Node* mergeDescending(Node *a, Node *b) {
    Node *result = NULL;
    Node *current = NULL;

    while (a != NULL && b != NULL) {
        if (a->data >= b->data) { 
            if (result == NULL) {
                result = a;
                current = result;
            } else {
                current->next = a;
                current = current->next;
            }
            a = a->next;
        } else {
            if (result == NULL) {
                result = b;
                current = result;
            } else {
                current->next = b;
                current = current->next;
            }
            b = b->next;
        }
    }

    // 处理剩余部分
    if (a != NULL) {
        current->next = a;
    }
    if (b != NULL) {
        current->next = b;
    }

    return result;
}


//测试程序
void test_linkedlist(){
    Node *listA = NULL;
    Node *listB = NULL;

    // 输入链表A
    int n;
    printf("输入链表A中元素个数:");
    scanf("%d", &n);
    listA = createLinkedList(n);

    // 输入链表B
    printf("输入链表B中元素个数:");
    scanf("%d", &n);
    listB = createLinkedList(n);

    //输出链表A,B
    printf("List A");
    displayLinkedList(listA);
    printf("List B");
    displayLinkedList(listB);

    // 合并链表A和链表B
    Node *mergedList = mergeDescending(listA, listB);

    // 输出链表C
    printf("Merged List C");
    displayLinkedList(mergedList);

    // 释放链表节点的内存
    Node *current = mergedList;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    system("pause");
}

int main()
{
    test_linkedlist();
    return 0;
}
