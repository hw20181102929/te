#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
struct BinTree
{
    int data;
    struct BinTree * Left;
    struct BinTree * Right;
};
void create(struct BinTree * *BT)
{
    int n;
    scanf("%d",&n);
    if(n!=ERROR)
    {
        (*BT)=(struct BinTree *)malloc(sizeof(struct BinTree));
        (*BT)->data=n;
        create(&((*BT)->Left));
        create(&((*BT)->Right));
    }
}
void Print(struct BinTree * BT,int h)
{
    if(BT)
    {
        Print(BT->Right,h+1);
        for(int i=0;i<h;i++)
        {
            printf("  ");
        }
        printf("%d\n",BT->data);
        Print(BT->Left,h+1);
    }
}
int main()
{
    struct BinTree b,*BT;
    create(&BT);
    Print(BT,1);
    return 0;
}
