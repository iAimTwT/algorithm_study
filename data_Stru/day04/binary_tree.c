#include <stdio.h>
#include <stdlib.h>

//二叉树定义
typedef struct 
{
    char data;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

//创建
BinaryTree* createTree(){
    char value;
    scanf(" %c",&value);

    if(value == '#'){
        return NULL;
    }

    BinaryTree* newNode = (BinaryTree*)malloc(sizeof(BinaryTree));
    newNode->data = value;
    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

//先序
void preOrderTraversal(BinaryTree* root){
    if(root == NULL){
        return;
    }
    printf("%c",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//中序
void inOrderTraversal(BinaryTree *root){
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%c",root->data);
    inOrderTraversal(root->right);
}

//后序
void bottomOrderTraversal(BinaryTree *root){
    if (root == NULL) {
        return;
    }
    bottomOrderTraversal(root->left);
    bottomOrderTraversal(root->right);
    printf("%c",root->data);
}

//层序遍历
void gradationOrderTraversal(BinaryTree *root){
     if (root == NULL) {
        return;
    }

    BinaryTree* queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        BinaryTree* currentNode = queue[front++];
        printf("%c", currentNode->data);

        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}

int main(){
    printf("请输入二叉树节点字符（使用#表示空节点）：\n");
    BinaryTree *root = NULL;

    root = createTree();
    
    printf("先序遍历结果：");
    preOrderTraversal(root);
    printf("\n");

    printf("中序遍历结果：");
    inOrderTraversal(root);
    printf("\n");

    printf("后序遍历结果：");
    bottomOrderTraversal(root);
    printf("\n");

    printf("按层遍历结果：");
    gradationOrderTraversal(root);
    printf("\n");

    system("pause");
    return 0;
}