/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        struct ListNode *answer = new ListNode(0);
        struct ListNode *head = answer;
        while(1){
            if(l1 == NULL)
                answer -> val = l2 -> val;
            else if(l2 == NULL)
                answer -> val = l1 -> val;
            else
                answer -> val = l1 -> val + l2 -> val;
            answer -> val = answer -> val + flag;
            
            if(answer->val >= 10){
                answer->val = answer->val - 10;
                flag = 1;
            }else{
                flag = 0;
            }
            
            if(l1 != NULL)
                l1 = l1 -> next;
            if(l2 != NULL)
                l2 = l2 -> next;
            
            if(l1 == NULL && l2 == NULL){
                if(flag == 1)
                    answer -> next = new ListNode(1);
                break;
            }else{
                answer->next = new ListNode(0);
                answer = answer->next;
            }
        }
        return head;
    }
};

