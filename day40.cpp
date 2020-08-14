// write your code here cpp
#include<stack>
#include<iostream>
#include<string>
using namespace std;
void test()
{
    int n = 0;
    while(cin>>n)
    {
        getchar();
        string str;
        getline(cin,str);
        int size = str.size();
        stack<int> st;
        //cout<<str<<endl;
        for(int i = 0;i<size;i++)
        {
            if(str[i] == ' ') continue;
            if(str[i]-'0'>=0&&str[i]-'0'<=9){
                int num = 0;
                while(i<size&&str[i] != ' ')
                {
                    num = num*10+str[i] - '0';
                    i++;
                }
                cout<<num<<endl;
                st.push(num);
            }
            if(str[i] == '+')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                n1+=n2;
                //cout<<n1;
                st.push(n1);
            }
            if(str[i] == '-')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                n2-=n1;
                st.push(n2);
            }
            if(str[i] == '*')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                n1*=n2;
                st.push(n1);
            }
            if(str[i] == '/')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                n2/=n1;
                st.push(n2);
            }
        }
        int ans = st.top();
        st.pop();
        cout<<ans<<endl;
    }
}
int main()
{
    test();
}
