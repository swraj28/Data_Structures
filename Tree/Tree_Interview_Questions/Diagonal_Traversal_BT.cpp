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
	Node* left, * right;
};

/*
    The key idea here is to do level order traversal. Whenever we find a node in the queue we will keep traversing to all the right nodes untill we hit
    null and keep the left node in the queue,as the left node will form different diagonal.
*/


vector<int> diagonal(Node *root) {

	vector<int> v;

	if (root->left == nullptr and root->right == nullptr) {
		v.push_back(root->data);
		return v;
	}

	queue<Node*> q;
	q.push(root);

	while (true) {
		int sze = q.size();

		if (sze == 0) {
			break;
		}

		while (sze--) {

			Node* f = q.front();
			q.pop();

			while (f != nullptr) {
				v.push_back(f->data);

				if (f->left) {
					q.push(f->left);
				}

				f = f->right;
			}
		}
	}

	return v;
}