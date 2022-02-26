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

struct Node {

	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class Solution {
public:
	void removeLoop(Node* head) {

		if (head == NULL or head->next == NULL)return ;

		Node*slow = head;
		Node*fast = head;
		bool flag = false;

		while (fast->next != NULL and fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				flag = true;
				break;
			}
		}

		if (flag == false) {
			return ;
		}

		slow = head;
		Node* prev = nullptr;
		while (slow != fast) {
			slow = slow->next;
			prev = fast;
			fast = fast->next;
		}

		if (prev == nullptr) {
			while (fast->next != slow) {
				fast = fast->next;
			}
			fast->next = nullptr;
		} else {
			prev->next = nullptr;
		}
	}
};