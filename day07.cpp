#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
class p
{
public:
  p(int a,int b)
  {
    _a = a--;
    _b = _a*b;
  }
public:
  int _a;
  int _b;
};
//变成斐波那契数的最小判断
void test()
{
    int a = 0;
    int b = 1;
    int c = 0;
    int n = 0;
    int min = 0;
    int flag = 0;
    cin>>n;
    while(c<n)
    {
        c = a+b;
        //cout<<c<<" ";
        if(n==c)
        {
            cout<<0<<endl;
            flag = 1;
            break;
        }
        a = b;
        b = c;
    }
    //cout<<endl;
    //cout<<c<<" "<<a<<endl;
    if(flag == 0)
    {
      min = c - n;
      if(min>n - a)
          min = n - a;
      cout<<min<<endl;
    }
}
//判断括号是否合法
bool test2(string A,int n)
{
  stack<char> st;
  for(int i = 0;i<n;i++)
  {
    //cout<<"----"<<endl;
      if(A[i] != '('&&A[i] != ')'||A[0] == ')')
      {
        //cout<<"----+++++"<<endl;
          return false;
      }
      else
      {
          if(A[i] == '(')
          {
              st.push(A[i]);
          }
          else
          {
            if(st.empty())
              return false;
            else
              st.pop();
          }
      }
  }
  return st.empty();
}
void t()
{
  int n = 0;
  char ch;
  // while(ch = getchar()!='\n')
  //   n++;
  for(n = 0; getchar()!='\n';n++)
  {

  }
  cout<<n;
}
void t1()
{
  // int a =1,b = 2,c = 3,d = 0;
  // if(a==1&&b++==2)
  // if(b!=2||c--!=3)
  //   cout<<a<<" "<<b<<" "<<c<<" 1"<<endl;
  // else
  //   cout<<a<<" "<<b<<" "<<c<<" 2"<<endl;
  // else
  //   cout<<a<<" "<<b<<" "<<c<<" 3"<<endl;
  int p[][4] = {{1},{3,2},{4,5,6},{0}};
  cout<<p[1][2];
}
int main()
{
  // string str("())");
  // for(int i = 0;i<str.size();i++)
  // {
  //   cout<<str[i];
  // }
  // cout<<endl;
  // cout<<test2(str,str.size());
  // p a(4,5);
  // cout<<a._a<<" "<<a._b<<endl;
  t1();
}
