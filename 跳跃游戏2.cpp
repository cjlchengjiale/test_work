/*
45. ��Ծ��Ϸ II
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
     ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<ctime>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size() == 1)    return 0;
        //��ʼ��
        for(int i = 0;i<nums.size();i++)
            dp[i] = i;
        //
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<=nums[i];j++)
            {
                if(i + j<nums.size())
                {
                    dp[i + j] = min(dp[i + j],dp[i] + 1);
                }
                else
                    return dp[nums.size() - 1];
            }
        }
        return dp[nums.size() - 1];
    }
};
int main()
{
  return 0;
}
