//复习 素数筛
#include <stdio.h>

int prime[10000];
bool mark[10000];
int num;
void init()
{
    int i;
    for(i = 0;i < 10000;i++)
        mark[i] = false;//初始值设为全是素数 false表示是素数
    mark[1] = true;//1不是素数
    num = 0;
    for(i = 2;i < 10000;i++)
    {
        if(mark[i] == true) continue;
        prime[num++] = i;
        int j;
        for(j = i * i;j < 10000;j++)//此处有点儿不懂
        {
            mark[j] = true;
        }
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i = 0;i < n;i++)
        {
            if(mark[i] == false)
                printf("%d\n",i);//感觉 prime数组没用上 init后用mark数组就可以了
        }
    }
    return 0;
}
