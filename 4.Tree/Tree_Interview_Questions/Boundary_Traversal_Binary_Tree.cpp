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

// Link:- https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

struct Node {
	int data;
	Node* left, * right;
};

class Solution {
public:

	vector<int> v;

	void dfs(Node* root) {
		if (root == nullptr) {
			return;
		}

		if (root->left == nullptr and root->right == nullptr) {
			v.push_back(root->data);
		}

		dfs(root->left);
		dfs(root->right);
	}

	vector <int> boundary(Node *root) {

		if (root == nullptr) {
			return v;
		}

		if (root->left == nullptr and root->right == nullptr) {
			v.push_back(root->data);
			return v;
		}

		Node* temp = root->left;

		v.push_back(root->data);

		while (temp != nullptr) {
			if (temp->left != nullptr or temp->right != nullptr) {
				v.push_back(temp->data);
			}
			if (temp->left) {
				temp = temp->left;
			} else {
				temp = temp->right;
			}
		}

		dfs(root);

		vector<int> v1;

		temp = (root->right);

		while (temp != nullptr) {
			if (temp->left != nullptr or temp->right != nullptr) {
				v1.push_back(temp->data);
			}
			if (temp->right) {
				temp = temp->right;
			} else {
				temp = temp->left;
			}
		}

		reverse(v1.begin(), v1.end());

		for (auto node : v1) {
			v.push_back(node);
		}

		return v;
	}
};