#include<iostream>
using namespace std;
int tmp;//��¼Ų������
void han_nuo(char A,char B,char C,int n)
{
  if(n == 1)//��ʣ���������ʱ��Ų��C��
  {
    cout<<A<<"--->"<<C<<endl;
    tmp++;
  }
  else
  {
    han_nuo(A,C,B,n-1);//A�г����������������������ͨ��CŲ��B
    tmp++;
    cout<<A<<"--->"<<C<<endl;
    han_nuo(B,A,C,n-1);//����������Ѿ���C����������ͨ��AŲ��C����
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
