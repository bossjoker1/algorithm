#include<iostream>
using namespace std;
int n, m;

typedef long long ll;

int A[100005], B[100005];

int main(){
    ll res = 0;
    ll A2 = 0, A4 = 0, B2 = 0, B4 = 0, tmp;
    cin>>n>>m;
    
    for(int i=0; i < n; i++){
        cin >> tmp;
        if (tmp % 4 == 0){
            A4 ++;
        }else if(tmp % 2 == 0){
            A2 ++;
        }
    }
    for(int i=0; i < m; i++){
        cin >> tmp;
        if (tmp % 4 == 0){
            B4 ++;
        }else if(tmp % 2 == 0){
            B2 ++;
        }
    }
//     cout<<"A2 : "<<A2<<" B2 : "<<B2<<endl;
//     cout<<"A4 : "<<A4<<" B4 : "<<B4<<endl; 
    res = A2 * B2 + A4 * m + B4 * n - A4 * B4 ;
    
    printf("%lld\n", res);

    return 0;
}

int cnt = mp[A[0]], res = 0, cur = 0;
    for (int i = 0; i < n - 1; i++){
        if (A[i+1] - A[cur] > k){
            
            if (mp[A[i+1]] >= cnt){
                res = cnt;
                cur = i+1;
            }
            cnt += mp[A[i+1]];
        }
    }