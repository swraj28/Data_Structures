/*

Given a singly linklist, modify the list such that all the even numbers appear before all the odd numbers in the modified list.
The order of appearance of numbers within each segregation should be same as that in the original list.

Input Format:-

1->7->2->6->3->5->4->null
Output Format
2->6->4->1->7->3->5->null

Constraints
0 <= N <= 10^6

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class ListNode {
public:
	int val = 0;
	ListNode *next = nullptr;

	ListNode(int val) {
		this->val = val;
	}
};

ListNode *segregateEvenOdd(ListNode *head) {

	if (head == nullptr or head->next == nullptr) {
		return head;
	}

	ListNode*h1 = nullptr;
	ListNode*p1 = nullptr;
	ListNode*h2 = nullptr;
	ListNode*p2 = nullptr;

	// Return h1 at the end

	while (head != nullptr) {
		if ((head->val) % 2 == 0) {
			if (h1 == nullptr) {
				h1 = head;
				p1 = h1;
			} else {
				p1->next = head;
				p1 = p1->next;
			}
		} else {
			if (h2 == nullptr) {
				h2 = head;
				p2 = h2;
			} else {
				p2->next = head;
				p2 = p2->next;
			}
		}
		head = head->next;
	}

	if (h1 == nullptr) {
		return h2;
	}

	if (h2 == nullptr) {
		return h1;
	}

	p1->next = h2;

	p2->next = nullptr; //very very imp.

	return h1;
}

int main()
{
	int n;
	cin >> n;
	ListNode *dummy = new ListNode(-1);
	ListNode *prev = dummy;
	while (n-- > 0)
	{
		int val;
		cin >> val;
		prev->next = new ListNode(val);
		prev = prev->next;
	}

	ListNode *head = segregateEvenOdd(dummy->next);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}