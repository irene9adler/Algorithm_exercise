//��ϰ С�������������
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    priority_queue< int,vector <int>,greater<int> > Q;
    //�󶥶� priority_queue <int> Q;
    int n;
    while(scanf("%d",&n)!=EOF)//������������ʲô˳��?
    {
        if(Q.empty() == false) Q.pop();
        int i;
        int tmp;
        for(i = 0;i < n;i++)
        {
            scanf("%d",&tmp);
            Q.push(tmp);
        }
        int a,b;
        int res = 0;
        while(Q.empty() == false)
        {
            a = Q.top();
            Q.pop();//popû�з���ֵ
            b = Q.top();
            Q.pop();
            res += a + b;
            Q.push(a + b);
        }
        printf("%d\n",res);
    }
    return 0;
}
