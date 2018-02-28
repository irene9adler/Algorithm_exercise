//c++集合使用 例子
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set <int> myset;
        //定义迭代器
        set <int>:: iterator ite;
        int i;
        for(i = 0;i < nums.size();i++)
        {
            ite = myset.find(nums[i]);
            if(ite != nums.end())//找到了
            {
                nums.erase(ite);
            }
            else//没找到
                nums.insert(ite);

            for(ite = nums.begin();ite < nums.end();ite++)
            {
                return *ite;//返回迭代器指向的值
            }
        }
        //定义一个集合 从头遍历nums数组 如果集合中已经有这个元素了 把集合中的这个元素删掉
        //如果集合中还没有这个元素 插入 最后就剩答案元素在集合里

    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
