#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int maxnum(vector<long> &n)
{
    //vector<long> n(num,num + size);
    int sum = 0;
    vector<long> arr = n;
    // for(auto& ch:arr)
    //   cout<<ch;
    vector<long>::iterator it = arr.begin();
    vector<long>::iterator cit = it;
    int flag = 0;
    while(it != arr.end())
    {
      cit++;
      if(*it < *cit)
      {
        flag = 2;
      }
      else
        flag = 1;
      if(flag == 2)
      {
        while(*it<=*cit&&cit != arr.end())
        {
          it++;
          cit++;
        }
        sum++;
      }
      if(flag == 1)
      {
        while(*it>=*cit&&cit != arr.end())
        {
          it++;
          cit++;
        }
        sum++;
      }
      it = cit;
    }
    return sum;
}
int main()
{
  int n = 0;
      cin>>n;
      long num[n];
      int sum = 0;
      int size = 0;
      for(int i = 0;i < n ;i++)
      {
          cin>>num[i];
      }
      size  = sizeof(num)/sizeof(long);
      vector<long> arr(num,num + size);
      cout<<maxnum(arr)<<endl;
      //test();
}
//
//
// void reservechar(char* ch,int begin,int end)
// {
//   while(begin<=end)
//   {
//     char a = ch[begin];
//     ch[begin] = ch[end];
//     ch[end] = a;
//     begin++;
//     end--;
//   }
// }
// char * reverseWords(char * s){
//   char *result = (char*)malloc(sizeof(char)*strlen(s));
//   int i = 0;
//   int size = strlen(s);
//   strcpy(result,s);
//   cout<<result<<endl;
//    int cur = 0;
//    int prev = 0;
//    while(result[cur]!='\0')
//    {
//      cur++;
//      if(result[cur]==' ')
//     {
//       prev = cur + 1;
//       continue;
//     }
//      if(result[cur + 1]==' '||result[cur + 1]=='\0')
//      {
//        reservechar(result,prev,cur);
//        prev = cur + 2;
//      }
//    }
//    //cout<<result<<endl;
//    return result;
// }
// void test()
// {
//   char *p;
//   string n;
//   getline(cin,n);
//   string cpy(n);
//   string::reverse_iterator rit = n.rbegin();
//   int k = 0;
//   // for(auto& ch:cpy)
//   //   cout<<ch;
//   // cout<<endl;
//   while(rit != n.rend())
//   {
//     cpy[k] = *rit;
//     k++;
//     rit++;
//   }
//   for(auto& ch:cpy)
//     cout<<ch;
//   cout<<endl;
//   string::iterator it = cpy.begin();
//   string::iterator cit = it;
//   string::iterator tmp;
//   while(it != cpy.end())
//   {
//     while(*(cit+1)!=' '&&cit+1!=cpy.end())
//     {
//       //cout<<*cit;
//       cit++;
//     }
//     //cout<<endl;I like beijing.
//     tmp = cit + 1;
//     if(tmp != cpy.end())
//       tmp++;
//     cout<<*it<<"-----"<<*cit<<endl;
//     while(it <= cit)
//     {
//       if(it == cit)
//         break;
//       cout<<*it<<"  change to  "<<*cit<<endl;
//       char p = *it;
//       *it = *cit;
//       *cit = p;
//       it++;
//       cit--;
//     }
//     it = tmp;
//     cit = tmp;
//     if(it+1 == cpy.end()||it==cpy.end())
//       break;
//   }
//   //cout<<n.size()<<endl;
//   for(auto& ch:cpy)
//     cout<<ch;
// }
// int main()
// {
//     // int n = 0;
//     // cin>>n;
//     // long num[n];
//     // int sum = 0;
//     // int size = 0;
//     // for(int i = 0;i < n ;i++)
//     // {
//     //     cin>>num[i];
//     // }
//     // size  = sizeof(num)/sizeof(long);
//     // vector<long> arr(num,num + size);
//     // cout<<maxnum(arr)<<endl;;
//     test();
// }
