/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 1->2->3->4->5
// 1->3->2->4->5
// 1->4->3->2->5



class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 tempNode ,穿针引线，将后来的节点依次加入到pre后面
        ListNode *tempNode = new ListNode(-1);
        tempNode->next = head;
        ListNode *pre = tempNode;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return tempNode->next;
    }
};