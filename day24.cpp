#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
//动态规划
class Bonus {
public:
    int find_road(vector<vector<int> > board)
    {
        memset(max_num,0,sizeof(max_num));
        max_num[0][0] = board[0][0];
        for(int i = 1;i<6;i++)
            max_num[0][i] = max_num[0][i-1] + board[0][i];
        for(int i = 1;i<6;i++)
            max_num[i][0] = max_num[i-1][0] + board[i][0];
        for(int i = 1;i<6;i++)
        {
            for(int j = 1;j<6;j++)
            {
                max_num[i][j] = max(max_num[i-1][j],max_num[i][j-1]) + board[i][j];
            }
        }
        return max_num[5][5];
    }
    int getMost(vector<vector<int> > board) {
        // write code here
        return find_road(board);
    }
public:
    int max_num[6][6];
};
//迷宫问题
class labyrinth
{
public:
  labyrinth(int n,int m)
    :_row(n)
    ,_col(m)
  {
    _map.clear();
    res.clear();
    best.clear();
  }
  void map_init()
  {
    _map.resize(_row);
    for(int i = 0;i<_row;i++)
    {
      _map[i].resize(_col);
      for(int j = 0;j<_col;j++)
      {
        cin>>_map[i][j];
      }
    }
  }
  void find(int i,int j)
  {
    // cout<<12345678<<endl;
    cout<<i<<"----"<<j<<endl;
    _map[i][j] = 1;
    res.push_back({i,j});
    if(i == _row - 1&&j == _col - 1)
    {
      cout<<123456<<endl;
      if(best.empty()||res.size()<best.size())
        best = res;
    }
    if(i - 1>=0&&_map[i - 1][j] == 0) find(i - 1,j);
    if(i + 1<_row&&_map[i + 1][j] == 0) find(i + 1,j);
    if(j - 1>=0&&_map[i][j - 1] == 0) find(i,j - 1);
    if(j + 1<_col&&_map[i][j + 1] == 0) find(i,j + 1);
    _map[i][j] = 0;
    res.pop_back();
  }
  void print()
  {
    for(int i = 0;i<best.size();i++)
    {
      cout<<best[i].first<<" "<<best[i].second<<endl;
    }
  }
public:
  vector<vector<int>> _map;
  int _col;//列
  int _row;//行
  vector<pair<int,int>> res;
  vector<pair<int,int>> best;
};
void test()
{
  int n,m;
  cin>>n>>m;
  labyrinth sl(n,m);
  sl.map_init();
  sl.find(0,0);
  sl.print();
}
int main()
{
  test();
}
// 5 5
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 0
// 0 1 1 1 0
// 0 0 0 1 0
