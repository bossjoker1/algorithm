# 实现bitset?
# flipped懒标记，否则每次反转很浪费时间

class Bitset:
    flipped = False
    msize, cnt = 0, 0
    bitset = []

    def __init__(self, size: int):
        self.bitset, self.msize = [0] * size, size


    def fix(self, idx: int) -> None:
        if not self.flipped:
            if self.bitset[idx] == 0:
                self.cnt += 1
                self.bitset[idx] = 1
        else:
            if self.bitset[idx] == 1:
                self.cnt += 1
                self.bitset[idx] = 0
            
    def unfix(self, idx: int) -> None:
        if not self.flipped:
            if self.bitset[idx] == 1:
                self.cnt -= 1
                self.bitset[idx] = 0
        else:
            if self.bitset[idx] == 0:
                self.cnt -= 1
                self.bitset[idx] = 1


    def flip(self) -> None:
        self.flipped = not self.flipped
        self.cnt = self.msize - self.cnt

    def all(self) -> bool:
        return self.cnt == self.msize

    def one(self) -> bool:
        return self.cnt > 0

    def count(self) -> int:
        return self.cnt


    def toString(self) -> str:
        res = ""
        if self.flipped:
            for i in range(self.msize):
                res += "1" if self.bitset[i] == 0 else "0"
        else:
            for i in range(self.msize):
                res += "1" if self.bitset[i] == 1 else "0"
        return res
            


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()

# c++实现，维护字符串数组同时维护反转后的字符串
# class Bitset {
# public:
#     string tar, rev;
#     int cnt = 0;
    
#     Bitset(int size) {
#         tar = string(size, '0');
#         rev = string(size, '1');
#     }
    
#     void fix(int idx) {
#         if(tar[idx] == '0')
#             tar[idx] = '1', cnt++;
#         rev[idx] = '0';
#     }
    
#     void unfix(int idx) {
#         if(tar[idx] == '1')
#             tar[idx] = '0', cnt--;
#         rev[idx] = '1';
#     }
    
#     void flip() {
#         swap(tar, rev);
#         cnt = tar.size() - cnt;
#     }
    
#     bool all() {
#         return cnt == tar.size();
#     }
    
#     bool one() {
#         return cnt > 0;
#     }
    
#     int count() {
#         return cnt;
#     }
    
#     string toString() {
#         return tar;
#     }
# };

# /**
#  * Your Bitset object will be instantiated and called as such:
#  * Bitset* obj = new Bitset(size);
#  * obj->fix(idx);
#  * obj->unfix(idx);
#  * obj->flip();
#  * bool param_4 = obj->all();
#  * bool param_5 = obj->one();
#  * int param_6 = obj->count();
#  * string param_7 = obj->toString();
#  */

