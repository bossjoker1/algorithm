//
// Created by 张博思 on 2021/3/20.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        int flag = 0;
        cin >> flag;
        switch (flag) {
        case 1: {
            int r, s, v;
            cin >> r >> s >> v;
            for (int j = r-1; j <= s-1; j++) {
                if (vec[j - 1] % v == 0) {
                    vec[j - 1] = vec[j - 1] / v;
                }
            }
            break;
        }
        case 2: {
            int r, s;
            cin >> r >> s;
            cout << accumulate(vec.begin() + r - 1, vec.begin() + s, 0) << endl;
        }

        }
    }
}