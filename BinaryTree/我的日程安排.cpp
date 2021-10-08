// 并没有线段树。。
// 只是用map节省了遍历的时间

//key存右边界，value存左边界，左闭右闭
class MyCalendar {
    map<int,int> ans;
public:
    MyCalendar() {
        ans.clear();
    }
    
    bool book(int start, int end) {
        --end;
        auto p=ans.lower_bound(start);
        if (p!=ans.end() && p->second<=end)
            return false;
        // 注意end为key
        ans[end]=start;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */