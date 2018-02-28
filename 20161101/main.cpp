//��ϰ ����С������Ȩֵ
//�Ժ�������Ҫ�����������ע����
#include <stdio.h>
#include <algorithm>

using namespace std;

//�߽ṹ��
struct edge
{
    int a,b;
    int cost;//Ȩֵ
    bool operator < (const edge &A) const//A������
    {
        return cost < A.cost;
    }
}edge[5000];
int tree[101];//˫������ ȫ��

//��x�ĸ��ڵ� ͬʱѹ��·��
int findRoot(int x)
{
    if(tree[x] == -1) return tree[x];
    else{
    int tmp = findRoot(tree[x]);
    tree[x] = tmp;
    return tmp;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int m = n * (n - 1) / 2;
        int i;
        //��ʼ��˫�׽ڵ�
        for(i = 0;i < n;i++)
        {
            tree[i] = -1;
        }
        for(i = 0;i < m;i++)
        {
           scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        //���ձ�Ȩֵ��������
        sort(edge,edge + m);

        int res = 0;
        int a,b;
        for(i = 0;i < m;i++)//�������б�
        {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
            if(a != b)
                tree[a] = b;
            ans += edge[i].cost;
        }
        printf("%d\n",ans);
    }
    return 0;
}
