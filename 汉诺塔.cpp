#include<iostream>
using namespace std;
int tmp;//记录挪动次数
void han_nuo(char A,char B,char C,int n)
{
  if(n == 1)//当剩下最大盘子时，挪到C处
  {
    cout<<A<<"--->"<<C<<endl;
    tmp++;
  }
  else
  {
    han_nuo(A,C,B,n-1);//A中除最大盘子外其余所有盘子通过C挪到B
    tmp++;
    cout<<A<<"--->"<<C<<endl;
    han_nuo(B,A,C,n-1);//当最大盘子已经到C后，其余盘子通过A挪到C即可
  }
}
int main()
{
  int n = 0;
  cin>>n;
  han_nuo('A','B','C',n);
  cout<<tmp<<endl;
  return 0;
}
