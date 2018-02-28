 #include<stdio.h>
 #include<string.h>
 #define Max 1010

 char str1[Max],str2[Max],ans[Max],temp1[Max],temp2[Max];
 void Calculate()
 {
     int i,j,k,p,q,n,s,c;
     memset(str1,0,sizeof(str1));
     memset(str2,0,sizeof(str2));
     memset(ans,0,sizeof(ans));
     n=strlen(temp1);
     if(strchr(temp1,'.')==NULL)
         k=n;
     else
         k=strchr(temp1,'.')-temp1;//(重点)
     for(i=k-1,j=500;i>=0;i--,j++)
         str1[j]=temp1[i]-'0';
     for(i=k+1,j=499;i<n;i++,j--)
         str1[j]=temp1[i]-'0';
     n=strlen(temp2);
     if(strchr(temp2,'.')==NULL)
         k=n;
     else
         k=strchr(temp2,'.')-temp2;
     for(i=k-1,j=500;i>=0;i--,j++)
         str2[j]=temp2[i]-'0';
     for(i=k+1,j=499;i<n;i++,j--)
         str2[j]=temp2[i]-'0';
     c=0;
     for(i=0;i<1010;i++)
     {
         s=str1[i]+str2[i]+c;
         ans[i]=s;
         c=s/10;
     }
     //return ;
 }
 void Output()
 {
     int i,j;

     i=1009;
     while(ans[i]==0)//&&i>500
         i--;
     for(;i>=500;i--)
     printf("%d",ans[i]);

     j=0;
     while(ans[j]==0&&j<500)
         j++;
     if(j!=500)//(重点)
     {
         printf(".");
         for(i=499;i>=j;i--)
         printf("%d",ans[i]);
     }
     printf("\n");
 }
 int main()
 {
     while(scanf("%s %s",&temp1,&temp2))
     {
         Calculate();
         Output();
     }
     return 0;
 }
