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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	int totnode = 0;
	ListNode* p = head;
	ListNode* q;

	//calculate total nodes
	while(1) {
	    if(p != NULL) {
		totnode++;
		p = p->next;
	    }else
		break;
	}

	//remove the spec node
	p = head;
	for(int i = 0; i < totnode; i++) {
	    if(totnode - n == 0)
		return p -> next;
	    else if(i == totnode - n - 1)
		q = p;
	    else if(i == totnode - n) {
		q ->next = p -> next;
		break;
	    }
	    p = p -> next;
	}

	return head;
    }
};

