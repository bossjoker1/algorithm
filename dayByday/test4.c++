#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main() {
    int n;
    cin>>n;
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        mp[i+1] = temp;
    }
    int m = 0x7fffffff;
    for(int i = 0;i < n;i++){
        int flag = i+1, k = i+1;
        int count = 1;
        while(mp[k]!=flag){
//            cout<<k<<"->"<<mp[k]<<" ,";
            k = mp[k];
            count++;
            if(count >= n) break;
        }
        cout<<endl;
        m = min(m, count);
    }
    cout<<m;
}