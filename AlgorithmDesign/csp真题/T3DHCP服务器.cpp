// 100
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
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

struct IP {
    // 0 未分配 1 待分配 2 占用 3 过期
    int status;
    string client; // 被占用的主机名
    int dtime; // 过期时间
}IPs[maxn];

int N, Tdef, Tmin, Tmax, n;
string H;

unordered_map<string, vector<int>> mp;

inline void init() {
    rep(i, 1, n) {
        IPs[i].status = 0, IPs[i].dtime = 0;
    }
}

void updateTime(int curT) {
    rep(i, 1, N) {
        if (IPs[i].dtime > 0 && IPs[i].dtime <= curT) {
            if (IPs[i].status == 2) {
                // 占有超时则为过期
                IPs[i].status = 3; 
                IPs[i].dtime = 0; 
            }
            else if (IPs[i].status == 1) {
                // 待分配超时则改为未分配
                IPs[i].status = 0;
                IPs[i].client = "";
                IPs[i].dtime = 0;
            }
        }
    }
}
// -1表示没有，则不处理
int GetRightIP(string SHost, int curT) {
    int ip, ip2, flag = 0, flag2 = 0;
    rep(i, 1, N) {
        if (IPs[i].client == SHost) return i;
        if (!flag && IPs[i].status == 0) {
            ip = i;
            flag = 1;
        }
        if (!flag2 && IPs[i].status == 3) {
            ip2 = i;
            flag2 = 1;
        }
    }
    if (flag) return ip;
    else if (flag2) return ip2;
    else return -1;
}

int main() {
    N = read(), Tdef = read(), Tmax = read(), Tmin = read();
    cin >> H;
    n = read();
    init();

    int curT, ip, etime;
    string SHost, RHost, PType, SType;
    rep(z, 1, n) {
        curT = read(), cin >> SHost, cin >> RHost, cin >> PType, ip = read(), etime = read();

        updateTime(curT);
        if (PType == "DIS") {
            if (RHost != "*") continue;

            // 处理过期时间
            if (etime == 0) etime = curT + Tdef;
            else if (etime - curT < Tmin) etime = curT + Tmin;
            else if (etime - curT > Tmax) etime = curT + Tmax;

            // 选择ip
            int sendIp = GetRightIP(SHost, curT);
            if (sendIp == -1) continue;
            IPs[sendIp].dtime = etime;
            IPs[sendIp].client = SHost;
            // 待分配
            IPs[sendIp].status = 1;
            mp[SHost].push_back(sendIp);
            // 发送Offer报文
            SType = "OFR";
            cout << H << " " << SHost << " " << SType << " " << sendIp << " " << etime << endl;
        }

        if (PType == "REQ") {
            if (RHost == "*") continue;
            if (RHost != H) {
                // 清空占有ip
                for (auto& t : mp[SHost]) {
                    if (IPs[t].status == 1) {
                        IPs[t].status = 0;
                        IPs[t].client = "";
                        IPs[t].dtime = 0;
                    }
                }
                mp[SHost].clear();
                continue;
            }

            if ((ip<1 || ip>N) ||(IPs[ip].client != SHost)) {
                // 发送NAK
                SType = "NAK";
                cout << RHost << " " << SHost << " " << SType << " " << ip << " " << 0 << endl;
                continue;
            }
            // 处理过期时间
            if (etime == 0) etime = curT + Tdef;
            else if (etime - curT < Tmin) etime = curT + Tmin;
            else if (etime - curT > Tmax) etime = curT + Tmax;
            IPs[ip].status = 2;
            // IPs[ip].client = SHost;
            IPs[ip].dtime = etime;
            // 发送ACK报文
            SType = "ACK";
            cout << RHost << " " << SHost << " " << SType << " " << ip << " " << etime << endl;
        }
    }
    return 0;
}