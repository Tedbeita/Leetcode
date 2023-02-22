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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && val == head->val)
        {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;

        }
        ListNode *cur = head;
        while(cur != NULL && cur->next != NULL)
        {
            if(cur->next->val == val)
            {
                ListNode *tem = cur->next;
                cur->next = cur->next->next;
                delete tem;
            }
            else 
            {cur = cur->next;
            }
        }
        return head;
        
    
    }
};
