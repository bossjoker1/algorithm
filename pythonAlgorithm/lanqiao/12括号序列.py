# woc 太复杂了
# 贴个c题解

# #include<bits/stdc++.h>
# using namespace std;
# #define ll long long
# #define pii pair<int,int>
# #define pb push_back
# #define mp make_pair
# #define vi vector<int>
# #define vll vector<ll>
# #define fi first
# #define se second
# const int maxn = 5000 + 5;
# const int mod = 1e9 + 7;
# int n;
# int dp[maxn][maxn];
# string a ;
# ll calc ()
# {
#     memset(dp , 0 , sizeof dp);
#     dp[0][0] = 1;
#     for (int i = 1 ; i <= n ; i++){
#         if (a[i - 1] == '('){
#             for (int j = 1 ; j <= n ; j++)
#                 dp[i][j] = dp[i - 1][j - 1];
#         }else {
#             dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
#             for (int j = 1 ; j <= n ; j++)
#                 dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % mod;
#         }
#     }
#     for (int i = 0 ; i <= n ; i++) if (dp[n][i]) return dp[n][i];
#     return -1;
# }
# int main()
# {
#     ios::sync_with_stdio(false);
#     cin >> a;
#     n = a.size();
#     ll l = calc();
#     reverse(a.begin() , a.end());
#     for (auto &g : a) if (g == '(') g = ')'; else g = '(';
#     ll r = calc();
#     cout << l * r % mod << endl;
#     return 0;
# }
