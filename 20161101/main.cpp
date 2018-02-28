//复习 求最小生成树权值
//以后有书需要把下面的用例注释上
#include <stdio.h>
#include <algorithm>

using namespace std;

//边结构体
struct edge
{
    int a,b;
    int cost;//权值
    bool operator < (const edge &A) const//A是引用
    {
        return cost < A.cost;
    }
}edge[5000];
int tree[101];//双亲数组 全局

//找x的根节点 同时压缩路径
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
        //初始化双亲节点
        for(i = 0;i < n;i++)
        {
            tree[i] = -1;
        }
        for(i = 0;i < m;i++)
        {
           scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        //按照边权值递增排序
        sort(edge,edge + m);

        int res = 0;
        int a,b;
        for(i = 0;i < m;i++)//遍历所有边
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
