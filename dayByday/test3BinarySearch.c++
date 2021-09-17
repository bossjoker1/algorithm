#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//判断在当前target值下分的组数与m大小的比较
bool check(vector<int> ans, long long  target, int m){
    long long weight = 0;
    int cnt = 1;
    int temp = 0;
    int minW = 0x7ffffff, maxW = 0;
    for(int i = 0; i < ans.size(); i++){
        if(minW > ans[i] || maxW < ans[i]) {
            //最大最小值每一个变了，都要更新，这里写在一起了
            minW = min(minW, ans[i]);
            maxW = max(maxW, ans[i]);
            if (weight + (maxW - minW) > target) {
                //开始下一组，并将maxW, minW初始化为新一组的起始值
                minW = ans[i];
                maxW = ans[i];
                cnt++;
                //只在分组时加之前的权值，避免重复累加
                weight += temp;
            }
            //记录上一个权值
            temp = maxW - minW;
        }
    }

    return cnt <= m;
}

int main() {
    //输入数据个数和分组数
    int n, m;
    cin>>n>>m;
    vector<int> ans(n, 0);
    for(int i = 0; i<n;i++){
        cin>>ans[i];
    }

    //upper bound is (max - min), lower bound is 0
    long long r, l = 0;
    r = *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end());
    //cout<<r<<endl;
    while(l < r){
        // 二分查找
        long long mid = (l + r) >> 1;
        if(check(ans, mid, m)){
            //<= m 说明target设大了
            r = mid;
        }else{
            // > m 说明target设小了
            l = mid + 1;
        }
    }
    cout<<l;
}
