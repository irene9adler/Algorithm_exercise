//复习 根据前序中序遍历得到后续遍历
#include <stdio.h>

struct node
{
    node * lchild,* rchild;
    int c;
}tree[100];

typedef struct node node;
int loc;

node * create()
{
    tree[loc]->rchild = tree[loc]->lchild = NULL;
    return &tree[loc++];
}

void postOrder(node * T)
{
    if(T->rchild) postOrder(T->lchild);
    if(T->lchild) postOrder(T->rchild);
    printf("%d\n",T->c);
}

char str1[100];
char str2[100];
node * paixushu(int s1,int e1,int s2,int e2)//根据前序中序遍历构造二叉排序(?)树
{
    node * tmp = create();
    tmp->c = str1[s1];
    int rootindex;
    for(rootindex = s2;rootindex <= e2; rootindex++)
    {
        if(str2[rootindex] == tmp->c)
        {
            break;
        }
    }
    if(rootindex != s2)//有左子树
       paixushu(s1 + 1,s1 + rootindex - s2,s2,rootindex - 1);
    if(rootindex != e2)
       paixushu(s1 + rootindex - s2 + 1,e1,rootindex + 1,e2);
}
int main()
{
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        int l1 = strlen(str1);
        int l2 = strlen(str2);
        node * root = paixushu(0,l1 - 1,0,l2 - 1);
        postOrder(root);
    }
    return 0;
}
