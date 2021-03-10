/*
45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
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
        //初始化
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
