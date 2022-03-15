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
	Node * next;
	Node * prev;

	Node (int x) {
		data = x;
		next = NULL;
		prev = NULL;
	}
};


Node* reverseDLL(Node * head) {

	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	Node* cur = head;
	Node* cur_left = nullptr;

	while (cur != nullptr) {
		Node* temp = cur->next;

		cur->next = cur_left;
		cur->prev = temp;

		cur_left = cur;
		cur = temp;
	}

	return cur_left;
}