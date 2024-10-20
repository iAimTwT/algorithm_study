#include<stdio.h>
#include<stdlib.h>

//定义单链表
typedef struct node
{
    int data;
    struct node *next;

}Node;


//创建单链表(头插法)
Node* createlist_fromhead(int n){
    Node *head = NULL;
    Node *temp = NULL;

    for(int i = 0; i < n; i++) {
        // 分配内存空间并为节点赋值
        temp = (Node*)malloc(sizeof(Node));
        printf("输入第%d个元素的值: ", i+1);
        int value;
        scanf("%d", &value);
        temp->data = value;
        temp->next = head;  // 将新节点的下一个节点指向当前头节点

        head = temp;// 将新节点设为头节点
    }
    return head;// 返回链表的头指针
}

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

//删除节点
Node *deleteNode(Node *head,int index){
    Node *temp = head;
    Node *prev = NULL;

    if(index == 1){
        head = head->next;
        free(temp);
        return head;
    }


    for(int i = 1;i < index && temp !=NULL ;i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("索引超出链表范围!\n");
        return head;
    }
    
    prev->next = temp->next;
    free(temp);
    return head;
}

//删除固定值节点
Node *deleteNodeWithValue(Node *head,int value){
    Node *temp = head;
    Node *prev = NULL;
    if(temp!= NULL && temp->data == value){
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("找不到该值\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

//插入元素
Node *insertNode(Node *head,int index,int x){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if(index == 1){
        temp->next = head;
        head = temp;
        return head;
    }
    
    Node *prev = head;
    for (int i = 1; i < index - 1 && prev != NULL; i++){
        prev = prev->next;
    }
    
    if(prev == NULL){
        printf("插入位置超出链表范围!\n");
        return head;
    }
    
    temp->next = prev->next;
    prev->next = temp;
    return head;

}

//求链表长度
int getLinkedListLength(Node *head){
    Node *p = head;
    int count=0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

//查找元素并返回地址
Node *searchNode(Node *head,int value){
    Node * p = head;
    while (p != NULL)
    {
        if(p->data == value){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//测试函数
void test_list(){
    int n,delnum,value,index,x;
    Node *head;

    printf("该链表中元素的个数为多少:");
    scanf("%d",&n);
    head = createLinkedList(n);
    displayLinkedList(head);
    
    printf("要删除第几个元素:");
    scanf("%d",&delnum);
    head = deleteNode(head,delnum);
    displayLinkedList(head);

    printf("输入要删除的值:");
    scanf("%d",&value);
    head = deleteNodeWithValue(head,value);
    displayLinkedList(head);

    printf("输入要插入的值和位置(用空格隔开):");
    scanf("%d %d",&x,&index);
    head =insertNode(head,index,x);
    displayLinkedList(head);

    printf("链表长度为:%d\n",getLinkedListLength(head));

    printf("输入要查找的值:");
    scanf("%d",&value);
    printf("地址为:%d",searchNode(head,value));

    system("pause");
}

int main(){
    test_list();
    
    return 0;
}