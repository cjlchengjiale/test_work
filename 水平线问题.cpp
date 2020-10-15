/*

伞屉国是一个以太阳能为主要发电手段的国家，因此他们国家中有着非常多的太阳能基站，链接着的基站会组合成一个发电集群。
但是不幸的是伞屉国不时会遭遇滔天的洪水，当洪水淹没基站时，基站只能停止发电，同时被迫断开与相邻基站的链接。你作为
伞屉国的洪水观察员，有着这样的任务：在洪水到来时，计算出发电集群被洪水淹没后被拆分成了多少个集群。

由于远古的宇宙战争的原因，伞屉文明是一个二维世界里的文明，所以你可以这样理解发电基站的位置与他们的链接关系：给你
一个一维数组a，长度为n，表示了n个基站的位置高度信息。数组的第i个元素a[i]表示第i个基站的海拔高度是a[i],而下标相
邻的基站才相邻并且建立链接，即x号基站与x-1号基站、x+1号基站相邻。特别的，1号基站仅与2号相邻，而n号基站仅与n-1号
基站相邻。当一场海拔高度为y的洪水到来时，海拔高度小于等于y的基站都会被认为需要停止发电，同时断开与相邻基站的链接。


输入描述：

每个输入数据包含一个测试点。

第一行为一个正整数n，表示发电基站的个数 (0 < n <= 200000)

接下来一行有n个空格隔开的数字，表示n个基站的海拔高度，第i个数字a[i]即为第i个基站的海拔高度，对于任意的i(1<=i<=n),有(0 <= a[i] < 2^31-1)

接下来一行有一个正整数q(0 < q <= 200000)，表示接下来有q场洪水

接下来一行有q个整数，第j个整数y[j]表示第j场洪水的海拔为y[j],对于任意的j(1<=j<=n),有(-2^31 < y[j] < 2^31-1)

输出描述：
输出q行，每行一个整数，第j行的整数ans表示在第j场洪水中，发电基站会被分割成ans个集群。标准答案保证最后一个整数后也有换行。

示例：
输入
10
6 12 20 14 15 15 7 19 18 13
6
15 23 19 1 17 24

输出
2
0
1
1
2
0
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int house_num = 0;//房屋数量
    cin>>house_num;
    vector<pair<int,int>> house(house_num + 2,{0,0});//前后各加一个房子防止越界
    for(int i = 1;i<house_num + 1;i++)
    {
        cin>>house[i].first;//记录房子高度
        house[i].second = i;//记录房子额下标
    }
    int flood_num;//记录洪水得场数
    cin>>flood_num;
    vector<pair<int,int>> flood(flood_num,{0,0});//记录洪水的高度和下标
    for(int i = 0;i<flood_num;i++)
    {
        cin>>flood[i].first;
        flood[i].second = i;//记录洪水下标
    }
    sort(house.begin() + 1,house.end() - 1);//房屋高度排序
    sort(flood.begin(),flood.end());//洪水高度排序

    vector<int> station(house_num + 2,0);//记录当前房屋是否被冲毁得状态  0表示没被冲毁 1表示被洪水冲毁
    vector<int> result(flood_num,0);//记录对应洪水将房屋冲过后的房子集群数
    station[0] = station[house_num + 1] = 1;//首位房屋表示冲毁
    int count = 1;//记录当前的集群数
    int tmp = 1;//记录每波洪水冲毁的最后一幢房屋的位置
    int k = 0;//遍历数目
    for(int i = 0;i<flood_num;i++)
    {
        for(k = tmp;k<=house_num;k++)
        {
          //表示冲毁当前房屋
            if(flood[i].first >= house[k].first)
            {
                station[house[k].second] = 1;//标记为1表示冲毁
                //两边都未被冲毁，集群数++
                if(station[house[k].second - 1] == 0 && station[house[k].second + 1] == 0)
                    count++;
                //两边都被冲毁，集群数--
                else if(station[house[k].second - 1] == 1 && station[house[k].second + 1] == 1)
                    count--;
            }
            //当前房屋之后的都不能被冲毁
            else
            {
                tmp = k;//记录该位置
                result[flood[i].second] = count;//赋给对应洪水位置的房屋集群数
                break;
            }
        }
    }
    //输出答案
    for(auto& e:result)
        cout<<e<<endl;
    return 0;
}
