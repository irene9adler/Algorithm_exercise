//c++����ʹ�� ����
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set <int> myset;
        //���������
        set <int>:: iterator ite;
        int i;
        for(i = 0;i < nums.size();i++)
        {
            ite = myset.find(nums[i]);
            if(ite != nums.end())//�ҵ���
            {
                nums.erase(ite);
            }
            else//û�ҵ�
                nums.insert(ite);

            for(ite = nums.begin();ite < nums.end();ite++)
            {
                return *ite;//���ص�����ָ���ֵ
            }
        }
        //����һ������ ��ͷ����nums���� ����������Ѿ������Ԫ���� �Ѽ����е����Ԫ��ɾ��
        //��������л�û�����Ԫ�� ���� ����ʣ��Ԫ���ڼ�����

    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
