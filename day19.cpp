#include<iostream>
using namespace std;
//ºÈ¿ÉÀÖ
void test2()
{
  int n = 0;
    while(cin>>n)
    {
        int tmp = 0;
        int sum = 0;
        while(n>2)
        {
            sum += n/3;
            tmp = n/3+n%3;
            n = tmp;
        }
        if(n==2)
            sum++;
        cout<<sum<<endl;
    }
}
void test1()
{
  string str1,str2;
  cin>>str1>>str2;
  if(str1.size()>str2.size())
    swap(str1,str2);
  for(auto& ch:str1)
    cout<<ch;
  cout<<endl;
  string::iterator it = str1.begin();
  string::iterator begin = it;
  string::iterator rbegin = str1.begin();
  string::iterator idx = str1.begin();
  string::iterator cit = str2.begin();
  string::iterator cbegin = str2.begin();
  int tmp = 0,max = 0;
  while(rbegin!=str1.end())
  {
    //cout<<*rbegin<<"---"<<endl;
      while(cit != str2.end())
      {
          while(*it == *cit)
          {
              it++;
              cit++;
              tmp++;
          }
          //cout<<tmp<<endl;
          if(tmp>max)
          {
              idx = rbegin;
              max = tmp;
          }
          tmp = 0;
          cbegin++;
          cit = cbegin;
          it = rbegin;
      }
      rbegin++;
      it = rbegin;
      cbegin = str2.begin();
      cit = cbegin;
  }
  string res(idx,idx+max);
  //cout<<*idx<<"===="<<max<<endl;
  cout<<res<<endl;
}
int main()
{
    test1();
}
