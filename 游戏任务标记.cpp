/*
��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ���������һ����1024��������ID��Χ[1,1024]��
����32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ���ʼ״̬����δ��ɡ� ����������������������ID��
��Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ� ���һ������������ڶ���ID������
�Ѿ�������1�����δ������0�������һ��ڶ���ID����[1,1024]��Χ�������-1��

��������:
�������һ��,����������ʾ����ID.

�������:
����Ƿ����

��������1:
1024 1024

�������1:
1
*/
#include<iostream>
using namespace std;
//��λͼ
/*int main()
{
    int id1 = 0,id2 = 0;
    cin>>id1>>id2;
    if(id1 > 1024 || id1 < 1 || id2 > 1024 || id2 < 1)
        cout<<-1<<endl;
    else if(id2 == id1)    cout<<1<<endl;
    else    cout<<0<<endl;
    return 0;
}*/
//λͼ˼��
int main()
{
    int id1 = 0,id2 = 0;
    cin>>id1>>id2;
    if(id1 > 1024 || id1 < 1 || id2 > 1024 || id2 < 1)
        cout<<-1<<endl;
    else if(id1 == 1024 && id2 == 1024)    cout<<1<<endl;
    else
    {
        unsigned int *p = new unsigned int[32];
        int tmp = id1 / (4 * 8);
        int idx = id1 % (4 * 8);
        int pos = 1<<idx;
        p[tmp] &= pos;
        int t = id2 / (4 * 8);
        int s = id2 % (4 * 8);
        int pos1 = 1<<s;
        if(p[tmp] == pos1)    cout<<1<<endl;
        else    cout<<0<<endl;
    }
}
