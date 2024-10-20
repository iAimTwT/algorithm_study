#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}node;

//创建单链表
node* createlinkedlist(int n) {
	node* head = NULL;
	node* temp = NULL;

	for (int i = 0; i < n; i++) {
		temp = (node*)malloc(sizeof(node));
		printf("输入第%d个元素的值", n - i );
		scanf_s("%d", &(temp->data));
		temp->next = head;
		head = temp;
	}
	return head;
}

//输出单链表
void outlinkedlist(node *head) {
	node *count = head;
	while (count != NULL) {
		printf("%d", count->data);
		count = count->next;
	}
	printf("\n");
}

//删除结点
node* dellinkedlist(node *head,int i){
	node *prv = head;
	node* current = head->next; // 指向要删除的节点
	
	if(i == 1){
		head = head->next;
		return head;
	}

	int index = 2;
	while (current != NULL) {
        if (index == i) { // 找到要删除的节点
            prv->next = current->next; // 修改前一个节点的指针跳过当前节点
            free(current); // 释放当前节点的内存
            return head;
        }
        prv = current; // 更新前一个节点
        current = current->next; // 更新当前节点
        index++; // 更新计数器
    }
	return head;
}

//删除值结点
node *delnodewithvalue(node *head,int y){
	node *prv = NULL;
	node* current = head; 
	
	while (current != NULL) {
        if (current->data == y) {
            if (prv == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prv->next = current->next;
                free(current);
                current = prv->next;
            }
        } else {
            prv = current;
            current = current->next;
        }
    }
    return head;
}

//插入元素
node *insertlist(node *head,int index,int x){
	node *current = head;
	node *prv = NULL;
	node *temp = NULL;


	temp = (node *)malloc(sizeof(node));
	temp->data = x;

	if(index == 1){
		temp->next = head;
		head = temp;
		return head;
	}

	int count = 1;
	while (current != NULL && count < index)
	{
		prv = current;
		current = current->next;
		count++;
	}
	
	temp->next = current;
	prv->next = temp;
	return head;
}

//求链表长度
int lengthoflist(node *head){
	int length = 0;
	node *p = head;
	while (p!=NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

//返回x的地址
node *addressofX(node *head,int value){
	node *current = head;
	while (current != NULL)
	{
		if(current->data == value){
			return current;
		}
		current = current->next;
	}
	return NULL;
}


 int main() {
	 node* head = NULL;
	 int n,i,y,index,x,value;

	 printf("请输入链表中元素个数:");
	 scanf_s("%d", &n);
	 head = createlinkedlist(n);
	 outlinkedlist(head);

	 printf("输入要删除元素的位置:");
	 scanf_s("%d",&i);
	 head = dellinkedlist(head,i);	
	 outlinkedlist(head);


	 printf("请输入要删除的值:");
	 scanf_s("%d",&y);
	 head = delnodewithvalue(head,y);
	 outlinkedlist(head);

	 
	 printf("请输入要插入的位置和值:");
	 scanf_s("%d %d",&index,&x);
	 head = insertlist(head,index,x);
	 outlinkedlist(head);
	 
	 printf("链表长度为:%d\n",lengthoflist(head));

	 printf("输入要查找的值:");
	 scanf_s("%d",&value);
	 printf("该值的地址为:%d",addressofX(head,value));
	 
	 system("pause");
 }