#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//两个string字符串的比较
int lex_compare(string a[],int n)
{
  for(int i = 1;i<n;i++)
  {
    //cout<<a[i].compare(a[i - 1])<<" ";
    if(a[i].compare(a[i - 1])<1)
      return 0;

  }
  return 1;
}
int length_compare(string str[],int n)
{
  for(int i = 1;i<n;i++)
  {
    if(str[i - 1].size()>str[i].size())
      return 0;
  }
  return 1;
}
void test()
{
  int n = 0;
  int a = 0;
  int b = 1;
  cin>>n;
  string str[n];
  for(int i = 0;i<n;i++)
  {
    cin>>str[i];
  }
  a = length_compare(str,n);
  b = lex_compare(str,n);
  cout<<a<<" "<<b<<endl;
  if(a==0&&b==1)
    cout<<"lexicographically"<<endl;
  if(a==1&&b==0)
    cout<<"lengths"<<endl;
  if(a==1&&b==1)
    cout<<"both"<<endl;
  if(a==0&&b==0)
    cout<<"none"<<endl;
}
//输出int类型的最小公倍数
void compare(int &n,int &m)
{
    if(n>m)
    {
        int tmp = n;
        n = m;
        m = tmp;
    }
}
void test1()
{
    int num1 = 0;
    int num2 = 0;
    cin>>num1>>num2;
    int sum = 1;
    if(num1%num2 == 0)
    {
        cout<<num1<<endl;
        exit(0);
    }
    if(num2%num1 == 0)
    {
        cout<<num2<<endl;
        exit(0);
    }
    compare(num1,num2);
    //cout<<num1<<"----"<<num2<<endl;
    for(int i=1;i<num1;i++)
    {
        if(num1%i==0&&num2%i==0)
        {
            sum*=i;
            num1/=i;
            num2/=i;
            //cout<<sum<<" ";
        }
    }
    //cout<<endl;
    cout<<num1*num2*sum<<endl;
}
void other_test()
{
  int a[4] = {1,2,3,4};
  int *p = (int*)(&a + 1);
  cout<<*(p - 1)<<endl;
}
int main()
{
  // test();
  // test1();
  other_test();
}
