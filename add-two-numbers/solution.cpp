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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0, sum = 0;
		ListNode *p1 = l1, *p2 = l2;
		ListNode *r = new ListNode(0);
		ListNode *p = r;
		while(p1 && p2) {
			sum = p1->val + p2->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			p->next = new ListNode(sum);
			p1 = p1->next;
			p2 = p2->next;
			p = p->next;
		}
		if (p2) p1 = p2;
		while(p1) {
			sum = p1->val + + carry;
			carry = sum / 10;
			sum = sum % 10;
			p->next = new ListNode(sum);
			p1 = p1->next;
			p = p->next;
		}
		if (carry) {
			p ->next = new ListNode(1);
		}
		return r->next;
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
	ListNode* l[2];
	l[0] = l[1] = NULL;
    while(cin>>num) {
		if (num == -1) {
			l[next] = createList(nums);
			nums.clear();
			next++;
			if (next == 2) break;
			continue;
		}
		nums.push_back(num);
    }
    Solution s;
    ListNode* r = s.addTwoNumbers(l[0], l[1]);
	printList(l[0]);
	printList(l[1]);
	printList(r);
}
