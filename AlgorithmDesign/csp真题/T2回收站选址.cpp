#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 100005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

// 方向数组
int mp1[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1}, mp2[4][2] = {-1, -1, -1, 1, 1, 1, 1, -1};

map<pair<int, int>, int> cor;

int n, cnt[5];

int main(){

    n = read();
    int x, y;
    pair<int, int> temp;
    rep(i, 1, n){
        x = read(), y = read();
        cor[make_pair(x, y)] = 1;
    }
    bool flag;
    for(auto& t:cor){
        flag = true;
        x = t.first.first, y = t.first.second;
        rep(i, 0, 3){
            if(cor.find(make_pair(x+mp1[i][0], y+mp1[i][1])) == cor.end()){
                flag = false;
                break;
            }
        }
        if(flag){
            int count = 0;
            rep(i, 0, 3){
                if(cor.find(make_pair(x+mp2[i][0], y+mp2[i][1]))!=cor.end())
                    count++;
            }
            cnt[count]++;
        }
    }

    rep(i, 0, 4){
        printf("%d\n", cnt[i]);
    }

    return 0;
}