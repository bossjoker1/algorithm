#include <stdio.h>

typedef long long ll;


int main() {
    int n;
    ll c;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld",&c);
        ll res = 2*c*c - c + 1;
        printf("%lld\n", res);
        
    }
    return 0;
}