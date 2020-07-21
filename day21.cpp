#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Ï´ÅÆ
void test()
{
  int t = 0;
  while(cin>>t)
  {
    for(int i = 0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> vec;
        for(int j = 0;j<2*n;j++)
        {
            int tmp = 0;
            cin>>tmp;
            vec.push_back(tmp);
        }
        while(k)
        {
            int count = 0;
            int end = n;
            vector<int> cur = vec;
            vec.clear();
            while(end<=2*n-1)
            {
                int num1 = cur[count];
                int num2 = cur[end];
                vec.push_back(num1);
                vec.push_back(num2);
                end++;
                count++;
            }
            cur.clear();
            k--;
        }
        for(int p = 0;p<vec.size();p++)
        {
            if(p == vec.size() - 1)
                cout<<vec[p];
            else
                cout<<vec[p]<<" ";
        }
        cout<<endl;
    }
  }
}
//Ê¶±ðÄ³Ò»Ò³¸èÇú
void small_song(int n,string str)
{
    int number = 1;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i] == 'U')
        {
            if(number == 1)
                number = n;
            else
                number--;
        }
        if(str[i] == 'D')
        {
            if(number == n)
                number = 1;
            else
                number++;
        }
    }
    for(int i = 1;i<=n;i++)
        cout<<i<<" ";
    cout<<endl;
    cout<<number<<endl;
}
void big_song(int n,string str)
{
    int begin = 0;
    int end = 3;
    int number = 1;
    vector<int> num;
    for(int i = 1;i<=n;i++)
        num.push_back(i);
    for(int i = 0;i<str.size();i++)
    {
        if(str[i] == 'U')
        {
            if(number == 1&&begin == 0&&end == 3)
            {
                number = n;
                begin = num.size() - 4;
                end = num.size() - 1;
            }
            else
            {
                number--;
                if(number == begin)
                {
                    begin--;
                    end--;
                }
            }
            //cout<<begin<<"----"<<end;
        }
        if(str[i] == 'D')
        {
            if(number == n&&begin==num.size() - 4&&end == num.size() - 1)
            {
                number = 1;
                begin = 0;
                end = 3;
            }
            else
            {
                number++;
                if(number == end + 2)
                {
                    begin++;
                    end++;
                }
            }
        }
    }
    for(int i = begin;i<=end;i++)
        cout<<num[i]<<" ";

    cout<<endl;
    cout<<number<<endl;
}
void test1()
{
    int num = 0;
    while(cin>>num){
        string order;
        cin>>order;
        if(num<=4)
            small_song(num,order);
        else
            big_song(num,order);
    }
}
int main()
{
    test();
}
