// 虽然链表不太熟了，但毕竟是最基础的数据结构
// 还是能AC的hhh

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node * nhead = head;
        stack<Node*> nodes;
        while(!(nodes.empty()&&nhead->next==nullptr&&nhead->child==nullptr)){
            if(nhead -> child != nullptr){
                if(nhead->next!=nullptr)
                    nodes.push(nhead->next);
                nhead -> next = nhead -> child;
                nhead -> next -> prev = nhead;
                nhead -> child = nullptr;
            }else{
                if(nhead->next == nullptr){
                    Node * tp = nodes.top();
                    nodes.pop();
                    nhead->next = tp;
                    tp->prev = nhead;
                }       
            }
            nhead = nhead->next;
        }
        return head;
    }
};