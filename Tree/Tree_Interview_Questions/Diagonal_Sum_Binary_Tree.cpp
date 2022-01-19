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

vector <int> diagonalSum(Node* root) {

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

		int sm = 0;

		while (sze--) {

			Node* f = q.front();
			q.pop();

			while (f != nullptr) {
				// v.push_back(f->data);

				sm += f->data;

				if (f->left) {
					q.push(f->left);
				}

				f = f->right;
			}
		}

		v.push_back(sm);
	}

	return v;
}