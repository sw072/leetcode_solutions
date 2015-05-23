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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		head->next = NULL;
		ListNode *p = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (!l1) l1 = l2;
		while (l1) {
			p->next = l1;
			p = l1;
			l1 = l1->next;
		}
		p = head->next;
		delete head;
		return p;
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
	printList(l[0]);
	printList(l[1]);
    Solution s;
    ListNode* r = s.mergeTwoLists(l[0], l[1]);
	printList(r);
}
