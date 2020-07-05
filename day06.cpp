#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
struct A
{
  long a;
  short b;
  int c;
  int *d;
};
// int main()
// {
//   // int m = 0123,n = 123;
//   // printf("%o,%o",m,n);
//   cout<<sizeof(A);
// }
//×Ö·û´®×ªintÐÍ
int test()
{
  string str;
  getline(cin,str);
  int ans = 0;
  int sum = 0;
  string::iterator it = str.begin();
  while(it != str.end())
  {
    if(*it<'0'||*it>'9')
      return 0;
    else
    {
      ans *= 10;
      ans += (*it - '0');
      //cout<<ans<<endl;
    }
    it++;
  }
  return ans;
}
void test1()
{
    int w = 0,h = 0;
    cin>>w>>h;
    int num[w][h];
    for(int i = 0;i<w;i++)
    {
        for(int j = 0;j<h;j++)
        {
            num[i][j] = 0;
        }
    }
    for(int i = 0;i<w;i++)
    {
        for(int j = 0;j<h;j++)
        {
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0;i<w;i++)
    {
        for(int j = 0;j<h;j++)
        {
            for(int k = i;k<w;k++)
            {
              for(int s = j + 1;s<h;s++)
              {
                //i j
                num[i][j] = 1;
                int tmp1 = k - i;
                int tmp2 = s - j;
                int sum = (tmp1*tmp1) + (tmp2*tmp2);
                int anw = sqrt(sum);
                //cout<<"++"<<anw<<"---";
                //cout<<k<<"  "<<s;
                if(anw != 2&&num[k][s] != 1)
                {
                  num[k][s] = 1;
                  cout<<"----"<<k<<"  "<<s<<endl;
                }
                if(anw !=2&&num[k][s] == 1)
                  num[k][s] = 0;
              }
              //cout<<endl;
            }
        }
    }
    for(int i = 0;i<w;i++)
    {
        for(int j = 0;j<h;j++)
        {
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
  cout<<test()<<endl;
}
