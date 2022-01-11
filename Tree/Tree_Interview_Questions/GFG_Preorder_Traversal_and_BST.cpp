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

// link:- https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1/#

class Solution {
public:

	int ans = 0;

	int si = 0;

	void dfs(int arr[], int N, int l, int r) {

		if (si >= N) {
			ans = 1;
			return;
		}

		if ((arr[si] > l) and (arr[si] < r)) {

		} else {
			return;
		}

		int val = (arr[si]);
		si++;

		dfs(arr, N, l, val);
		dfs(arr, N, val, r);
	}

	int canRepresentBST(int arr[], int N) {

		if (N == 1) {
			return true;
		}

		dfs(arr, N, INT_MIN, INT_MAX);

		return ans;
	}
};