#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define maxn 100005

typedef long long ll;

inline int max(int x, int y) { return x > y ? x : y; }

struct ip
{
    ll b[5], type, bitSum[33];
}ips[maxn];

int n, m, cnt[6], k, l, r;
vector<int> A[33], B[33], C[33], D[33], E[33];

int getType(ip i) {
    if (i.b[1] >= 0 && i.b[1] <= 127) {
        return 1;
    }
    else if (i.b[1] >= 128 && i.b[1] <= 191) {
        return 2;
    }
    else if (i.b[1] >= 192 && i.b[1] <= 223) {
        return 3;
    }
    else if (i.b[1] >= 224 && i.b[1] <= 239) {
        return 4;
    }
    else {
        return 5;
    }
}

inline int read() {
    ll x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

// 踩了upper_bound和lower_bound的坑，这俩千万不要在一行写
int main() {
    n = read(), m = read();

    rep(i, 1, n) {
        ips[i].b[1] = read(), ips[i].b[2] = read(), ips[i].b[3] = read(), ips[i].b[4] = read();
        ips[i].type = getType(ips[i]);
        // 计算每个ip地址前k位的和并保存
        rep(k, 0, 31) {
            ips[i].bitSum[k + 1] = (ips[i].b[k / 8 + 1] >> (7 - (k % 8)) & 1) + (ips[i].bitSum[k] << 1);

            switch (ips[i].type)
            {
            case 1:
                A[k+1].push_back(ips[i].bitSum[k+1]);
                break;
            case 2:
                B[k+1].push_back(ips[i].bitSum[k+1]);
                break;
            case 3:
                C[k+1].push_back(ips[i].bitSum[k+1]);
                break;
            case 4:
                D[k+1].push_back(ips[i].bitSum[k+1]);
                break;
            case 5:
                E[k+1].push_back(ips[i].bitSum[k+1]);
                break;
            default:
                break;
            }
        }


    }

    rep(i, 1, 32) {
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        sort(C[i].begin(), C[i].end());
        sort(D[i].begin(), D[i].end());
        sort(E[i].begin(), E[i].end());
    }

    int t2, t1;
    rep(i, 1, m) {
        k = read(), l = read(), r = read();
        if (A[k].size() != 0) {
            t2 = upper_bound(A[k].begin(), A[k].end(), r) - A[k].begin();
            t1 = lower_bound(A[k].begin(), A[k].end(), l) - A[k].begin();
            cnt[1] = t2 - t1;
        }
        if (B[k].size() != 0) {
            t2 = upper_bound(B[k].begin(), B[k].end(), r) - B[k].begin();
            t1 = lower_bound(B[k].begin(), B[k].end(), l) - B[k].begin();
            cnt[2] = t2 - t1;
        }
        if (C[k].size() != 0) {
            t2 = upper_bound(C[k].begin(), C[k].end(), r) - C[k].begin();
            t1 = lower_bound(C[k].begin(), C[k].end(), l) - C[k].begin();
            cnt[3] = t2 - t1;
        }
        if (D[k].size() != 0) {
            t2 = upper_bound(D[k].begin(), D[k].end(), r) - D[k].begin();
            t1 = lower_bound(D[k].begin(), D[k].end(), l) - D[k].begin();
            cnt[4] = t2 - t1;
        }
        if (E[k].size() != 0) {
            t2 = upper_bound(E[k].begin(), E[k].end(), r) - E[k].begin();
            t1 = lower_bound(E[k].begin(), E[k].end(), l) - E[k].begin();
            cnt[5] = t2 - t1;
        }
        rep(j, 1, 4) {
            printf("%d ", cnt[j]);
        }
        printf("%d\n", cnt[5]);
        rep(j, 1, 5) {
            cnt[j] = 0;
        }
    }

    return 0;
}