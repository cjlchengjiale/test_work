/*
698. 划分为k个相等的子集
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。


提示：

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int max_num = nums[0];
        for(auto& ch:nums)
        {
            sum+=ch;
            max_num = max(max_num,ch);
        }
        if(sum % k != 0 || max_num > sum/k)    return false;
        vector<bool> visited(nums.size(),false);
        return is_true(0,0,sum/k,k,nums,visited);
    }
    bool is_true(int idx,int now_sum,int target,int num,vector<int>& nums,vector<bool> &visited)
    {
        if(num == 0)    return true;
        int flag = false;
        for(int i = idx;i<nums.size();i++)
        {
            if(!visited[i] && now_sum + nums[i] <= target)
            {
                visited[i] = true;
                if(now_sum + nums[i] < target)
                {
                    flag = is_true(i + 1,now_sum + nums[i],target,num,nums,visited);
                }
                else
                {
                    flag = is_true(0,0 ,target,num-1,nums,visited);
                }
                visited[i] = false;
                if(flag)    return true;
            }
        }
        return flag;
    }
};
