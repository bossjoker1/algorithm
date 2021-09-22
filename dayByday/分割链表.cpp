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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;      
        vector<ListNode*> res;
        while(temp != nullptr){
            count++;
            temp = temp->next;    
        }

        int avg = count / k;
        int flag = count % k; 

        ListNode* nhead = head;    
        ListNode* pre = nullptr;
        for(int i = 0; i < k; i++){
            res.push_back(nhead);
            int div = flag > 0 ? avg + 1 : avg;
            for(int j = 0; j < div; j++){
                pre = nhead;
                nhead = nhead->next;
            }
            if(pre) pre->next = nullptr;
            flag --;
        }
        
        return res;
    }
};