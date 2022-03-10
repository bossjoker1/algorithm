# 双向链表 + hash(字典) 才能实现O(1)
class ListNode:
    def __init__(self, key = 0, val = 0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hashmap = {}
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tailsc
        self.tail.prev = self.head
    
    def remove_node(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def add_node_to_last(self, node):
        self.tail.prev.next = node
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev = node
    
    def move_node_to_last(self, node):
        self.remove_node(node)
        self.add_node_to_last(node)

    def get(self, key: int) -> int:
        if key not in self.hashmap:
            return -1
        node = self.hashmap[key]
        self.move_node_to_last(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            node = self.hashmap[key]
            node.val = value
            self.move_node_to_last(node)
            return
        if len(self.hashmap) == self.capacity:
            del self.hashmap[self.head.next.key]
            self.remove_node(self.head.next)
        node = ListNode(key, value)
        self.hashmap[key] = node
        self.add_node_to_last(node)

# 又写了一遍

class ListNode:
    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.head = ListNode()
        self.tail = ListNode()
        self.hashmap = {}
        self.capacity = capacity
        self.head.next = self.tail
        self.tail.prev = self.head

    def removeNode(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def add_to_theLast(self, node):
        node.next = self.tail
        node.prev = self.tail.prev
        self.tail.prev.next = node
        self.tail.prev = node

    def move_to_theLast(self, node):
        self.removeNode(node)
        self.add_to_theLast(node)

    def get(self, key: int) -> int:
        if key not in self.hashmap:
            return -1
        else:
            node = self.hashmap[key]
            self.move_to_theLast(node)
            return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            node = self.hashmap[key]
            node.val = value
            self.move_to_theLast(node)
            return
        if len(self.hashmap) == self.capacity:
            del self.hashmap[self.head.next.key]
            self.removeNode(self.head.next)
        node = ListNode(key, value)
        self.add_to_theLast(node)
        self.hashmap[key] = node
            