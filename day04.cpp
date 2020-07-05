#include<iostream>
using namespace std;
//进制转化0~16进制
int main()
{
    int num = 0,n = 0;
    cin>>num>>n;
    if(n<=9)
    {
      cout<<"123"<<endl;
        char nums[1024] = {0};
        int k = 0;
        while(num)
        {
            int tmp = num%n;
            cout<<tmp<<"====="<<endl;
            num/=n;

            nums[k++] = tmp+'0';
            cout<<nums[k-1]<<"--------"<<endl;
        }
        for(int i = k-1;i>=0;i--)
        {
            cout<<nums[i];
        }
    }
    else
    {
        char word[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        char nums[1024] = {0};
        int k = 0;
        while(num)
        {
            int tmp = num%n;
            nums[k++] = word[tmp];
            num/=n;
        }
        for(int i = k-1;i>=0;i--)
        {
            cout<<nums[i];
        }
    }
}
// int main()
// {
//   int a[5] = {1,3,5,7,9};
//   int *p = (int *)(&a+1);
//   cout<<*(a+1)<<" "<<*(p-1)<<endl;
// }
