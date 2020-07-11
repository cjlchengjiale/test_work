#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//二进制插入
int binInsert(int n, int m, int j, int i)
{
  vector<int> num;
  vector<int> num1;
  int tmp = n;
  int tmp1 = m;
  while(tmp!=0)
  {
    int cur = tmp%2;
    //cout<<cur<<endl;
    num.push_back(cur);
    tmp/=2;
  }
  while(tmp1!=0)
  {
    int cur = tmp1%2;
    //cout<<cur<<endl;
    num1.push_back(cur);
    tmp1/=2;
  }
  //reverse(num.begin(),num.end());
  // for(auto& ch:num)
  //   cout<<ch<<" ";
  // cout<<endl;
  // for(auto& ch:num1)
  //   cout<<ch<<" ";
  // cout<<endl;
  int k = 0;
  for(int p = j;p<=i;p++)
  {
    if(k==num1.size())
      break;
    num[p] = num1[k];
    cout<<num[p]<<endl;
    k++;
  }
  int number = 0;
  int sum = 0;
  int bnt = 1;
  //reverse(num.begin(),num.end());
  for(int c = 0;c<num.size();c++)
  {
    sum = bnt*num[c];
    number+=sum;
    bnt*=2;
  }
  // for(auto& ch:num)
  //   cout<<ch<<" ";
  // cout<<endl;
   cout<<number<<endl;
}
//构成某个偶数的相邻最小的两个素数
void test()
{
    int n = 0;
    cin>>n;
    int flag = 0;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    int tmp1 = 0,tmp2 = 0;
    for(int i = 3;i<=n;i++)
    {
        for(int j = 2;j<i;j++)
        {
            if(i%j==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            num.push_back(i);
        else
            flag = 0;
    }
    for(auto& ch:num)
      cout<<ch<<" ";
    cout<<endl;
    // while(it<cit)
    // {
    //   it()
    // }
    for(int i = 0;i<num.size() - 1;i++)
    {
      for(int j = i;j<num.size();j++)
      {
        if(num[i] + num[j] == n)
        {
          tmp1 = num[i];
          tmp2 = num[j];
        }
      }
    }
    cout<<tmp1<<" "<<tmp2<<endl;
}
int t()
{
  int n[][3] = {10,20,30,40,50,60};
  int (*p)[3];
  p = n;
  cout<<p[0][0]<<" "<<*(p[0]+1)<<" "<<(*p)[2]<<endl;
}
int main()
{
  // binInsert(356353,184,3,11);
  // test();
  t();
}
