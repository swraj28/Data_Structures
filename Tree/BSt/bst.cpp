#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

//Recursive Implementation:-
node* buildBST(node* root, int data) {
	if (root == NULL) {
		node* n = new node(data);
		root = n;
		return root;
	}

	if (data > root->data) {
		root->right = buildBST(root->right, data);
	} else {
		root->left = buildBST(root->left, data);
	}

	return root;
}

node* insert() {
	node* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {

		root = buildBST(root, data);

		cin >> data;
	}

	return root;
}

//Iterative Implemenataion:-
node* Insert_iter(node*root, int data) {

	node* new_node = new node(data);

	// Pointer to start traversing from root and
	// traverses downward path to search
	// where the new node to be inserted
	node*x = root;

	// Pointer y maintains the trailing
	// pointer of x
	node*y = NULL;

	while (x != NULL) {
		y = x;
		if (data < x->data) {
			x = x->left;
		} else {
			x = x->right;
		}
	}
	// If the root is NULL i.e the tree is empty
	// The new node is the root node
	if (y == NULL) {
		root = new_node;
	} else if (data < y->data) {
		y->left = new_node;
	} else {
		y->right = new_node;
	}
	// Returns the root node
	return root;
}

void preOrder(node*root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node*root) {
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node*root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

bool search(node* root, int item) {

	if (root == NULL) {
		return false;
	}

	if (root->data == item) {
		return true;
	}

	if (item > root->data) {
		return search(root->right, item);
	} else {
		return search(root->left, item);
	}
}

bool isBST(node* root, int minRange = INT_MIN, int maxRange = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	bool leftBST = isBST(root->left, minRange, root->data);
	bool rightBST = isBST(root->right, root->data, maxRange);

	if (leftBST and rightBST and root->data > minRange and root->data < maxRange) {
		return true;
	} else {
		return false;
	}
}

class TreeDetail {
public:
	bool bst;
	int size;
	int maxValue;
	int minValue;
};

TreeDetail largestBstInABinaryTree(node* root) {

	TreeDetail val;

	if (root == NULL) {

		val.bst = true;
		val.size = 0;
		val.minValue = INT_MAX;
		val.maxValue = INT_MIN;
		return val;
	}

	TreeDetail leftStatus = largestBstInABinaryTree(root->left);
	TreeDetail rightStatus = largestBstInABinaryTree(root->right);

	if (!leftStatus.bst or !rightStatus.bst or root->data < leftStatus.maxValue or root->data > rightStatus.minValue) {

		val.bst = false;
		val.size = max(leftStatus.size, rightStatus.size);
		return val;
	}

	val.bst = true;
	val.size = leftStatus.size + rightStatus.size + 1;

	val.minValue = root->left == NULL ? root->data : leftStatus.minValue;

	val.maxValue = root->right == NULL ? root->data : rightStatus.maxValue;

	return val;
}

int uniqueBST(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int leftBST = uniqueBST(i - 1);
		int rightBST = uniqueBST(n - i);

		ans += leftBST * rightBST;
	}

	return ans;
}

node* builtBalancedBST(int arr[], int start, int end) {
	// if(start==end){
	// 	return new node(arr[start]);
	// }

	if (start > end) {
		return NULL;
	}

	int mid = start + (end - start) / 2;

	node* root = new node(arr[mid]);

	root->left = builtBalancedBST(arr, start, mid - 1);
	root->right = builtBalancedBST(arr, mid + 1, end);

	return root;
}

void printNodesKDistance(node* root, int k, int level, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	if (level == k) {
		res.push_back(root->data);
		return;
	}

	printNodesKDistance(root->left, k, level + 1, res);
	printNodesKDistance(root->right, k, level + 1, res);
}


void smallest(node* root, int &k, int &ans) {
	if (root == NULL) {
		return;
	}

	smallest(root->left, k, ans);

	k--;
	if (k == 0) {
		ans = root->data;
	}

	smallest(root->right, k, ans);
}

int kthSmallest(node* root, int k) {
	int ans = 0;

	smallest(root, k, ans);
	return ans;
}


int main() {

	//Recursive Insertion
	// node* root = insert();

	//Iterative Insertion
	node* root = NULL;
	root = Insert_iter(root, 50);
	Insert_iter(root, 30);
	Insert_iter(root, 20);
	Insert_iter(root, 40);
	Insert_iter(root, 70);
	Insert_iter(root, 60);
	Insert_iter(root, 80);

	preOrder(root);
	cout << endl;

	inOrder(root);
	cout << endl;

	postOrder(root);
	cout << endl;

	// cout << search(root, 5) << endl;
	// cout << search(root, 15) << endl;

	// cout << isBST(root) << endl;

	// TreeDetail val = largestBstInABinaryTree(root);

	// cout << val.size << endl;

	// cout << uniqueBST(5) << endl;

	return 0;
}

// 4 2 6 1 3 5 7 -1

// Input for largest bst in a bt
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1