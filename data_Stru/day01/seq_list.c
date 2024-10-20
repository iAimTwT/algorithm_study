#include <stdio.h>
#include<stdlib.h>

// #define INITSIZE 100
// #define INCREMENT 10


//定义顺序表结构体
typedef struct
{
    int *data;
    int length;
    // int listsize;
}seq_list;

//初始化顺序表
int initseqlist(seq_list *L){
    // L->data=(int*)malloc(INCREMENT*sizeof(int));
    L->data=(int*)malloc(sizeof(int));
    if(L->data==NULL)
    {
        return 0;
        printf("error");
    }
    L->length = 0;
    return 1;
}

//向顺序表中输入元素
void inputlist(seq_list *L,int n){
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        L->data[i]=a;
    }
}

//输出顺序表
void outputlist(seq_list *L){
    int i;
    printf("顺序表中的元素为:");
    for(i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//使用插入排序对顺序表排序
void insertSort(seq_list *L) {
    for (int i = 1; i < L->length; i++) {
        int temp = L->data[i]; // 从未排序部分取出一个元素
        int j = i - 1;
        // 在已排序部分找到合适的位置插入
        while (j >= 0 && L->data[j] > temp) {
            L->data[j + 1] = L->data[j];
            j--;
        }
        L->data[j + 1] = temp;
    }
    outputlist(L);
}


//按顺序插入顺序表
int insertlist(seq_list *L,int x){
    int index=0;
    L->length++;
    while(index < L->length &&x>=L->data[index]){//待解决：index为0,已解决,判断条件错误
        index++;
    }
     for (int i = L->length; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index]=x;
    outputlist(L);
}

//查询元素位置
int querylist(seq_list *L,int y){
    int index=-1;
    for(int i=0;i<=L->length;i++){
        if(L->data[i]==y){
            index=i;
            break;
        }
    }
    if (index==-1)
    {
        return -1;
    }
    else return index;
}

//删除顺序表中元素
int deletelist(seq_list *L,int i){
    for(int index=i;index<L->length;index++){
        L->data[index] = L->data[index+1];
    }
    L->length--;
    outputlist(L);
}

//测试程序
void test_seqlist(){
    seq_list L;
    initseqlist(&L);
    int n,x,y,del;

    printf("请输入顺序表中元素的个数:");
    scanf("%d",&n);
    L.length = n;
    
    printf("向顺序表中输入%d个整数:",n);
    inputlist(&L,n);
    
    insertSort(&L);
   

    printf("输入要插入的数字:");
    scanf("%d",&x);
    insertlist(&L,x);
    

    printf("输入要查找的数字:");
    scanf("%d",&y);
    printf("在顺序表中的位置为(-1则不存在):%d\n",querylist(&L,y));

    printf("输入要删除顺序表中第几个元素：");
    scanf("%d",&del);
    deletelist(&L,del);
    

    system("pause");
}

int main(){
    test_seqlist();
    return 0;
    system("pause");
}