#include<iostream>
using namespace std;
int test(int a)
{
  int tmp = 1;
  int num = 0;
  while(tmp<a+1)
  {
    tmp*=2;
    num++;
  }
  //cout<<num1 - 1<<endl;
  return num;
}
void find_father(int a,int b)
{
  int road1 = test(a);
  int road2 = test(b);
  cout<<road1<<"----"<<road2<<endl;
  if(road1>road2)
  {
    while(road1>road2)
    {
      if(a%2 == 0)
      {
        a/=2;
        road1--;
      }
      else
      {
        a = a - 1;
        a/=2;
        road1--;
      }
      cout<<a<<" "<<road1<<endl;
    }
  }
  if(road1<road2)
  {
    while(road1<road2)
    {
      if(b%2 == 0)
      {
        b/=2;
        road2--;
      }
      else
      {
        b = b - 1;
        b/=2;
        road2--;
      }
      cout<<b<<" "<<road2<<endl;
    }
  }
  cout<<b<<"===="<<road2<<endl;
  cout<<a<<"****"<<b<<endl;
  while(a!=b)
  {
    if(a%2 == 0)
      a/=2;
    else
    {
      a--;
      a/=2;
    }
    if(b%2 == 1)
    {
      b--;
      b/=2;
    }
    else
      b/=2;
    cout<<a<<"++++"<<b<<endl;
  }
  cout<<a<<endl;
}

class LCA {
public:
  int getLCA(int a, int b){
    int road1 = 0;
  int road2 = 0;
  int tmp1 = 1;
  int num1 = 0;
  while(tmp1<a+1)
  {
    tmp1*=2;
    num1++;
  }
   road1 = num1;
   int tmp2 = 1;
  int num2 = 0;
  while(tmp2<b+1)
  {
    tmp2*=2;
    num2++;
  }
    road2 = num2;
  //cout<<road1<<"----"<<road2<<endl;
  if(road1>road2)
  {
    while(road1>road2)
    {
      if(a%2 == 0)
      {
        a/=2;
        road1--;
      }
      if(a%2 == 1)
      {
        a = a - 1;
        a/=2;
        road1--;
      }
      //cout<<a<<" "<<road1<<endl;
    }
  }
  if(road1<road2)
  {
    while(road1<road2)
    {
      if(b%2 == 0)
      {
        b/=2;
        road2--;
      }
      if(b%2 == 1)
      {
        b = b - 1;
        b/=2;
        road2--;
      }
      //cout<<b<<" "<<road2<<endl;
    }
  }
  //cout<<b<<"===="<<road2<<endl;
  //cout<<a<<"****"<<b<<endl;
  while(a!=b)
  {
    if(a%2 == 0)
      a/=2;
    else
    {
      a--;
      a/=2;
    }
    if(b%2 == 1)
    {
      b--;
      b/=2;
    }
    else
      b/=2;
    //cout<<a<<"++++"<<b<<endl;
  }
  cout<<a<<endl;
  }
};
void test()
{
    int num = 0;
    cin>>num;
    int max = 0;
    int sum = 0;
    int tmp = 0;
    while(num!=0)
    {
      cout<<num<<endl;
        tmp = num%2;
        cout<<tmp<<"_____"<<endl;
        if(tmp == 1)
        {
            sum++;
        }
        if(tmp == 0)
        {
            if(max < sum)
            {
                max = sum;
            }
            sum = 0;
        }
        num/=2;
        cout<<sum<<"======="<<max<<endl;
    }
    if(sum > max)
      max = sum;
    cout<<max<<"---"<<endl;
}
int main()
{
  // test();
  //find_father(12,5);
  // LCA tmp;
  // tmp.getLCA(12,3);
  test();
}
