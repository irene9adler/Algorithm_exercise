//��ϰ �ж����ö����������Ƿ���ȫ��ͬ ������������ǰ������������ӵ��ַ����Ƿ���ȫ��ͬ
#include <stdio.h>

struct node
{
    node * lchild, * rchild;
    int c;
}tree[100];//�����ʾһ����

//��������
typedef struct node node;
int loc;
node * create()
{
   tree[loc].lchild = tree[loc].rchild = NULL;
   return &tree[loc++];
}
//ǰ�����
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

//��������������
node * paixushu(node * T,int x)
{
    if(T == NULL)
    {
        T = create();
        T->c = x;
    }
    else if(x < T->c) paixushu(T->lchild,x);
    else if(x > T->c) paixushu(T->rchild,x);//д����else if x = T->c������ͱ��Թ���
}

int main()
{
    int n;//һ����Ҫ�ͼ�������
    while(scanf("%d",&n)!=EOF)
    {
        char input[100];
        loc = 0;
        scanf("%s",input);
        //��һ�ö���������
        node * tmp = create();//tnp == NULL?
        int len = strlen(input);
        int i;
        for(i = 0;i < len;i++)
        {
            tmp = paixushu(tmp,input[i] - '0');
        }
        //�õ�str1 ����
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
