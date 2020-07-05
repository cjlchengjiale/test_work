#include<iostream>
#include<string>
using namespace std;
void test()
{
  int num[][3] = {10,20,30,40,50,60};
  int (*p)[3];
  p= num;
  cout<<p[0][0]<<" "<<*(p[0]+1)<<" "<<(*p)[2]<<endl;
}
bool istrue(string& str)
{
  int size = str.size();
  string::iterator it = str.begin();
  string::iterator cit = str.end() - 1;
  while(it<=cit)
  {
    if(*it != *cit)
      return false;
    it++;
    cit--;
  }
  return true;
}
//判断每个位置的回文数个数
void test1()
{
  string str1;
  string str2;
  getline(cin,str1);
  getline(cin,str2);
  string cpy(str1);
  int sum = 0;
  //str1.insert(2,str2);
  for(int i = 0;i<=str1.size();i++)
  {
    cpy = str1;
    cpy.insert(i,str2);
    cout<<cpy<<"  "<<cpy.size()<<endl;
    if(istrue(cpy) == 1)
    {
      sum++;
    }
  }
  cout<<sum<<endl;
}
int main()
{
  // int x = 1;
  // do
  // {
  //   cout<<x++<<endl;
  // }while(x--);
  test1();
}
