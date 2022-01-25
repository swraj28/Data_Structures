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


// Definition for a Node.

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) {
			return NULL;
		}

		queue<Node*> q;
		q.push(root);

		while (true) {

			int s = q.size();

			if (s == 0) {
				break;
			}

			Node* fr = q.front();
			q.pop();
			s -= 1;

			if (fr->left) {
				q.push(fr->left);
			}

			if (fr->right) {
				q.push(fr->right);
			}

			while (s--) {
				Node* temp = q.front();
				q.pop();

				if (temp->left) {
					q.push(temp->left);
				}

				if (temp->right) {
					q.push(temp->right);
				}

				fr->next = temp;

				fr = fr->next;
			}

			fr->next = NULL;
		}

		return root;
	}
};