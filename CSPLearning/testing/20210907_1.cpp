#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m, res, min_l;
    bool flag;
    cin >> n >> m;
    vector<int> odd, even;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp%2 == 0){
            even.push_back(temp);
        }
        else {
            odd.push_back(temp);
        }
    }

    sort(odd.begin(), odd.end()); // 升序
    sort(even.rbegin(), even.rend());

    if (odd.size() > even.size()) {
        flag = true;
        min_l = even.size();
    }
    else {
        flag = false;
        min_l = odd.size();
    }

    if (m % 2 == 0) {
        if (m > 2 *  min_l) {
            if (flag) {
                res = odd[m - min_l-1];
            }
            else {
                res = even[m - min_l - 1];
            }
        }
        else {
            res = even[m / 2 - 1];
        }
    }
    else {
        if (m > 2 * min_l) {
            if (flag) {
                res = odd[m - min_l - 1];
            }
            else {
                res = even[m - min_l - 1];
            }
        }
        else {
            res = odd[m / 2];
        }
    }
    cout << res;
    return 0;

}