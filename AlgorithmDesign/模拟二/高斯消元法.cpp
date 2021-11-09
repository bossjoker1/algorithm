#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

inline int max(int x, int y) { return x > y ? x : y; }

typedef long long ll;

int cnt = 0;

vector<map<string, double>> mp(105); vector<double> b;

const int N = 105;
double a[N][N];
double x[N], eps = 1e-8;

// false标识这个方程不符合规范
bool handleString(string s) {
    string temp, str;
    double n = 1.0; int d;
    int i = 0;
    while (i < s.size()) {
        // 对 系数_变量名 的 整体处理
        double f = 1.0;
        if (s[i] == '-' || s[i] == '+' || isdigit(s[i]) || islower(s[i])) {
            if (s[i] == '-' || s[i] == '+') {
                f = s[i] == '-' ? -1.0 : 1.0;
                i++;
            }
            n = 1.0;

            if (isdigit(s[i])) {
                temp.push_back(s[i]);
                int p = ++i;
                while (isdigit(s[p]) || s[p] == '.') {
                    temp.push_back(s[p]);
                    p++;
                }
                i = p;
                n = atof(temp.c_str());
                temp = "";
                if (s[i] != '*') {
                    mp[cnt].clear();
                    return false;
                }
                i++;
            }
            // 开始处理变量名
            if (islower(s[i])) {
                str.push_back(s[i]);
                int p = ++i;
                while (isdigit(s[p])) {
                    temp.push_back(s[p]);
                    p++;
                }
                d = atoi(temp.c_str());
                if (d > 99 || p - i > 2) {
                    return false;
                }
                i = p;
                str.append(temp);
                if (mp[cnt].find(str) != mp[cnt].end()) {
                    return false;
                }
                mp[cnt][str] = n * f;

                temp = "", str = "";
            }
        }
        if (s[i] == '=') {
            // 等式右边
            i++;
            double sign = 1.0;
            for (i; i < s.size(); i++) {
                if (s[i] == '-') sign = -1.0;
                else if (isdigit(s[i]) || s[i] == '.') temp.push_back(s[i]);
                else { mp[cnt].clear(); return false; }
            }
            n = atof(temp.c_str());
            b.push_back(sign * n);
            cnt++;
        }
    }
}

int gauss(int n, int m) {
    int c = 0;
    int r;
    for (r = 0; r < n && c < m; r++, c++) {
        int maxr = r;
        for (int i = r + 1; i < n; i++) {
            if (abs(a[i][c]) > abs(a[maxr][c]))
                maxr = i;
        }
        if (maxr != r) swap(a[r], a[maxr]);
        if (fabs(a[r][c]) < eps) {
            r--;
            continue;
        }
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > eps) {
                double k = a[i][c] / a[r][c];
                for (int j = c; j < m + 1; j++) a[i][j] -= a[r][j] * k;
                a[i][c] = 0;
            }
        }
    }
    for (int i = r; i < m; i++) {
        if (fabs(a[i][c]) > eps) return -1;//无解
    }
    if (r < m) return m - r;//返回自由元个数
    for (int i = m - 1; i >= 0; i--) {
        for (int j = i + 1; j < m; j++) a[i][m] -= a[i][j] * x[j];
        x[i] = a[i][m] / a[i][i];
    }
    return 0;//有唯一解
}

int main() {
    string s;
    while (cin >> s) {
        handleString(s);
    }
    if (cnt == 0) { printf("error1\n"); return 0; }

  
    set<string> num;
    for (int i = 0; i < cnt; i++) {
        for (auto& t : mp[i]) {
            num.insert(t.first);
        }
    }

    int count = num.size();

    map<string, int> order;
    // 建立字母排序索引
    int i = 0;
    for (auto& t : num) {
        order[t] = i;
        i++;
    }

    for (int i = 0; i < cnt; i++) {
        for (auto& t : mp[i]) {
            a[i][order[t.first]] = t.second;
        }
        a[i][count] = b[i];
    }
    int flag = gauss(cnt, count);
    if (flag == -1) {
        printf("error2\n");
        return 0;
    }
    if (flag > 0) {
        printf("error3\n");
        return 0;
    }
    for (int i = 0; i < count; i++) {
        printf("%.4f ", int(x[i]*10000)/10000.0);
    }
    return 0;
}