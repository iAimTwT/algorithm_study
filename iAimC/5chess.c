#include<stdio.h>
#include <stdlib.h>
#define CHESSBOARD_SIZE 16
int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE]={{0}};
void print_chessboard(int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE])
{
    for(int i=1;i<CHESSBOARD_SIZE;i++)
    {
        chessboard[0][i]='a'+i-1;
        chessboard[i][0]=i;
    }
    printf("  ");
    for(int row=0;row<CHESSBOARD_SIZE;row++)
    {
        for(int column=0;column<CHESSBOARD_SIZE;column++)
        {
            if(row==0&&column>=1)
            {
                printf("%2c",chessboard[0][column]);
            }
            if(row>=1&&column==0)
            {
                printf("%2d ",chessboard[row][0]);
            }
            if(row>0&&column>0)
            {
            if (chessboard[row][column]==1)//白子
            {
                printf("O ");
            }
            else if (chessboard[row][column]==2)//黑子
            {
                printf("X ");
            }
            else if(chessboard[row][column]==0)
            {
                printf(". ");
            }
            }
        }
        printf("\n");
    }
}
void input(int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE])
{
    int row;
    char column;
    int count=0;
    for(int i=0;i<100;i++)
    {
        if(count==0)
        {
            printf("请白子下子：(例如1a)");
            scanf("%d%c",&row,&column);
            chessboard[row][column-96]=1;
            count++;
            print_chessboard(chessboard);
        }
        if(count==1)
        {
            printf("请黑子下子：(例如1a)");
            printf("\n");
            scanf("%d%c",&row,&column);
            chessboard[row][column-96]=2;
            count--;
            print_chessboard(chessboard);
        }
    }
}
void win(int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE])
{
    
}
int main()
{
    print_chessboard(chessboard);
    input(chessboard);
    system("pause");
}