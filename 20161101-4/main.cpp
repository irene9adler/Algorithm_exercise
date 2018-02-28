//复习进制转换 m进制转n进制 不用中间转成十进制
#include <stdio.h>


int main()
{
    int m,n;
    char str[100];
    while(scanf("%d%s%d",&m,str,&n)!=EOF)
    {
        int tmp = 0;//这是中间结果
        int c= 1;
        int i;
        int l = strlen(str);
        for(i = l - 1;i >= 0;i--)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                tmp += str[i] - 'A' + 10;
                c = c * m;
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                tmp += str[i] - 'a' + 10;
                c = c * m;
            }
            else
            {
                tmp += str[i] - '0';
                c = c * m;
            }
        }
        char res[100];
        int loc = 0;
        int r;
        if(tmp == 0) res[0] = '0';
        while(tmp != 0)//while(tmp)
        {
            r = tmp % n;
            if(r < 10)
                res[loc++] = r + '0';
            else res[loc++] = r - 10 + 'A';
            tmp /= n;
        }
        printf("%s\n",res);
       }
    }
    return 0;
}
