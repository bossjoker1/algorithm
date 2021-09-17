#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    string s = "asdaaaad";
    int sum  = s.size();
    for(int i = 1; i < s.size();i++){
        int temp = 0;
        for(int k = 0; k < min(i, (int)(s.size()-i-1));k ++){
            if(s[0+k] == s[i+k]){
                temp++;
            }
        }
        cout<<temp<<" ";
        sum+=temp;
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}