//复习 判断两棵二叉排序树是否完全相同 连接两个数的前序中序遍历连接的字符串是否完全相同
#include <stdio.h>

struct node
{
    node * lchild, * rchild;
    int c;
}tree[100];//数组表示一棵树

//创建空树
typedef struct node node;
int loc;
node * create()
{
   tree[loc].lchild = tree[loc].rchild = NULL;
   return &tree[loc++];
}
//前序遍历
char str[100];
char str1[200];
char str2[200];
int * l;
int l1,l2;

void preOrder(node * T)
{
    str[*(l++)] = T.c+ '0';
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void midOrder(node * T)
{
    preOrder(T->lchild);
    str[*(l++)] = T.c + '0';
    preOrder(T->rchild);
}

//构建二叉排序树
node * paixushu(node * T,int x)
{
    if(T == NULL)
    {
        T = create();
        T->c = x;
    }
    else if(x < T->c) paixushu(T->lchild,x);
    else if(x > T->c) paixushu(T->rchild,x);//写两个else if x = T->c的情况就被略过了
}

int main()
{
    int n;//一棵树要和几棵树比
    while(scanf("%d",&n)!=EOF)
    {
        char input[100];
        loc = 0;
        scanf("%s",input);
        //建一棵二叉排序树
        node * tmp = create();//tnp == NULL?
        int len = strlen(input);
        int i;
        for(i = 0;i < len;i++)
        {
            tmp = paixushu(tmp,input[i] - '0');
        }
        //得到str1 高能
        str = str1;
        l = &l1;
        preOrder(tmp);
        midOrder(tmp);
        for(i = 0;i < n;i++)
        {
            scanf("%s",input);
            loc = 0;
            node * tmp2 = create();//tmp2 == NULL?
            len = strlen(input);
            for(i = 0;i < len;i++)
            {
                tmp2 = paixushu(tmp2,input[i] - '0');
            }
            str= str2;
            l = & l2;
            preOrder(tmp2);
            midOrder(tmp2);
            if(strcmp(str1,str2) == 0)
            {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}
