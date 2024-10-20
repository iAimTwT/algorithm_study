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

// 合并两个单链表（按递减顺序）
node* merge_linkedlists(node* head1, node* head2) {
    node* merged_head = NULL; // 合并后的链表头指针

    // 依次比较两个链表的元素，将较大者插入到合并后的链表头部
    while (head1 != NULL && head2 != NULL) {
        if (head1->data >= head2->data) {
            node* temp = head1->next;
            head1->next = merged_head;
            merged_head = head1;
            head1 = temp;
        } else {
            node* temp = head2->next;
            head2->next = merged_head;
            merged_head = head2;
            head2 = temp;
        }
    }

    // 将剩余元素插入到合并后的链表头部
    while (head1 != NULL) {
        node* temp = head1->next;
        head1->next = merged_head;
        merged_head = head1;
        head1 = temp;
    }

    while (head2 != NULL) {
        node* temp = head2->next;
        head2->next = merged_head;
        merged_head = head2;
        head2 = temp;
    }

     // 反转合并后的链表
    node* prev = NULL;
    node* current = merged_head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
     return prev; // 返回反转后的链表头指针

}

int main() {
	node* head1 = NULL;
    node* head2 = NULL;
    node* merged_head = NULL;
    int n1, n2;

    printf("请输入第一个链表中元素个数: ");
    scanf("%d", &n1);
    head1 = createlinkedlist(n1);

    printf("请输入第二个链表中元素个数: ");
    scanf("%d", &n2);
    head2 = createlinkedlist(n2);

    printf("\n第一个链表: ");
    outlinkedlist(head1);
    printf("第二个链表: ");
    outlinkedlist(head2);

    merged_head = merge_linkedlists(head1, head2);
    printf("\n合并后的链表: ");
    outlinkedlist(merged_head);

    system("pause");
    return 0;
 }