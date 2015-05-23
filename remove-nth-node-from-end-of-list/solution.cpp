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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) return head;
		ListNode *p = head, *q = head;
		while(n) {
			q = q->next;
			n--;
		}
		if (!q) {
			head = p->next;
			delete p;
			return head;
		}
		while(q->next) {
			p = p->next;
			q = q->next;
		}
		q = p->next;
		p->next = p->next->next;
		delete q;
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
	ListNode* l;
    while(cin>>num) {
		if (num == -1) {
			l = createList(nums);
			nums.clear();
			break;
		}
		nums.push_back(num);
    }
	cin>>num;
	printList(l);
    Solution s;
    ListNode* r = s.removeNthFromEnd(l, num);
	printList(r);
}
