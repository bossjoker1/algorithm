// 100
// 思路就是遇到括号就对括号内的元素开乘
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 10005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int toNumber(string str, int& pos) { //从str的pos位置开始，得到一个数字
    int num = 0;
    while (isdigit(str[pos])) {
        num = num * 10 + str[pos] - '0';
        pos++;
    }
    return num;
}

struct Element {
    string ename;
    int num;
    Element(string _name, int _num) :ename(_name), num(_num) {}
};



void handleFuncString(string s, unordered_map<string, int>& mp) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, '+')) {
        vector<Element> Elements;
        int fac = 1;
        int idx = 0;
        // 处理系数，默认为1
        if (isdigit(item[idx])) {
            fac = toNumber(item, idx);
        }
        while (idx < item.size()) {
            // 获得元素名称
            if (isupper(item[idx])) {
                string name;
                name += item[idx];
                idx++;
                if (islower(item[idx])) {
                    name += item[idx];
                    idx++;
                }
                Elements.emplace_back(name, 1);
            }
            else if (item[idx] == '(') {
                Elements.emplace_back("(", 0);
                idx++;
            }
            else if (item[idx] == ')') {
                Elements.emplace_back(")", 0);
                // 右括号后面没有数字，则人为插入1
                if (idx == item.size() - 1 || !isdigit(item[idx + 1])) {
                    item.insert(idx+1, "1");
                }
                idx++;
            }
            else if (isdigit(item[idx])) {
                int post = toNumber(item, idx);
                // 如果数字跟在')'后面，开始乘
                if (Elements[Elements.size() - 1].ename == ")") {
                    int end = Elements.size() - 1;
                    Elements[end].ename = "*"; // 假性删除括号
                    end--;
                    // 括号见元素原子个数开乘
                    while (Elements[end].ename != "(") {
                        Elements[end].num *= post;
                        end--;
                    }
                    Elements[end].ename = "*";
                }
                else {// 如果数字直接跟在元素后面
                    Elements[Elements.size() - 1].num *= post;
                }
            }
        }
        for (auto& t : Elements) {
            if (t.ename == "*") continue;
            else mp[t.ename] += t.num * fac;
        }
    }
}

int n;

int main() {
    n = read();
    string s;
    rep(i, 1, n) {
        unordered_map<string, int> mp1, mp2;
        getline(cin, s);
        int p = s.find('=');
        handleFuncString(s.substr(0, p), mp1);
        handleFuncString(s.substr(p + 1, s.size()), mp2);

        if (mp1.size() != mp2.size()) {
            printf("N\n");
        }
        else {
            bool flag = true;
            for (auto& t : mp1) {
                if (t.second != mp2[t.first]) {
                    printf("N\n");
                    flag = false;
                    break;
                }
            }
            if (flag) printf("Y\n");
        }
    }
    return 0;
}