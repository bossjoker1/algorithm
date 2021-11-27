#include<bits/stdc++.h>
using namespace std;
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int year, month, day, cnt=0;
bool isRun;

// 没什么意思，简单判断下就行了

int main(){
    year = read(), month = read(), day = read();
    if((year%4==0&&year%100!=0) || year%400==0) isRun = true;

    if(month > 12){
        month = month % 10; // 得到个位
        if(month == 0) month = 10;
        if(month == 2) month = 12;
        cnt++;
    }

    if(month == 0){
        month = 1; cnt++;
    }

    if(month == 2){
        if(isRun) {
            if(day > 29 || day < 1) cnt++;
        }else{
            if(day > 28 || day < 1) cnt++;
        }
    }

    if(month <= 7 && month != 2){
        if(month % 2 == 0){
            if(day > 30 || day < 1) cnt++;
        }else{
            if(day > 31 || day < 1) cnt++;
        }
    }

    if(month >= 8 && month <= 12){
        if(month % 2 == 0){
            if(day > 31 || day < 1) cnt++;
        }else{
            if(day > 30 || day < 1) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}