/*
有n个房间，现在i号房间里的人需要被重新分配，分配的规则是这样的：先让i号房间里的人全都出来，接下来按照 i+1, i+2, i+3, ...
的顺序依此往这些房间里放一个人，n号房间的的下一个房间是1号房间，直到所有的人都被重新分配。

现在告诉你分配完后每个房间的人数以及最后一个人被分配的房间号x，你需要求出分配前每个房间的人数。
数据保证一定有解，若有多解输出任意一个解。

输入描述:
第一行两个整数n, x (2<=n<=10^5, 1<=x<=n)，代表房间房间数量以及最后一个人被分配的房间号；
第二行n个整数 a_i(0<=a_i<=10^9) ，代表每个房间分配后的人数。


输出描述:
输出n个整数，代表每个房间分配前的人数。
示例1

输入
3 1
6 5 1

输出
4 4 4

*/
#include<iostream>
#include<vector>
#include<cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0,x = 0;
    cin>>n>>x;
    vector<long long> vec(n,0);
    for(int i = 0;i<n;i++)
        cin>>vec[i];
    x-=1;//x号房间对应下标为x-1
    //房间人数最少的一定是被分配出去的房间号
    long long min_val = *min_element(vec.begin(),vec.end());//求出这些房间中最少的房间人数
    long long tmp = min_val * vec.size();//记录一共分配了多少人数，每次是从头到尾
    for(auto & ch:vec)    ch-=min_val;//对应每个房间减少相应的人数
    //开始找分配的i号房间
    while(--vec[x] >=0)
    {
        if(x == 0)    x = n-1;
        else    x--;
        tmp++;//记录这一轮中分配出去的人数
    }
    vec[x] = tmp;//tmp为分配的总人数
    for(auto&e:vec)    cout<<e<<" ";
    cout<<endl;
}
