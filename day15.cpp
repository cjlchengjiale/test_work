#include<iostream>
#include<string>
#include<vector>
using namespace std;
void test()
{
  int n = 0;
  cin>>n;
  int sum = 0;
  for(int i = 2;i<=n;i++)
  {
    int tmp = 0;
    for(int j = 1;(j*j)<i;j++)
    {
      if(i%j == 0)
      {
        tmp+=j;
        if((i/j)!=i)
          tmp+=(i/j);
      }
    }
    if(tmp == i)
    {
      sum++;
      cout<<i<<endl;
    }
  }
  cout<<sum<<endl;
}
string get_str(string& str)
{
  string tmp;
  for(int i = 0;i<str.size();i++)
  {
    if(str[i]!=' ')
      tmp.push_back(str[i]);
  }
  for(auto& ch:tmp)
    cout<<ch;
  cout<<endl;
  return tmp;
}
void get_vec(string str,vector<string>& vec)
{
  string::iterator it = str.begin();
  for(int i = 0;i<str.size();i++)
  {
    if(str[i]=='1'&&str[i+1]=='0')
    {
      string tmp;
      tmp.push_back(str[i]);
      i++;
      tmp.push_back(str[i]);
    }
    if(str[i] == str[i+1])
    {
      string tmp;
      while(str[i]==str[i+1])
      {
        i++;
        tmp.push_back(str[i]);
      }
      tmp.push_back(str[i]);
      vec.push_back(tmp);
    }
    else if(str[i]+1 == str[i+1])
    {
      string tmp;
      while(str[i]+1 == str[i+1])
      {
        i++;
        tmp.push_back(str[i]);
      }
      vec.push_back(tmp);
    }
    else if(str[i]=='j'||str[i]=='J')
    {
      string tmp(it+i,it+i+5);
      i+=4;
      vec.push_back(tmp);
    }
    else
    {
      string tmp;
      tmp.push_back(str[i]);
      vec.push_back(tmp);
    }
  }
}
void test1()
{
    string str1;
    getline(cin,str1);
    vector<string> vec1;
    vector<string> vec2;
    string tmp;
    string str = get_str(str1);
    string::iterator it = str.begin();
    int a = str.find("-");
    string s1(it,it+a);
    string s2(it+a+1,str.end());
    get_vec(s1,vec1);
    get_vec(s2,vec2);
    for(auto&ch:vec1)
      cout<<ch<<endl;
    cout<<endl;
    for(auto&ch:vec2)
      cout<<ch<<endl;
    cout<<endl;
}
class A
{
public:
  void funca()
  {
    cout<<"funa called"<<endl;
  }
  virtual void funcb()
  {
    cout<<"funb called"<<endl;
  }
};
class B:public A
{
public:
  void funca()
  {
    //A::funca();
    cout<<"funcab called"<<endl;
  }
  virtual void funcb()
  {
    cout<<"funcbb called"<<endl;
  }
};
int main()
{
  // test1();
  B b;
  A *pa;
  pa = &b;
  A *pa2 = new A;
  pa->funca();
   pa->funcb();
   pa2->funca();
   pa2->funcb();
  delete pa2;
}
