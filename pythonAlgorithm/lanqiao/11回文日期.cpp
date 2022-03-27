// 直接从年份入手

#include <iostream>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//check函数用来检查得到的日期是否合法 
bool check(int date)
{
	int year = date/10000;
	int month = (date/100)%100;
	int day = date%100;
	if(month < 0 || month > 12) return false;
	if(day == 0 || month != 2 && day > days[month]) return false;
	if(month==2)
	{
		int leap = year%4==0&&year%100!=0||year%400==0;
		if(day>days[month]+leap) return false;
	}
	return true;	
}

int main()
{
	int N;
	int date1,date2;
	cin>>N;
	int year = N/10000;
	for(int i=year;;++i)
	{
		date1=i;
		int x=i;
		for(int j=0;j<4;++j)
		{
			date1 = date1*10+x%10;
			x/=10;
		}
		if(date1>N&&check(date1)) 
		{
			cout<<date1<<endl;
			break;
		}
	}
  
	int ab=N/1000000;
	for(int i=ab;;++i)
	{
	int a=i/10;
	int b=i%10;
	int x=b*10+a;
	date2 = i*1000000+ i*10000 +x*100 +x;
	if(date2>N&&check(date2)) 
	{
		cout<<date2<<endl;
		break;
	}
	}
	return 0;
}
