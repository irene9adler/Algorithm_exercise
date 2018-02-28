#include <iostream>
#include <stdio.h>

#define MAXN 5005
using namespace std;
int a[MAXN];
int b[MAXN];
int m,n,ans;


int main()
{
    n = 1;
    scanf("%d",&m);
    int sum = 0;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= i ; j++){
            scanf("%d",&a[n++]);
        }
    }

    b[1] = a[1];
    for(int i = 1 ; i <= m-1 ; i++){
        for(int j = 1 ; j <= i ; j++){
            for(int k = j ; k <= j+1 ; k++){
                b[sum+i+k] = max(b[sum+i+k],b[sum+j]+a[sum+i+k]);
            }
        }
        sum += i;
    }
    for(int i = sum+1 ; i <= (m*(m+1)/2) ; i++){
        ans = max(b[i],ans);
    }
    printf("%d\n",ans);
    return 0;
}
