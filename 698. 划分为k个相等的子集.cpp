/*
698. ����Ϊk����ȵ��Ӽ�
����һ����������  nums ��һ�������� k���ҳ��Ƿ��п��ܰ��������ֳ� k ���ǿ��Ӽ������ܺͶ���ȡ�

ʾ�� 1��

���룺 nums = [4, 3, 2, 3, 5, 2, 1], k = 4
����� True
˵���� �п��ܽ���ֳ� 4 ���Ӽ���5������1,4������2,3������2,3�������ܺ͡�


��ʾ��

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
