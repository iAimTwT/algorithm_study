#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int n,int x){
    int left = 0;
    int right = n - 1;
    while (left<=right)
    {
        int mid = (left+right)/2;
        if (arr[mid]==x)
        {
            return mid;
        }
        else if (arr[mid]<x)
        {
            left = mid + 1;
        }
        else if (arr[mid]>x)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[]={0,12,13,15,17,25,26,40,50,57,60,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    printf("输入要查找的值:");
    scanf("%d",&x);

    int result = binarySearch(arr,n,x);
    if (result != -1)
    {
        printf("%d数在表中的位置为%d\n",x,result);
    }
    else{
        printf("表中没有该元素\n");
    }
    
    system("pause");
    return 0;
}
