//��ϰ ����ɸ
#include <stdio.h>

int prime[10000];
bool mark[10000];
int num;
void init()
{
    int i;
    for(i = 0;i < 10000;i++)
        mark[i] = false;//��ʼֵ��Ϊȫ������ false��ʾ������
    mark[1] = true;//1��������
    num = 0;
    for(i = 2;i < 10000;i++)
    {
        if(mark[i] == true) continue;
        prime[num++] = i;
        int j;
        for(j = i * i;j < 10000;j++)//�˴��е������
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
                printf("%d\n",i);//�о� prime����û���� init����mark����Ϳ�����
        }
    }
    return 0;
}
