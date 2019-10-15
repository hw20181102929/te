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
void print(struct BinTree * BT,int h)
{
    if(BT)
    {
        print(BT->Right,h+1);
        for(int i=0;i<h;i++)
        {
            printf("  ");
        }
        printf("%d\n",BT->data);
        print(BT->Left,h+1);
    }
}
int main()
{
    struct BinTree b,*BT;
    BT=&b;
    create(&BT);
    print(BT,1);
    return 0;
}
