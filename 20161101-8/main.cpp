#include <stdio.h>
#include <string.h>

int main()
{
    int n;


    while(scanf("%d",&n)!=EOF)
    {
        char str[256] = {0};
        char inside[256][256];
        char outside[256][256];
        int loc_in = 0;
        int loc_out = 0;
        scanf("%s",str);
        int l = strlen(str);
        int i = 0;
        int j = 0,k = 0;
        //for(i = 0;i < l;i++)
        while(str[i] != 0)
        {
            printf("str[%d] = %c\n",i,str[i]);//_
            if(str[i] == '(')//处理in的部分
            {
                i++;
                if(loc_in == 0) loc_in = 1;
                while(1)
                {
                   if(str[i] == '_')
                   {
                       if(loc_in > 1 && str[i - 1] != '_')
                       {
                           loc_in ++;
                       }
                       j = 0;
                       i++;
                       continue;
                   }
                   if(str[i] == ')')
                    {
                        i++;
                        loc_in ++;
                        j = 0;
                        break;
                    }

                   inside[loc_in][j++] = str[i];
                   printf("inside[%d][%d] = %c\n",loc_in,j,inside[loc_in][j]);
                   i++;
                }
                //continue;
            }

            //处理out的部分
            else if(str[i] == '_')
            {
                if(loc_out > 1 && str[i - 1] != '_')
                {
                    loc_out ++;
                }
                i++;
                k = 0;
                //continue;
            }

            else{
                    if(loc_out == 0) loc_out = 1;
                    outside[loc_out][k++] = str[i];
                    i++;
            }

        }

        int max_out_len = 0;
        for(i = 1;i <= loc_out;i++)
        {
            if(strlen(outside[i]) > max_out_len)
               max_out_len = strlen(outside[i]);
        }
        printf("%d ",max_out_len);
        int res_in = 0;
        while(strlen(inside[res_in]) != 0)
        {
            res_in ++;
        }
        printf("%d\n",res_in);

       printf("loc_in = %d\n",loc_in - 1);//in out的计数有_问题
       printf("loc_out = %d\n",loc_out);
       for(i = 1;i <= loc_out;i++)
        {
            printf("loc_out[%d]:%s\n",i,outside[i]);
        }

       for(i = 1;i <= loc_in;i++)
        {
            printf("loc_in[%d]:%s\n",i,inside[i]);
            printf("length of inside = %d\n",strlen(inside[i]));
        }
    }
    return 0;
}
