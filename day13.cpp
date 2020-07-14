#include<iostream>
using namespace std;
class Date
{
public:
    Date(int year = 1,int month = 1,int day = 0)
        :_year(year),
        _month(month),
        _day(day)
        {

        }
    int getdays(int year,int month)
    {
        int num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(month==2&&(((year%4==0)&&(year%100!=0))||year%400==0))
            num[month]++;
        return num[month];
    }
    int whichday()
    {
        int day = 0;
        day+=_day;
        int month = 1;
        while(month!=_month)
        {
            day+=getdays(_year,month);
            month++;
        }
        return day;
    }
private:
    int _year;
    int _month;
    int _day;
};
void test()
{
    int n = 0;
    int con = 0;
    int sum = 0;
    int tmp = 0;
    int sul = 1;
    cin>>n;
    int num[n];
    for(int i = 0;i<n;i++)
        cin>>num[i];
    while(con != n)
    {
        for(int j = 0;j<n;j++)
        {
            if(j == con)
                continue;
            else
            {
                tmp+=num[j];
                sul*=num[j];
            }
        }
        if(tmp > sul)
        {
            sum++;
            tmp = 0;
            sul = 0;
        }
        con++;
    }
    cout<<sum<<endl;
}
int main()
{
    // int y,m,d;
    // cin>>y>>m>>d;
    // Date d1(y,m,d);
    // cout<<d1.whichday()<<endl;
    test();
    return 0;
}
