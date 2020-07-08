#include<iostream>
using namespace std;
void test()
{
  int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  cout<<*(*(a+1)+1)<<endl;
}
class a
{
public:
  a(int i = 0){cout<<1;}
  a(const a&x){cout<<2;}
  a&operator = (const a&x){cout<<3;return *this;}
  ~a(){cout<<4;}
};
//另类加法
int addnum(int a,int b)
{
  int tmp = 0;
  int cur = 0;
  while(b!=0)
  {
    tmp = a^b;
    cur = (a&b)<<1;
    a = tmp;
    b = cur;
  }
  return a;
}
//路程问题
int sul(int a)
{
  if(a==1)
    return 1;
  return a*sul(a-1);
}
void num_road()
{
  int a = 0,b = 0;
  cin>>a>>b;
  int tmp = a+b;
  cout<<sul(tmp)/(sul(a)*sul(b))<<endl;
}
int main()
{
  //int a = 4;
  //test();
  // a b(1),c(2),d(b);
  num_road();
}
