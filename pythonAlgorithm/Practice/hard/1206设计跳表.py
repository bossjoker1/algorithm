# 最大级深maxLevl=16，power=2分链表，随机数的上限maxRand
maxLevel = 16
power = 2
maxRand = power ** maxLevel - 1
# 随机函数，这里就相当于[1 ... 65535]取随机，然后再对2取对数，可保证插入深度在[1 ... 16]这些数字里呈对数分布
randLevel = lambda: maxLevel - int(math.log(random.randint(1, maxRand), power))

# 三个属性，跳表本体的值，向右的指针，向下的指针
class SkipNode:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.down = None

class Skiplist:
    def __init__(self):
        # 初始化左右正负无穷墙壁
        left = [SkipNode(-float('inf')) for _ in range(maxLevel)]
        right = [SkipNode(float('inf')) for _ in range(maxLevel)]
        # 把墙壁交联在一起
        for i in range(maxLevel - 1):
            left[i].right = right[i]
            left[i].down = left[i + 1]
            right[i].down = right[i + 1]
        # 最后一层单独处理，只有向右指向，没有向下指向
        left[-1].right = right[-1]
        # 跳表初始指针为左壁的首元素
        self.head = left[0]

    def search(self, target: int) -> bool:
        # 从初始指针开始进行跳跃迭代，找不到的node迟早为None，跳出循环自动返回False
        node = self.head
        while node:
            if node.right.value > target:
                node = node.down
            elif node.right.value < target:
                node = node.right
            else:
                return True
        return False

    def add(self, num: int) -> None:
        # 用prev数组存储往下跳跃前的跳表指针，方便之后插入指针时前后交联，免去双向指针处理
        prev = []
        # 原理依旧是指针迭代
        node = self.head
        while node:
            # 碰到右边大于等于自己时就往下跳，帮助prev生成完整的指针数组
            if node.right.value >= num:
                prev.append(node)
                node = node.down
            else:
                node = node.right
        # 待插入的指针数组，长度按概率进行随机
        arr = [SkipNode(num) for _ in range(randLevel())]
        # 用zip把prev后续的元素与新的指针数组交联在一次即可完成跳表插入
        t = SkipNode(None)
        for p, a in zip(prev[maxLevel - len(arr): ], arr):
            a.right = p.right
            p.right = a
            t.down = a
            t = a

    def erase(self, num: int) -> bool:
        # ans为输出标志，erase的结构和search结构类似，依旧是指针迭代
        ans = False
        node = self.head
        while node:
            if node.right.value > num:
                node = node.down
            elif node.right.value < num:
                node = node.right
            else:
                # 存在相等时就修改输出标志
                ans = True
                # 删除node.right的在跳表中的关系
                node.right = node.right.right
                node = node.down
        return ans

# class Skiplist {
#     static const int SKIPLIST_P_VAL = RAND_MAX / 2, MAX_LEVEL = 16; // RAND_MAX是rand()所能达到的最大值。
# public:
#     struct Node{
#         int val;
#         vector<Node *> next;
#         Node(int val, int size = MAX_LEVEL): val(val), next(size){}
#     };

#     Node head;
#     int maxlevel = 1; // 记录当前最高的level

#     Skiplist():head(INT_MIN, MAX_LEVEL) {

#     }
    
#     bool search(int target) {
#         // 在_search后就看第一层的pre的后面一个节点val是否等于target
#         auto prevs = _search(target);
#         return prevs[0]->next[0] && prevs[0]->next[0]->val == target;
#     }

#     vector<Node *> _search(int key){
#         // 此函数是跳表的核心，实现的功能是，寻找key所经历的路径。返回路径上的前置节点
#         Node * cur = &head;
#         vector<Node *> prevs(MAX_LEVEL);
#         for(int i = maxlevel - 1; i >= 0; i--){
#             // 从最顶层开始
#             while(cur->next[i] && cur->next[i]->val < key){
#                 // 一直寻找到刚好大于key的节点的前置节点
#                 cur = cur->next[i];
#             }
#             prevs[i] = cur;
#         }
#         return prevs;
#     }
    
#     void add(int num) {
#         auto prevs = _search(num); // 在当前的跳表中， num在各级跳表中的前置节点
#         int level = random_level(); // level的索引是从1开始的

#         // 更新maxlevel, prevs
#         if(level > maxlevel){
#             // 更新超出maxlevel的prevs，前置节点都为head
#             for(int i = maxlevel; i < level; i++){
#                 prevs[i] = &head;  
#             }
#             maxlevel = level;
#         }

#         // 创建当前节点
#         Node * cur = new Node(num, level);

#         // 插入在prevs节点后, 从pre->nxd到pre->cur->nx
#         for(int i = level - 1; i >= 0; i--){
#             cur->next[i] = prevs[i]->next[i];
#             prevs[i]->next[i] = cur;
#         }

#     }
    
#     bool erase(int num) {
#         auto prevs = _search(num);

#         // 如果num不存在跳表中
#         if(!prevs[0]->next[0] || prevs[0]->next[0]->val != num){
#             return false;
#         }

#         Node * del = prevs[0]->next[0];
#         // 删除prevs后的节点
#         for(int i = 0; i < maxlevel; i++){
#             if(prevs[i]->next[i] == del){
#                 prevs[i]->next[i] = del->next[i];
#             }
#         }
#         delete del;

#         // 更新maxlevel
#         while(maxlevel > 1 && !head.next[maxlevel - 1]){
#             maxlevel--;
#         }
#         return true;

#     }
    

#     static int random_level(){
#         int level = 1;
#         while(rand() < SKIPLIST_P_VAL && level < MAX_LEVEL){
#             level++;
#         }
#         return level; // 此处返回的level的索引是从1开始的
#     }
# };

# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)