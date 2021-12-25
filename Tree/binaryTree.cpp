#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) { //constructor
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

node* buildTree(node* root) {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new node(data);
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

	return root;
}

//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

node* buildTree_1(node* root) {
	int data;
	string val;
	cin >> data >> val;

	if (root == NULL) {
		root = new node(data);
	}
	if (val == "true") {
		root->left = buildTree_1(root->left);
	}

	cin >> val;

	if (val == "true") {
		root->right = buildTree_1(root->right);
	}
	return root;
}

//Build a Tree From a Given Parent Array Representation:-

node* create_tree(int Parent[], int n) {

	//Create an Empty map
	unordered_map<int, node*> map;

	for (int i = 0; i < n; i++) {
		map[i] = new node(i);
	}

	node*root = NULL;

	for (int i = 0; i < n; i++) {

		if (Parent[i] == -1) {
			root = map[i];
		} else {

			node*temp = map[Parent[i]];

			if (temp->left) {
				temp->right = map[i];
			} else {
				temp->left = map[i];
			}
		}
	}
	return root;
}

bool is_full_binary_tree(node* root) {
	if (root == NULL) {
		return true;
	}
	if (root->left == NULL and root->right == NULL) {
		return true;
	}

	if (root->left == NULL or root->right == NULL) {
		return false;
	}

	if (root->left and root->right) {
		return is_full_binary_tree(root->left) and is_full_binary_tree(root->right);
	}
}

//Iterative:-
bool is_full_binary_tree_itr(node* root) {
	if (root == NULL) {
		return true;
	}
	queue<node*>q;
	q.push(root);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		if (temp->left == NULL and temp->right == NULL) {
			continue;
		}

		if (temp->left == NULL or temp->right == NULL) {
			return false;
		}
		q.push(temp->left);
		q.push(temp->right);
	}
	return true;
}

//Perfect Binary Tree
int depth(node* root) {
	int d = 0;
	while (root != NULL) {
		d++;
		root = root->left;
	}

	return d;
}

bool is_perfect_binary_tree(node* root, int d, int level = 0) {
	if (root == NULL) {
		return true;
	}

	if (root->left == NULL and root->right == NULL) {
		return (d == level + 1);
	}

	if (root->left == NULL or root->right == NULL) {
		return false;
	}

	return is_perfect_binary_tree(root->left, d, level + 1) and is_perfect_binary_tree(root->right, d, level + 1);
}

bool is_perfect(node* root) {
	int d = depth(root);

	return is_perfect_binary_tree(root, d);
}
//Iterative appoach (Perfect Binary Tree)
// Trick:-All the leaf nodes are at the same level.

bool is_perfect_binary_tree_itr(node* root) {
	if (root == NULL) {
		return true;
	}
	// Push the root node
	queue<node*> q;
	q.push(root);
	// Flag to check if leaf nodes have been found
	int flag = 0;

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		// If current node has both left and right child
		if (temp->left and temp->right) {
			// If a leaf node has already been found
			// then return false
			if (flag == 1) {
				return false;
			} else {
				q.push(temp->left);
				q.push(temp->right);
			}
			// If a leaf node is found mark flag as one
		} else if (!temp->left and !temp->right) {
			flag = 1;
			// If the current node has only one child
			// then return false
		} else if (!temp->left or !temp->right) {
			return false;
		}
	}
	// If the given tree is perfect return true
	return true;
}

int countNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + 1 + rightCount;
	return totalCount;
}

//Complete Binary Tree
//1. Recursive Implementation:-
bool is_complete_binary_tree(node* root, int index, int total_nodes) {
	// An empty tree is complete
	if (root == NULL) {
		return true;
	}

	// If index assigned to current node is more than
	// number of nodes in tree, then tree is not complete
	if (index >= total_nodes) {
		return false;
	}

	// Recur for left and right subtrees
	return is_complete_binary_tree(root->left, 2 * index + 1, total_nodes)
	       and  is_complete_binary_tree(root->right, 2 * index + 2, total_nodes);
}

//2.Iterative Implementation:-

bool is_complete_binary_tree_itr(node* root) {

	// Base Case: An empty tree
	// is complete Binary Tree
	if (root == NULL) {
		return true;
	}

	// Create an empty queue
	queue<node*> q;
	q.push(root);

	// Create a flag variable which will be set true
	// when a non full node is seen
	bool flag = false;

	while (!q.empty()) {

		node*temp = q.front();
		q.pop();

		if (temp->left) {
			if (flag == true) {
				return false;
			}
			q.push(temp->left);
		} else {
			flag = true;
		}

		if (temp->right) {
			if (flag == true) {
				return false;
			}
			q.push(temp->right);
		} else {
			flag = true;
		}
	}

	return true;
}

