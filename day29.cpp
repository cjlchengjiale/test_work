// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;//9,6//r –– c¡–
int num = 0;
void my_find_max1(vector<vector<char>> &p,int m,int n,int c,int r)
{
  //cout<<m<<" "<<n<<" "<<r<<" "<<c<<" "<<num<<endl;
    if(c<0||c==n||r<0||r==m||p[r][c] == '#')    return ;
      num++;
      p[r][c] = '#';
      my_find_max1(p,m,n,c,r-1);
      my_find_max1(p,m,n,c-1,r);
      my_find_max1(p,m,n,c+1,r);
      my_find_max1(p,m,n,c,r+1);
}
void test()
{
    int n,m;
    while(cin>>m>>n)
    {
        vector<vector<char>> vec;
        int x,y;
        vec.resize(m);
        for(int i = 0;i<m;i++)
        {
            vec[i].resize(n);
            for(int j = 0;j<n;j++)
            {
                 // char tmp;
                 // cin>>tmp;
                 // vec[i].push_back(tmp);
                 cin>>vec[i][j];
                 //cout<<num[i][j]<<endl;
                if(vec[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        // for(int i = 0;i<m;i++)
        // {
        //   for(int j = 0;j<n;j++)
        //     cout<<vec[i][j];
        //   cout<<endl;
        // }
        my_find_max1(vec,m,n,y,x);
        cout<<num<<endl;
        num = 0;
    }
}
double dfs(int n,int m,int c,int r)
{
    if(c==n||r==m) return 1.0;
    if(c==n&&r==m) return 0;
    return dfs(n,m,c+1,r)+dfs(n,m,c,r+1);
}
void test1()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int i = 0;i<k;i++)
        {
            int x = 0,y = 0;
            cin>>x>>y;
            vec[x-1][y-1] = 1;
        }
       double dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 0;
        int flag = 0;
        for(int i = 0;i<n;i++)
        {
            if(flag == 0&&vec[i][0] != 1)
                dp[i][0] = 1;
            if(flag == 1||vec[i][0] == 1)
            {
                flag = 1;
                dp[i][0] = 0;
            }
        }
        flag = 0;
        for(int j = 0;j<m;j++)
        {
            if(flag == 0&&vec[0][j] != 1)
                dp[0][j] = 1;
            if(flag == 1||vec[0][j] == 1)
            {
                flag = 1;
                dp[0][j] = 0;
            }
        }
        /*cout<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
                cout<<vec[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                if(vec[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j]+dp[i][j - 1];
            }
        }
        /*cout<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        int all = dfs(n,m,1,1);
        //cout<<dp[n-1][m-1]<<endl;
        printf("%.2f\n",dp[n-1][m-1]/all);
    }
}
int main()
{
    test();
}
