#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
struct node{
    int x,y;
    node(int xx,int yy):x(xx),y(yy){}
};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main()
{
    int t,ca;
    int n,m,sx,sy;
    bool used[555][555];
    char s[555][555];
    scanf("%d",&t);
    for(int ca = 1 ; ca <= t ; ca++){
        scanf("%d %d",&n,&m);
        scanf("%d %d",&sx,&sy);
        sx--;sy--;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s[i]);
        }
        memset(used,false,sizeof(used));
        queue<node> que;
        que.push(node(sx,sy));
        used[sx][sy] = true;
        while(!que.empty()){
            node p = que.front();
            que.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x = p.x+dx[i];
                int y = p.y+dy[i];
                if(x<0||x>=n||y<0||y>=m)continue;
                if(used[x][y])continue;
                used[x][y] = true;
                if(s[x][y]=='*')ans++;
                else que.push(node(x,y));
            }
        }
        printf("Case %d: %d",ca,ans);
    }
    return 0;
}
