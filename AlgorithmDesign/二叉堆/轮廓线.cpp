// 依靠set内置排序
// 但是只有70分..ww
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

multiset<pair<int, tuple<int, int, int>>, less<pair<int, tuple<int, int, int>>>> eventSet;

// set维护高度序列
set<pair<int,int>, greater<pair<int, int>>>heights;
set<pair<int,int>, greater<pair<int, int>>>::iterator it;

int main() {
    int x, h, y;
    int p = 1; // 树的唯一id
    while (scanf("%d%d%d", &x, &h, &y) != EOF)
    {
        eventSet.insert(make_pair(x, make_tuple(p, h, 1)));
        eventSet.insert(make_pair(y, make_tuple(p, h, 0)));
        p++;
    }
    int th = 0;
    for (auto& event : eventSet) {
        if (get<2>(event.second) == 1) {
            heights.insert(make_pair(get<1>(event.second), get<0>(event.second)));
        }
        else {
            heights.erase(make_pair(get<1>(event.second), get<0>(event.second)));
        }
        if (!heights.empty()) {
            it = heights.begin(); //得到头顶
            if ((*it).first != th) {
                printf("%d %d ", event.first, (*it).first);
                th = (*it).first;
            }
        }
        else {
            th = 0;
            printf("%d %d ", event.first, th);
        }
    }

    return 0;
}