#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef vector<ll> vec;

int main() {

    int n, res = -1;
    scanf("%d", &n);

    vector<vector<int>> triangle(n);
    vector<int> dp(n, 0);

    for(int i = 0; i < n ; i++ ){
        for(int j = 0; j <= i; j++){
            int temp;
            scanf("%d", &temp);
           // cout<<temp<< " ";
            triangle[i].push_back(temp);
        }
       // cout<<endl;
    }
    dp[0] = triangle[0][0];

    for(int i = 1; i < n; i++ ){
		dp[i] = dp[i-1] + triangle[i][i];
		for (int j = i - 1; j > 0; j--) {
			dp[j] = max(dp[j], dp[j-1]) + triangle[i][j];
		}
		dp[0] += triangle[i][0];
	}

	for(int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}

    printf("%d\n", res);
    
    return 0;
}