/*
题目描述
合法的括号匹配序列被定义为:
1. 空串""是合法的括号序列
2. 如果"X"和"Y"是合法的序列,那么"XY"也是一个合法的括号序列
3. 如果"X"是一个合法的序列,那么"[X]"也是一个合法的括号序列
4. 每个合法的括号序列都可以由上面的规则生成
例如"", "[]", "[][][]", "[[][]]", "[[[[]]]]"都是合法的。
牛牛现在给出一个括号序列s,牛牛允许你执行的操作是:在s的开始和结尾处添加
一定数量的左括号('[')或者右括号(']')使其变为一个合法的括号匹配序列。
牛牛希望你能求出添加最少的括号之后的合法的括号匹配序列是什么。
示例
输入
][

输出
[][]
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
  string str;
  cin>>str;
  stack<char> st;
  for(int i = 0;i<str.size();i++){
    //如果是右括号
    if(str[i] == ']')
    {
      //栈围殴空，则入栈
      if(st.size() == 0)
      {
        st.push(str[i]);
      }
      //否则判断栈顶元素是否为左括号
      else
      {
        //若是则出栈
        if(st.top() == '[')
        {
          st.pop();
        }
        //不是则当前括号入栈
        else
          st.push(str[i]);
      }
    }
    //如果是左括号则入栈
    else
      st.push(str[i]);
  }
  //记录左右括号个需要添加的个数
  int left = 0,right = 0;
  while(st.size())
  {
    if(st.top() == ']') left++;
    else  right++;
    st.pop();
  }
  //cout<<left<<" "<<right;
  for(int i = 0;i<left;i++)
    cout<<"[";
  cout<<str;
  for(int i = 0;i<right;i++)
    cout<<"]";
  cout<<endl;
  return 0;
}