void preOrder(node*root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void pre_order_itr(node*root) {
	if (root == NULL)return;

	stack<node*>s;
	s.push(root);

	while (!s.empty()) {
		node*curr = s.top();
		s.pop();
		cout << curr->data << " ";

		if (curr->right)s.push(curr->right);

		if (curr->left)s.push(curr->left);
	}
}

void preOrder_morris_traversal(node*root) {//t.c-o(node) and s.c-o(1)
	if (root == NULL)return;

	node*curr = root;

	while (curr != NULL) {

		if (curr->left == NULL) {
			cout << curr->data << " ";
			curr = curr->right;
		} else {
			node*pred = curr->left;

			while (pred->right != NULL and pred->right != curr) {
				pred = pred->right;
			}
			if (pred->right == NULL) {
				pred->right = curr;
				cout << curr->data << " ";
				curr = curr->left;
			} else {
				pred->right = NULL;
				curr = curr->right;
			}
		}
	}
}

void inOrder(node*root) {
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void in_order_itr(node*root) {

	stack<node*>s;
	node*curr = root;

	while (!s.empty() or curr != NULL) {

		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		cout << curr->data << " ";
		s.pop();

		curr = curr->right;
	}
}

void inOrder_morris_traversal(node*root) {//t.c-o(nodes) and s.c-o(1)
	if (root == NULL)return;

	node*curr = root;

	while (curr != NULL) {

		if (curr->left == NULL) {
			cout << curr->data << " ";
			curr = curr->right;
		} else {
			//find the inorder predecessor of curr
			node*pred = curr->left;
			//To find predecessor keep going right till right node is not null or right node is not current.
			while (pred->right != NULL and pred->right != curr) {
				pred = pred->right;
			}
			//if right node is null then go left after establishing link from predecessor to current.
			if (pred->right == NULL) {
				pred->right = curr;
				curr = curr->left;
			} else { //left is already visit. Go right after visiting current.
				pred->right == NULL;
				cout << curr->data << " ";
				curr = curr->right;
			}
		}
	}
}

// L R N
void postOrder(node* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void post_order_itr(node*root) { //using 2 stacks
	if (root == NULL)return;

	stack<node*>s1, s2;
	s1.push(root);
	node*curr;

	while (!s1.empty()) {
		curr = s1.top();
		s1.pop();
		s2.push(curr);

		if (curr->left)s1.push(curr->left);
		if (curr->right)s1.push(curr->right);
	}

	while (!s2.empty()) {
		curr = s2.top();
		cout << curr->data << " ";
		s2.pop();
	}
}

void post_order_itr_1(node*root) { //using 1 stack

	stack<node*> s;
	node*curr = root;

	while (!s.empty() or curr != NULL) {

		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}

		node*temp = s.top()->right;
		if (temp == NULL) {
			temp = s.top();
			cout << temp->data << " ";
			s.pop();

			while (!s.empty() and temp == s.top()->right) {//skew tree
				temp = s.top();
				cout << temp->data << " ";
				s.pop();
			}
		} else {
			curr = temp;
		}
	}
}

int sumOfNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + root->data + rightSum;
	return totalSum;
}

int height(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight, rightHeight) + 1;
	return totalHeight;
}

bool search(node* root, int item) {
	if (root == NULL) {
		return false;
	}

	if (root->data == item) {
		return true;
	}

	bool leftSearch = search(root->left, item);
	bool rightSearch = search(root->right, item);

	return leftSearch or rightSearch;
}

void printKthLevel(node*root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 1) {
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
	return;

}

void levelOrder(node* root) {   //o(n)  //itreative approach
	// if (root == NULL) {
	// 	return;
	// }

	queue<node*> q;

	q.push(root);

	while (!q.empty()) {

		node* temp = q.front();
		q.pop();

		cout << temp->data << " ";

		if (temp->left) {   //if there is are node present on the left.
			q.push(temp->left);
		}

		if (temp->right) {  //if there are node present on the right
			q.push(temp->right);
		}
	}

}
//print each level in level order seperately(i.e,sperated by a new line)(methode1)

void levelOrder1(node*root) {

	// if (root == NULL) {
	// 	return;
	// }

	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node*temp = q.front();

		if (temp == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {

			cout << temp->data << " ";
			q.pop();

			if (temp->left) {   //if there are node present on the left.
				q.push(temp->left);
			}

			if (temp->right) {  //if there are node present on the right
				q.push(temp->right);
			}

		}
	}
}

