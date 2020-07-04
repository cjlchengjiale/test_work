#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
//最长子序列
class soultion
{
public:
    soultion(string str)
        :_str(str)
        {}
    void max_length_str()
    {
        int size = _str.size();
        int start = 0;
        int finish = 1;
        int tmp = 0;
        int str_size = 1;
        int max = 0;
        for(int i = 0;i<size;)
        {
          str_size = 1;
          while(_str[finish] - _str[tmp]==1&&finish<size)
          {
            str_size++;
            finish++;
            tmp++;
          }
          if(str_size>max)
          {
            start = i;
            max = str_size;
          }
          i+=str_size;
          tmp = finish;
          finish++;
        }
        //cout<<start<<" "<<max<<endl;
        print_max_str(start,max);
    }
    void print_max_str(int start,int size)
    {
      int seat = start;
      for(int i = start;i<seat + size;i++)
      {
        cout<<_str[i];
      }
      cout<<endl;
    }
public:
    string _str;
};
int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        int tmp = size/2;
        int half_size = 1;
        int flag = 0;
        vector<int>::iterator sit = numbers.begin();
        vector<int>::iterator eit = numbers.end();
        sort(sit,eit);
        for(auto& ch:numbers)
          cout<<ch<<" ";
        cout<<endl;
        vector<int>::iterator it = numbers.begin();
        vector<int>::iterator cit = it + 1;
        if(size==1)
        {
          flag = 1;
          cout<<1000<<endl;
        }
        else
        {
          while(it != numbers.end())
          {
              while(*it == *cit&&cit != numbers.end())
              {
                  cit++;
                  half_size++;
              }
              cout<<*it<<"---++++---"<<*cit<<"..."<<half_size<<endl;
              if(half_size>tmp)
              {
                  flag = 1;
                  cout<<*it<<"------"<<*cit<<endl;
                  cout<<tmp<<"+++++"<<half_size<<endl;
                  cout<<*it<<endl;
                  break;
              }
              half_size = 1;
              it = cit;
              if(cit != numbers.end())
                  cit++;
          }
        }
        if(flag == 0)
            cout<<300<<endl;
    }
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
            int size = numbers.size();
            int tmp = size/2;
            int half_size = 1;
            int flag = 0;
            vector<int>::iterator sit = numbers.begin();
            vector<int>::iterator eit = numbers.end();
            sort(sit,eit);
            //for(auto& ch:numbers)
              //cout<<ch<<" ";
            //cout<<endl;
            vector<int>::iterator it = numbers.begin();
            vector<int>::iterator cit = it + 1;
            if(size==1)
            {
              flag = 1;
              return 0;
            }
            else
            {
              while(it != numbers.end())
              {
                  while(*it == *cit&&cit != numbers.end())
                  {
                      cit++;
                      half_size++;
                  }
                  //cout<<*it<<"---++++---"<<*cit<<"..."<<half_size<<endl;
                  if(half_size>tmp)
                  {
                      flag = 1;
                      //cout<<*it<<"------"<<*cit<<endl;
                      //cout<<tmp<<"+++++"<<half_size<<endl;
                      return *it;
                      break;
                  }
                  half_size = 1;
                  it = cit;
                  if(cit != numbers.end())
                      cit++;
              }
            }
            if(flag == 0)
                return 0;
        }
int MoreThanHalfNum_Solution1(vector<int> numbers){
  int size = numbers.size();
  int tmp = size/2;
  int num[size];
  int flag = 0;
  memset(num,0,sizeof(num));
  for(int i =0;i<size;i++)
  {
    num[numbers[i]]++;
    if(num[numbers[i]] > tmp)
    {
      flag = 1;
      cout<<numbers[i]<<endl;
      break;
    }
  }
  if(flag == 0)
    cout<<0<<endl;
}
int test()
{
  int i ,j,k = 0;
  for(i = 0,j = -1;j = 0;i++,j++)
  {
    cout<<i<<" "<<j;
    k++;
  }
    cout<<i<<" "<<j;
  return k;
}
void test1()
{
  int i = 8;
  char *p;
  char a[10] = {'1','2','3','4','5','6','7','8','9',0};
  p = a+i;
  cout<<a<<endl;
}
int main()
{
    // string str;
    // getline(cin,str);
    // soultion idea(str);
    // idea.max_length_str();
    //int num[] = {1,2,2,2,2,2,2,2,2,2,2,2,2,3,6,5,2,2,2,2,2,2,2,3,6,5,2,1,4,8,9,5,2,3,5,2,6,3,1,2,2,2,2,2,2,3,6,5,2,1,4,8,9,5,2,3,5,2,6,3,1,2,2,2,2,2,2,3,6,5,2,1,4,8,9,5,2,3,5,2,6,3,1,2,2,2,2,2,2,3,6,5,2,1,4,8,9,5,2,3,5,2,6,3};
    // int num[] ={1};
    // vector<int> n(num,num+sizeof(num)/sizeof(int));
    // cout<<MoreThanHalfNum_Solution2(n)<<endl;
    test1();
}
