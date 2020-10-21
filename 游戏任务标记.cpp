/*
游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。
请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，
需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务
已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。

输入描述:
输入包括一行,两个整数表示人物ID.

输出描述:
输出是否完成

输入例子1:
1024 1024

输出例子1:
1
*/
#include<iostream>
using namespace std;
//非位图
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
//位图思想
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
