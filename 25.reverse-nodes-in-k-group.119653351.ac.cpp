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
    ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* p = head;
	ListNode* q = head;
	ListNode* r = p;
	ListNode* s;
	ListNode* t;
	bool ishead = true;

	if(p == NULL)
	    return head;

	while(1) {
	    for(int i = 0; i < k - 1; i++) {
		if(q -> next != NULL)
		    q = q -> next;
		else {
		    if(!ishead)
			r -> next = s;
		    return head;
		}
	    }

	    if(ishead) {
		head = q;
		ishead = false;
	    }else{
		r -> next = q;
		r = p;
	    }

	    s = p -> next;
	    for(int i = 0; i < k - 1; i++) {
		t = s -> next;
		s -> next = p;
		p = s;
		s = t;
	    }
	    p = s;
	    q = p;

	    if(p == NULL) {
		r -> next = NULL;
		break;
	    }
	}
	return head;
    }
};

