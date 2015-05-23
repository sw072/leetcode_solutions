#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

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
    ListNode* removeElements(ListNode* head, int val) {
		if (!head) return NULL;
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p->next;
		while(p->next) {
			if (p->next->val == val) {
				q = p->next;
				p->next = q->next;
				delete q;
			} else {
				p = p->next;
			}
    	}
		p = head;
		head = p->next;
		delete p;
		return head;
	}
};

ListNode* createList(vector<int> nums) {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for (int idx = 0; idx < nums.size(); ++idx) {
		p->next = new ListNode(nums[idx]);
		p = p->next;
	}
	return head->next;
}

void printList(ListNode *l) {
	while(l) {
		cout << l->val;
		l = l->next;
	}
	cout << endl;
}

int main()
{
    vector<int> nums;
    int num = 0;
	ListNode* l = NULL;
    while(cin>>num) {
		if (num == -1) {
			l = createList(nums);
			nums.clear();
			break;
		}
		nums.push_back(num);
    }
	printList(l);
    Solution s;
    ListNode* r = s.removeElements(l, 6);
	printList(r);
	return 0;
}
