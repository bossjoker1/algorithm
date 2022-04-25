# hard，看要求实际上内部还需实现LRU
# 除了key_to_Node的字典，还需要维护最小频率，即频率对应的双向列表

class ListNode:
    def __init__(self, key = 0, val = 0):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0
        
    def pop(self, node=None):
        if self.size == 0:
            return
        # 淘汰时直接删除头节点，其它情况下需要从链表中拿出来
        if node == None:
            node = self.head.next
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1
        return node
        
    def append(self, node):
        self.tail.prev.next = node
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev = node
        self.size += 1

class LFUCache:

    def __init__(self, capacity: int):
        self.NodeHash = {}
        self.freq = defaultdict(LinkedList)
        self.capacity = capacity
        self.minf = 0
        
        
    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.NodeHash:
            node = self.NodeHash[key]
            f = node.freq
            self.freq[f].pop(node)
            # 更新计数器最小值
            if self.minf == node.freq and self.freq[f].size == 0:
                self.minf += 1
            node.freq += 1
            node.val = value
            self.freq[node.freq].append(node)
        else:
            if len(self.NodeHash) == self.capacity:
                # 淘汰
                node = self.freq[self.minf].pop()
                del self.NodeHash[node.key]
            node = ListNode(key, value)
            self.NodeHash[key] = node
            self.freq[1].append(node)
            self.minf = 1
            
    def get(self, key: int) -> int:
        if key not in self.NodeHash:
            return -1
        
        node = self.NodeHash[key]
        f = node.freq
        self.freq[f].pop(node)
        if self.minf == node.freq and self.freq[f].size == 0:
            self.minf += 1
        node.freq += 1
        self.freq[node.freq].append(node)
        return node.val