//methode-2
void levelOrder2(node*root) {
	if (root == NULL)return;

	queue<node*>q;
	q.push(root);

	while (!q.empty()) {
		int s = q.size();

		while (s--) {
			node*curr = q.front();
			cout << curr->data << " ";
			q.pop();

			if (curr->left)q.push(curr->left);

			if (curr->right)q.push(curr->right);
		}
		cout << endl;
	}
}

int diameter(node* root) {     //o(n*n)
	if (root == NULL) {
		return 0;
	}

	int leftDiameter = diameter(root->left);  //if the diameter entirely lies in left subtree
	int rightDiameter = diameter(root->right); //if the diameter entirely lies in right subtree

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int meraDia = leftHeight + rightHeight ; //if the diameter passes through the root

	int totalDiameter = max(meraDia, max(leftDiameter, rightDiameter));
	return totalDiameter;
}

class DiaHeight {
public:
	int diameter;
	int height;
};

DiaHeight diameterOptimized(node* root) {    //o(n)  //bottom up approach(post order traversal)

	DiaHeight val; //object

	if (root == NULL) {
		val.diameter = 0;
		val.height = 0;
		return val;
	}

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	val.diameter = max(leftPair.diameter, max(rightPair.diameter, leftPair.height + rightPair.height ));
	val.height = max(leftPair.height, rightPair.height) + 1;

	return val;
}

bool isHeightBalanced(node* root) {  //o(n*n)
	if (root == NULL) {
		return true;
	}

	bool leftBalanced = isHeightBalanced(root->left);
	bool rightBalanced = isHeightBalanced(root->right);

	if (!leftBalanced or !rightBalanced) {
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int diff = abs(leftHeight - rightHeight);

	if (diff > 1) {
		return false;
	} else {
		return true;
	}
}

class BalanceHeight {
public:
	bool balance;
	int height;
};

BalanceHeight isHeightBalancedOptimized(node* root) {   //o(n)

	BalanceHeight val;  //object

	if (root == NULL) {
		val.height = 0;
		val.balance = true;
		return val;
	}

	BalanceHeight leftPair = isHeightBalancedOptimized(root->left);
	BalanceHeight rightPair = isHeightBalancedOptimized(root->right);

	if (!leftPair.balance or !rightPair.balance) {
		val.balance = false;
		return val;
	}

	// val.height = max(leftPair.height, rightPair.height) + 1;

	int diff = abs(leftPair.height - rightPair.height);

	if (diff > 1) {
		val.balance = false;
	} else {
		val.balance = true;
	}

	return val;
}

void printRootToLeaf(node* root, string path) {

	if (root == NULL) {
		return;
	}

	string val = to_string(root->data);

	if (root->left == NULL and root->right == NULL) {
		path = path + val;
		cout << path << endl;
		return;
	}

	printRootToLeaf(root->left, path + val);
	printRootToLeaf(root->right, path + val);
}

node* lca(node* root, int data1, int data2) {

	if (root == NULL) {
		return NULL;
	}

	if (root->data == data1 or root->data == data2) {
		return root;
	}

	node* leftLCA = lca(root->left, data1, data2);
	node* rightLCA = lca(root->right, data1, data2);

	if (leftLCA != NULL and rightLCA != NULL) {
		return root;
	}

	if (leftLCA == NULL and rightLCA == NULL) {
		return NULL;
	}

	return leftLCA != NULL ? leftLCA : rightLCA;
}

int findHeight(node* root, int item, int level) {

	if (root == NULL) {
		return -1;
	}

	if (root->data == item) {
		return level;
	}

	int leftDistance = findHeight(root->left, item, level + 1);

	if (leftDistance == -1) { //if the item is not found in the left then we will search in the right
		int rightDistance = findHeight(root->right, item, level + 1);
		return rightDistance;
	}

	return leftDistance;
}

int findDistance(int data1, int data2, node* root) {

	node* common = lca(root, data1, data2);

	int d1 = findHeight(common, data1, 0);
	int d2 = findHeight(common, data2, 0);

	return d1 + d2;
}

int helper(node* root, int &maxPath) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = helper(root->left, maxPath);
	int rightMax = helper(root->right, maxPath);

	leftMax = max(leftMax, 0);
	rightMax = max(rightMax, 0);

	maxPath = max(maxPath, leftMax + root->data + rightMax);

	return max(leftMax, rightMax) + root->data;

}

