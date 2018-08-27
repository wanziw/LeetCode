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
    ListNode* swapPairs(ListNode* head) {
	ListNode* p = head;
	ListNode* q;
	struct ListNode *r = new ListNode(0);
	r -> next = p;
	bool ishead = true;

	if(p == NULL)
	    return head;

	while(p -> next != NULL) {
	    if(ishead) {
		head = p -> next;
		ishead = false;
	    }

	    q = p -> next;
	    r -> next = q;
	    p -> next = q -> next;
	    q -> next = p;
	    r = p;

	    p = p -> next;
	    if(p == NULL) break;
	}
	return head;
    }
};

