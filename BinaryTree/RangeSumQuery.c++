//初次尝试BIT的题，只能说对涉及类的算法题还不是太了解怎么做，模板倒会写
class NumArray {
public:
    vector<int> tree;

    int lowbit(int x) {
        return x & -x;
    }
    
    int query(int x) {
        int ans = 0;
        for(int i = x; i > 0; i -= lowbit(i))
            ans += tree[i];
        return ans;
    }

    void add(int x, int u) {
        for(int i = x; i <= n; i += lowbit(i))
            tree[i] += u;
    }

    vector<int> nums;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(n+1, 0);
        for(int i = 0; i < n; i++)
            add(i+1, nums[i]);
    }
    
    void update(int index, int val) {
        add(index+1, val-nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }

};