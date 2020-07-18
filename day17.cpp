#include<iostream>
#include<string>
using namespace std;
void reverse(string& str)
{
  int cur = 0;
  int end = str.size() - 1;
  while(cur<=end)
  {
    char tmp = str[cur];
    str[cur] = str[end];
    str[end] = tmp;
    cur++;
    end--;
  }
}
void test()
{
  string str1;
  string str2;
  cin>>str1;
  cin>>str2;
  if(str1.size()<str2.size())
    swap(str1,str2);
  int k = str2.size() - 1;
  string res;
  int seat = 0;
  for(int i = str1.size()-1;i>=0;i--)
  {
    int tmp = (str1[i]-'0') + seat;
    if(k>=0)
      tmp += (str2[k--]-'0');
    if(tmp>9)
    {
      res.push_back((tmp-10)+'0');
      seat = 1;
      if(i==0)
        res.push_back('1');
    }
    else
    {
      res.push_back(tmp+'0');
      seat = 0;
    }
  }
  reverse(res);
  cout<<res;
}
int main()
{
  test();
}
// 1                                        1
// 2                                    1   1   1
// 3                                1   2   3   2   1
// 4                            1   3   6   7   6   3   1
// 5                        1   4   10  16  19  16  10  4   1
// 6                    1   5   15  30  45  51  45  30  15  5  1
// 7                 1   6   21  50  90 126 141 126  90  50  21 6  1
// 8            1    7   28  77 161  266 357 393
// 9         1  8    36  112 266 504  784 1016
// 10     1  9  45   156 514 882 1554
// 11   1  10 55 210  715 1552
// 12 1 11 66
