#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> res;
vector<int> vec;
void dfs(int n,int j,int m,int tmp)
{
    if(tmp == m)
    {
        res.push_back(vec);
        //for(auto& ch:vec)
          //cout<<ch<<" ";
        //cout<<endl;
        vec.pop_back();
        //cout<<tmp<<"==="<<endl;
        return ;
    }
    for(j;j<=n;j++)
    {
        if(tmp+j>m) break;
        else if(tmp+j<=m)
        {
            //cout<<j<<"**"<<endl;
            vec.push_back(j);
            dfs(n,j+1,m,tmp+j);
            //cout<<j<<"---"<<tmp<<endl;
        }
        else
        {
          //tmp-=(j-1);
          if(!vec.empty())
          {
            //cout<<"erase :"<<vec[vec.size() - 1]<<endl;
            vec.pop_back();
          }
          return ;
        }
        //vec.pop_back();
    }
    if(!vec.empty())
    {
      //cout<<"erase :"<<vec[vec.size() - 1]<<endl;
      vec.pop_back();
    }
}
void test()
{
    int n = 0,m = 0;
    while(cin>>n>>m)
    {
        vector<int> vec;
        //for(int i = 1;i<=n;i++)
        //{
          dfs(n,1,m,0);
          vec.clear();
        //}
        for(int i = 0;i<res.size();i++)
        {
            for(int j = 0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        res.clear();
    }
}
int main()
{
    test();
}
