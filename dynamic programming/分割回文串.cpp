// 最长为16，感觉可以暴力回溯，但可能不会过
class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            // 退出条件
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j) == 1) {
                // 做选择，如果f[i][j]是回文串，将其加入数组中
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                // 撤销选择
                ans.pop_back();
            }
        }
    }

    // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(const string& s, int i, int j) {
        if (f[i][j]) {
            return f[i][j];
        }
        if (i >= j) {
            return f[i][j] = 1;
        }
        return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n));

        dfs(s, 0);
        return ret;
    }
};
