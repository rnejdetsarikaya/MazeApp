#include <stdio.h>
#include <stdlib.h>
int boyut;
int x2,y2;
struct n
{
    int data;
    int xKor;
    int yKor;
    struct n * next;
};
typedef struct n   node;
node * yol=NULL;
node* ilk;
node* a=NULL;
node* b= NULL;
node * push(node * root,int x)
{
    if(root==NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data=x;
        root->next=NULL;
        return root;
    }
    node * iter=root;
    while(iter->next !=NULL)
    {
        iter=iter->next;
    }
    node * gecici = (node*)malloc(sizeof(node));
    gecici->data=x;
    gecici->next=NULL;
    iter->next=gecici;
    return root;
}
int pop(node * root)
{
    if(root==NULL)
    {
        printf("Dügüm bos!!");
        return -1;
    }
    if(root->next==NULL)
    {
        int a=root->data;
        free(root);
        return a;
    }
    node* iter=root;
    while(iter->next->next!=NULL)
    {
        iter=iter->next;
    }
    node* gecici=iter->next;
    int a=gecici->data;
     iter->next=NULL;
    free(gecici);

    return a;
}
void cikar(node * root,int m[][boyut])
{
    if(root==NULL)
    {
        printf("Dügüm bos!!");
        //return -1;
    }
    if(root->next==NULL)
    {
        //int a=root->xKor;
        free(root);
        //return a;
    }
    node* iter=root;
    while(iter->next->next!=NULL)
    {
        iter=iter->next;
    }
    node* gecici=iter->next;
   // int a=gecici->data;
     iter->next=NULL;
    free(gecici);
coz(m,iter->xKor,iter->yKor);
   // return a;
}
node* ekle(node * root,int x,int y)
{
    if(root==NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->xKor=x;
        root->yKor=y;
        root->next=NULL;
        return root;
       // printf("%d",root->x);
    }
    node * iter=root;
    while(iter->next !=NULL)
    {
        iter=iter->next;
    }

    node * gecici = (node*)malloc(sizeof(node));
    gecici->xKor=x;
    gecici->yKor=y;
    gecici->next=NULL;
    iter->next=gecici;
    return root;
}
void yaz(node * root)
{
    while(root != NULL)
    {
        printf("%d ",root->data);
        root=root->next;
    }
}
int ctrl(int m[][boyut],int x,int y)
{
    if(x<0 || x>boyut || y<0 || y>boyut)
        return 0;
    return m[x][y];
}
  int muhtemelYol;
int yolBul(int m[][boyut],int *x,int *y)
{
   m[*x][*y]=2;
 muhtemelYol=0;

   if(ctrl(m,*x,*y-1)==1) muhtemelYol++; ///sola
   if(ctrl(m,*x,*y+1)==1) muhtemelYol++; ///saða
   if(ctrl(m,*x+1,*y)==1) muhtemelYol++; /// aþaðý
    if(ctrl(m,*x-1,*y)==1) muhtemelYol++;  ///yukarý

    if (muhtemelYol==0)
    {return 0;}
if(ctrl(m,*x,*y-1)==1) *y=*y-1; ///sola git
   else if(ctrl(m,*x,*y+1)==1) *y=*y+1; /// saða git
   else if(ctrl(m,*x+1,*y)==1)*x=*x+1;  ///aþaðý git
    else if(ctrl(m,*x-1,*y)==1) *x=*x-1;  /// yukarý git

 if (*x == x2 && *y == y2)
{   m[*x][*y]=2;
yol=ekle(yol,x2,y2);
    return 2;}

 return 1;
}
void coz(int m[][boyut],int x,int y)
{

    int basarili=0;
    switch (yolBul(m,&x,&y))
    {
        case 0:
        if(yol != NULL)
        {
        cikar(yol,m);
        } break;
    case 1:
        yol=ekle(yol,x,y);
      coz(m,x,y);
    basarili =1;
            break;
    case 2:
        printf("Basarili!!");
        basarili=1;
        break;
            }
      if(basarili==0)
      printf("Yol Yok");

}
int main()
{
   int i,j,x1,y1;
    printf("Labirent boyutunu giriniz: \n");
    scanf("%d",&boyut);
   //boyut=4;
 int d[boyut][boyut];
    srand(time(NULL));
     for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            d[i][j]=rand()%2;
        }
    }
  /*int d[4][4]={      { 1,1,0,0 },
                     { 0,1,1,0 },
                     { 1,0,1,1 },
                     { 1,0,1,1 }};*/
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    printf("Baslangic kordinatlarini giriniz: ");
    scanf("%d %d",&x1,&y1);
    printf("\nCikis kordinatlarini giriniz: ");
    scanf("%d %d",&x2,&y2);
 yol=ekle(yol,x1,y1);
ilk=yol;
coz(d,x1,y1);
node * iter=ilk;
printf("\n");
for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
while(ilk != NULL)
{
    printf("(%d,%d) ",ilk->xKor,ilk->yKor);
    ilk=ilk->next;
}
    return 0;
}
