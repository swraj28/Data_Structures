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
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

class Solution {
public:

	Node* prev = nullptr;

	bool f = true;

	void dfs(Node* root) {
		if (root == nullptr) {
			return;
		}

		dfs(root->left);

		if ((root->data) > (prev->data) and f == true) {
			f = false;
			prev = root;
		}

		dfs(root->right);
	}

	Node * inOrderSuccessor(Node *root, Node *x) {

		prev = x;

		dfs(root);

		if (f) {
			return nullptr;
		}

		return prev;
	}
};