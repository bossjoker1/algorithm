// 100分
// 注意类似以下样例
// 4 1
// html
// ..mSh #SJMc
// ....4 #Tm
// ....mSh
// #SJMc msh
// answer: 1 4
#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 105;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

struct element {
    string name;    // 元素名
    int level;
    int par;        // 父亲节点的行号，0表示根节点html
    // vector<int> childs; // 儿子们的行号
    string idname;  // 依附的id选择器名，可有可无
}Elements[maxn];

int n, m;

map<string, int> mp;

int main() {
    n = read(), m = read();
    // 读数据
    string a;
    rep(i, 1, n) {
        int cnt = 0, pos = 0;
        getline(cin, a);
        while (a[pos] == '.') {
            cnt++;
            pos++;
        }
        Elements[i].level = cnt / 2;

        while (a[pos] != ' ' && pos < a.size()) {
            // 大小写不敏感
            Elements[i].name += tolower(a[pos]);
            pos++;
        }
        pos++; // 空格
        // 读id
        while (pos < a.size()) {
            Elements[i].idname += a[pos];
            pos++;
        }
        // 找爸爸
        if (i == 1) Elements[i].par = 0;
        else {
            for (int k = i; k >= 1; k--) {
                if (Elements[k].level < Elements[i].level) {
                    Elements[i].par = k;
                    break;
                }
            }
        }
    }

    rep(i, 1, m) {
        vector<string> find;
        string a;
        getline(cin, a);
        string temp;
        rep(k, 0, a.size() - 1) {
            temp += a[k];
            if (k == a.size() - 1 || a[k+1] == ' ') {
                find.push_back(temp);
                temp = "";
                k++;
            }
        }
        for (int k = 0; k < find.size(); k++) {
            if (find[k][0] != '#') {
                // 转为小写
                transform(find[k].begin(), find[k].end(), find[k].begin(), ::tolower);
            }
        }

        // 开始找
        set<int> ans;
        rep(j, 1, n) {
            int cnt = find.size() - 1;
            // 匹配到根，开始向上匹配，判断是否正确
            bool flag = false;
            if (Elements[j].name != find[cnt] && Elements[j].idname != find[cnt])
                continue;

            if (Elements[j].idname != "" && find[cnt][0] == '#' && find[cnt] != Elements[j].idname)
                continue;

            if (cnt >= 0 && Elements[j].idname == find[cnt]) {
                cnt--;
                ans.insert(j);
            }

            if (cnt >=0 && Elements[j].name == find[cnt]) {
                cnt--;
                ans.insert(j);
            }

            int temp = j;
            while (cnt >= 0) {
                int idx = Elements[temp].par;
                if (idx == 0) break;
                if (Elements[idx].name == find[cnt]) {
                    cnt--;
                }
                if (cnt >= 0 && Elements[idx].idname == find[cnt]) {
                    cnt--;
                }
                temp = idx;
            }

            if (cnt >= 0) {
                ans.erase(j);
            }
        }

        cout << ans.size() << " ";
        for (auto& t : ans) {
            printf("%d ", t);
        }
        printf("\n");
    }
    return 0;
}