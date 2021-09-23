class Solution {
public:
    vector<string> ans;
    void dfs(int left, int right, string cur) {
        if (left == 0 && right == 0) {
            ans.push_back(cur);
            return;
        }
        if (left > 0) {
            dfs(left-1, right, cur+"(");  // 左括号只要有就能放
        }
        if (right > left) {
            dfs(left, right-1, cur + ")"); // 剩余的左括号数量小于右括号就只能放右括号了
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        dfs(n, n, cur);
        return ans;
    }
};
