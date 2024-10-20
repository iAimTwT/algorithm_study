#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAXSIZE 13

typedef struct
{
    int key;
    int occupation;
}HashTable;

void initHashTable(HashTable table[]){
    for(int i =0;i<TABLE_MAXSIZE;i++){
        table[i].occupation=0;
    }
}

int hashFunction(int key){
    return key % TABLE_MAXSIZE;
}

void insert(HashTable table[],int key){
    int hashIndex =hashFunction(key);
    while (table[hashIndex].occupation)
    {
        hashIndex = hashIndex + 1;
        if (hashIndex==TABLE_MAXSIZE-1)
        {
            hashIndex = hashIndex - 1;
        }
        
    }
    table[hashIndex].key = key;
    table[hashIndex].occupation = 1;
}

void printHashTable(HashTable table[]){
    for(int i= 0;i<TABLE_MAXSIZE;i++){
        if(table[i].occupation == 1){
            printf("第%d个元素的值为:%d\n",i,table[i].key);
        }
        else{
            printf("NULL\n");
        }
    }
}

int main(){
    HashTable table[TABLE_MAXSIZE];
    initHashTable(table);

    int keys[]={19,01,23,14,55,20,84,27,68,11};
    for(int i = 0;i<sizeof(keys) / sizeof(keys[0]);i++){
        insert(table,keys[i]);
    }

    printHashTable(table);


    system("pause");
    return 0;
}



