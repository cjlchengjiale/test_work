
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class solution
{
public:
  int min_cut(string s)
  {
    int len = s.length();
    vector<int> dp(len,0);
    for(int i = 0;i<len;i++)
      dp[i] = i;
    for(int i = 1;i<len;i++)
    {
      if(is_true(s,0,i))
        dp[i] = 0;
      else
      {
        for(int j = 0;j<i;j++)
        {
          if(is_true(s,j + 1,i))
            dp[i] = min(dp[j] + 1,dp[i]);
        }
      }
    }
    return dp[len - 1];
  }
  bool is_true(string s,int left,int right)
  {
    while(left <= right)
    {
      if(s[left] != s[right])
        return false;
      else
      {
        left++;
        right--;
      }
    }
    return true;
  }
};
int main()
{
  string s;
  cin>>s;
  solution st;
  cout<<st.min_cut(s)<<endl;
}
