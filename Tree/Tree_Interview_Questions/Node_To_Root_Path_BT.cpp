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

class TreeNode
{
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// The only thing here is that once we find the result then while backtracking we do not need to pop the element from the vector.

// 1. Root to node Path:- (Using a boolean variable)

bool dfs(TreeNode* root, int data, vector <TreeNode*> &v) {

    if (root == nullptr) {
        return false;
    }

    if ((root->val) == data) {
        v.pb(root);
        return true;
    }

    v.pb(root);

    bool res = dfs(root->left, data, v) or dfs(root->right, data, v);

    if (res == 0) {
        v.pop_back();
    }

    return res;
}

// 2. Node to Root Path :-  (Directly returning the vector)

vector<TreeNode*> nodeToRootPath_(TreeNode* root, int data) {

    if (root == nullptr) {
        return {};
    }

    if (root->val == data) {

        vector<TreeNode*> v;
        v.pb(root);

        return v;
    }

    vector<TreeNode*> left = nodeToRootPath_(root->left, data);

    if (left.size()) {
        left.pb(root);
        return left;
    }

    vector<TreeNode*> right = nodeToRootPath_(root->right, data);

    if (right.size()) {
        right.pb(root);
        return right;
    }

    return {};
}

vector<TreeNode*> nodeToRootPath(TreeNode* root, int data) {

    vector<TreeNode*> v;

    auto x = dfs(root, data, v);

    reverse(all(v));

    return v;
}

//************************************************************** input_section=================================================

// TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
// {

//     if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
//     {
//         IDX[0]++;
//         return nullptr;
//     }

//     TreeNode* node = new TreeNode(arr[IDX[0]++]);
//     node->left = createTree(arr, IDX);
//     node->right = createTree(arr, IDX);

//     return node;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     vector<int> IDX(1, 0);
//     TreeNode* root = createTree(arr, IDX);

//     int data;
//     cin >> data;
//     vector<TreeNode*> ans = nodeToRootPath(root, data);
//     if (ans.size() == 0)
//         cout << endl;
//     for (TreeNode* node : ans)
//     {
//         cout << node->val << " ";
//     }
// }

// int main()
// {
//     solve();
//     return 0;
// }