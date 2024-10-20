#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;//平衡二叉树使用
} TreeNode;

TreeNode* insert(TreeNode *root, int value) {
    if (root == NULL) {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        if (node == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int totalLength = 0;
int nodeCount = 0;
void calculateTotalLength(TreeNode *root, int depth) {
    if (root != NULL) {
        totalLength += depth;
        nodeCount++;
        calculateTotalLength(root->left, depth + 1);
        calculateTotalLength(root->right, depth + 1);
    }
}
double calculateASL(TreeNode *root) {
    totalLength = 0;
    nodeCount = 0;
    calculateTotalLength(root, 1);  // 从根节点开始，深度为1
    return (nodeCount == 0) ? 0 : (double)totalLength / nodeCount;
}


TreeNode* findMin(TreeNode *root) {
    while (root->left != NULL) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode *root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } 
    else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

TreeNode* search(TreeNode *root, int value) {
    if (root == NULL) {
        printf("无%d\n", value);
        return NULL;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else if (value > root->data) {
        return search(root->right, value);
    } else {
        return root;
    }
}





// 辅助函数：比大小
int max(int a, int b)
{
    return a > b ? a : b;
}

// 辅助函数：计算树的高度
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// 辅助函数：创建新节点
TreeNode *newNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

// 辅助函数：获得节点的平衡因子
int getBalanceFactor(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// 右旋
TreeNode *rightRotate(TreeNode *y)
{
    /* 树结构示意图：
                y
               / \
              x   O
             / \
            O   O
    */
    TreeNode *x = y->left;
    TreeNode *xr = x->right;
    // 旋转
    x->right = y;
    y->left = xr;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

// 左旋
TreeNode *leftRotate(TreeNode *y)
{
    /* 树结构示意图：
                y
               / \
              O   x
                 / \
                O   O
    */
    TreeNode *x = y->right;
    TreeNode *xl = x->left;
    // 旋转
    x->left = y;
    y->right = xl;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

/**
 * @brief 向以node为根节点的树中插入key
 *
 * @param node 根节点
 * @param data 插入值
 * @return TreeNode* 插入后该树的新的根节点
 */
TreeNode *insertAvl(TreeNode *node, int data)
{
    // 1. 按照BST的方法在叶节点上插入新值
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;  // 值已经存在

    // 2. 更新插入路径上每棵子树的高度
    node->height = height(node);

    // 3. 计算平衡因子，不平衡则需要调整
    int bf = getBalanceFactor(node);

    // LL型不平衡
    if (bf > 1 && data < node->left->data)
        return rightRotate(node);
    // RR型不平衡
    if (bf < -1 && data > node->right->data)
        return leftRotate(node);
    // LR型不平衡
    if (bf > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL型不平衡
    if (bf < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // 如果是平衡的直接返回根节点
    return node;
}



int main() {
    TreeNode *root = NULL;
    int value;
    int L[100];
    int i = 0;

    printf("请输入数列L,以回车结束输入:\n");

    while (scanf("%d", &value) == 1) {
        L[i++] = value;
        if (getchar() == '\n') {
            break;
        }
    }

    for (int j = 0; j < i; j++) {
        root = insert(root, L[j]);
    }

    printf("中序遍历结果为：\n");
    inorderTraversal(root);
    printf("\n");

    printf("平均查找长度为：%.2f\n", calculateASL(root));

    printf("请输入要查找和删除的元素x:\n");
    scanf("%d", &value);
    TreeNode *node = search(root, value);
    if (node != NULL) {
        root = deleteNode(root, value);
        printf("删除%d后中序遍历结果为:\n", value);
        inorderTraversal(root);
        printf("\n");
    }
    printf("\n");


    printf("用数列L生成平衡的二叉排序树\n");
    TreeNode *root1 = NULL;
    for (int j = 0; j < i; j++) {
        root1 = insertAvl(root1, L[j]);
    }
    printf("中序遍历结果为：\n");
    inorderTraversal(root1);
    printf("\n");
    printf("平均查找长度为：%.2f\n", calculateASL(root1));

    
    system("pause");
    return 0;
}