int maxPathSum(node* root) {   //leetcode 124

	int maxPath = INT_MIN;
	helper(root, maxPath);
	return maxPath;
}

int firstVisit = 1;

void leftView(node* root, int currentLevel) {
	if (root == NULL) {
		return;
	}

	if (currentLevel == firstVisit) {
		cout << root->data << " ";
		firstVisit++;
	}

	leftView(root->left, currentLevel + 1);
	leftView(root->right, currentLevel + 1);
}

void leftBoundary(node* root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		return;
	}

	cout << root->data << " ";

	if (root->left) {
		leftBoundary(root->left);
	} else {
		leftBoundary(root->right);
	}
}

void printLeaf(node* root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		cout << root->data << " ";
		return;
	}

	printLeaf(root->left);
	printLeaf(root->right);
}

int sumReplacement(node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	int leftSum = sumReplacement(root->left);
	int rightSum = sumReplacement(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return temp + root->data;  //total sum
}

int preOrderIndex = 0;

node* BuiltTreeFromPreorderInorder(int pre[], int in[], int start, int end) {
	if (start == end) {
		node* leaf = new node(pre[preOrderIndex]);
		return leaf;
	}

	node* root = new node(pre[preOrderIndex]);

	int mid;

	for (int i = start; i <= end; i++) {
		if (in[i] == pre[preOrderIndex]) {
			mid = i;
			break;
		}
	}

	preOrderIndex++;

	root->left = BuiltTreeFromPreorderInorder(pre, in, start, mid - 1);
	root->right =  BuiltTreeFromPreorderInorder(pre, in, mid + 1, end);

	return root;
}

void serialize(node* root) {
	if (root == NULL) {
		cout << "-1 ";
		return;
	}

	cout << root->data << " ";
	serialize(root->left);
	serialize(root->right);
}

void nodesBelowTarget(node* root, int currDist, int K, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	if (currDist == K) {
		res.push_back(root->data);
	}

	nodesBelowTarget(root->left, currDist + 1, K, res);
	nodesBelowTarget(root->right, currDist + 1, K, res);
}

int nodesAboveTarget(node* root, node* target, int K, vector<int> &res) {
	if (root == NULL) {
		return INT_MIN;
	}

	if (root == target) {
		return 0;
	}

	int leftDistance = nodesAboveTarget(root->left, target, K, res);
	int rightDistance = nodesAboveTarget(root->right, target, K, res);

	if (leftDistance + 1 == K or rightDistance + 1 == K) {
		res.push_back(root->data);
	}

	int result = INT_MIN;

	if (leftDistance >= 0) {
		result = leftDistance + 1;
		nodesBelowTarget(root->right, leftDistance + 2, K, res);
	}

	if (rightDistance >= 0) {
		result = rightDistance + 1;
		nodesBelowTarget(root->left, rightDistance + 2, K, res);
	}

	return result;
}

vector<int> distanceK(node* root, node* target, int K) { //Leetcode-863

	vector<int> res;
	nodesBelowTarget(target, 0, K, res);
	nodesAboveTarget(root, target, K, res);

	return res;
}

int main() {

	node* root = NULL;
	root = buildTree(root);

	// preOrder(root);
	// cout << endl;
	// inOrder(root);
	// cout << endl;
	// postOrder(root);
	// cout << endl;

	// cout<<countNodes(root)<<endl;
	// cout<<sumOfNodes(root)<<endl;

	// cout<<search(root,3)<<endl;
	// cout << height(root) << endl;

	// int k = 3;
	// printKthLevel(root, k);

	// levelOrder(root);
	// cout << endl;
	// levelOrder1(root);

	// cout << diameter(root) << endl;
	// DiaHeight val = diameterOptimized(root);
	// cout << val.diameter << endl;
	// cout << val.height << endl;

	// cout<<isHeightBalanced(root)<<endl;

	// printRootToLeaf(root,"");

	node* val = lca(root, 6, 5);
	cout << val->data << endl;

	cout << findHeight(root, 7, 0) << endl;

	cout << findDistance(4, 6, root) << endl;
	cout << findDistance(1, 7, root) << endl;

	// leftView(root,1);
	// cout<<endl;

	// leftBoundary(root);
	// cout<<endl;

	// printLeaf(root);
	// cout<<endl;

	// BalanceHeight val = isHeightBalancedOptimized(root);
	// cout<<val.balance<<endl;

	// cout << sumReplacement(root) << endl;

	// int in[] = {1,2,3,4,5,6,7};
	// int pre[] = {4,2,1,3,6,5,7};

	// serialize(root);
	// cout<<endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1