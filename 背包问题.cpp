/*��ΪN����Ʒ�����ǵ�����w�ֱ���w1,w2,...,wn�����ǵļ�ֵv�ֱ���v1,v2,...,vn��ÿ����Ʒ�������ҽ���һ�������ڸ��������ΪM�ı�����
�󱳰���װ�����Ʒ���еļ�ֵ����ܺͣ�
��������:
��Ʒ����N=5��
����w�ֱ���2 2 6 5 4
��ֵv�ֱ���6 3 5 4 6
��������ΪM=10

�������:
��������Ʒ����ܺ�Ϊ15

��������1:
5
10
2 2 6 5 4
6 3 5 4 6

�������1:
15
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int goods_num = 0;//��������
    int values_num = 0;//�����������
    cin >> goods_num >> values_num;
    vector<int> goods(goods_num + 1, 0);//ÿ�������������±�1��ʼ
    vector<int> values(values_num + 1, 0);//ÿ�������Ӧ�ļ�ֵ���±�1��ʼ
    for (int i = 1;i <= goods_num;i++)
    {
        cin >> goods[i];
    }
    for (int i = 1;i <= goods_num;i++)
    {
        cin >> values[i];
    }
    //dp����
    vector<vector<int>> dp(goods_num + 1, vector<int>(values_num + 1,0));
    //��ʼ�����һ��
    for (int i = values_num ;i > 0;i--)
    {
      //�������������ڵ�ǰ��Ʒ�������뱳���ֲ��Ҽ�¼��ֵ
        if (i  >= goods[goods_num])
            dp[goods_num][i] = values[goods_num];
    }
    //��ʼ����ʣ�µ�goods_num - 1����Ʒ
    for (int i = goods_num - 1;i > 0;i--)
    {
      //�ж϶�Ӧ�������������Դ�ŵ�����ֵ
        for (int j = 1;j <= values_num;j++)
        {
          //����ǰ��������С�ڸ���Ʒ����������̳������Ѿ���õ���Ʒ�ļ�ֵ
            if (j < goods[i])
                dp[i][j] = dp[i + 1][j];
          //�����ж�����λ�õı�����ȥ��ǰ��Ʒ��������ϸ���ƽ��ֵ�������ֵ�����ֵ
            else
                dp[i][j] = max(dp[i + 1][j - goods[i]] + values[i], dp[i + 1][j]);
        }
    }
    cout << dp[1][values_num] << endl;
}
