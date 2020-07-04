#include<iostream>
using namespace std;
//Ñ°ÕÒ×î¼ÑÓÅÏÈÊý
int main()
{
    long n = 0;
    cin>>n;
    long m = n*3;
    long num[m] = {0};
    long add = 0;
    long a = 0;
    long b = m;
    for(long i = 0;i<m;i++)
    {
        cin>>num[i];
    }
    for(long i = 0;i<m;i++)
    {
        for(long j = i;j<m;j++)
        {
            if(num[j]<num[i])
            {
               long tmp = num[j];
               num[j] = num[i];
                num[i] = tmp;
           }
        }
   }
    for(a,b;a<b;a++)
    {
      b-=2;
      add+=num[b];
    }
   cout<<endl;
    cout<<add<<endl;
}
//É¾³ýÖØ¸´×Ö·û
void test()
{
   string str;
   string cp;
   getline(cin,str);
   getline(cin,cp);
   string::iterator it = str.begin();
   string::iterator cit = cp.begin();
   while(it!= str.end())
   {
      cout<<*it<<endl;
     while(cit != cp.end())
     {
       if(*it == *cit)
       {
         it = str.erase(it);
         it--;
         cout<<*it<<endl;
         cit = cp.begin();
         break;
       }
       cit++;
     }
     cit = cp.begin();
     if(it == str.end())
       break;
     it++;
   }
   for(int i = 0;i<str.size();i++)
   {
     cout<<str[i];
   }
   cout<<endl;
}
