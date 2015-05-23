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
    ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *p = head->next;
		ListNode *q = p->next;
		head->next = NULL;
		while(p) {
			p->next = head;
			head = p;
			p = q;
			if (q) q = q->next;
		}
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
	int next = 0;
	ListNode* l = NULL;
    while(cin>>num) {
		if (num == -1) {
			l = createList(nums);
			nums.clear();
			break;
		}
		nums.push_back(num);
    }
    Solution s;
	ListNode *r = s.reverseList(l);
	printList(l);
	printList(r);
}
