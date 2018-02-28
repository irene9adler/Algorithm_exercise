//复习 常规素数判断
#include <stdio.h>
#include <math.h>
 bool primeJudge(int x)
 {
     int l = sqrt(x) + 1;
     int i;
     bool res = true;
     if(x == 1) return false;
     for(i = 2;i < l;i++)
     {
         if(x % i == 0)//能整除
            res = false;
     }
     return res;
 }

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans = primeJudge(n);
        if(ans == true) printf("YES\n");
        else printf("NO!\n");
    }
    return 0;
}
