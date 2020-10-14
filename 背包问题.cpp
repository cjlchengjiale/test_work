/*有为N件物品，它们的重量w分别是w1,w2,...,wn，它们的价值v分别是v1,v2,...,vn，每件物品数量有且仅有一个，现在给你个承重为M的背包，
求背包里装入的物品具有的价值最大总和？
输入描述:
物品数量N=5件
重量w分别是2 2 6 5 4
价值v分别是6 3 5 4 6
背包承重为M=10

输出描述:
背包内物品最大总和为15

输入例子1:
5
10
2 2 6 5 4
6 3 5 4 6

输出例子1:
15
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int goods_num = 0;//货物总数
    int values_num = 0;//背包最大容量
    cin >> goods_num >> values_num;
    vector<int> goods(goods_num + 1, 0);//每个货物重量，下标1开始
    vector<int> values(values_num + 1, 0);//每个货物对应的价值，下标1开始
    for (int i = 1;i <= goods_num;i++)
    {
        cin >> goods[i];
    }
    for (int i = 1;i <= goods_num;i++)
    {
        cin >> values[i];
    }
    //dp数组
    vector<vector<int>> dp(goods_num + 1, vector<int>(values_num + 1,0));
    //初始化最后一行
    for (int i = values_num ;i > 0;i--)
    {
      //当背包容量大于当前物品重量放入背包种并且记录价值
        if (i  >= goods[goods_num])
            dp[goods_num][i] = values[goods_num];
    }
    //开始遍历剩下的goods_num - 1个物品
    for (int i = goods_num - 1;i > 0;i--)
    {
      //判断对应容量背包所可以存放的最大价值
        for (int j = 1;j <= values_num;j++)
        {
          //若当前背包容量小于该物品的重量，则继承下面已经存访的物品的价值
            if (j < goods[i])
                dp[i][j] = dp[i + 1][j];
          //否则，判断下面位置的背包减去当前物品重量后加上该武平价值和下面价值的最大值
            else
                dp[i][j] = max(dp[i + 1][j - goods[i]] + values[i], dp[i + 1][j]);
        }
    }
    cout << dp[1][values_num] << endl;
}
