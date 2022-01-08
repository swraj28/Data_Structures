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

/*

    Important Observations:-

        1. Since We require to validate the Binary Tree ,therefore the number of components will be equal to 1 and also there should not be any cycle
           present.
*/

class Solution {
public:

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		if (n == 1) {
			return true;
		}

		vector<int> cnt(n, 0);

		/*
			keep count of node if come more then 1 time then the valid binary tree is not possible .
			like in any order traversal one node should come only one time.

		*/

		for (int i = 0; i < n; i++) {
			if (leftChild[i] != -1) {
				cnt[leftChild[i]]++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (rightChild[i] != -1) {
				cnt[rightChild[i]]++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (cnt[i] > 1) {
				return false;
			}
		}

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sze[i] = 1;
		}

		int toatal_comp = n;

		for (int i = 0; i < n; i++) {
			if (leftChild[i] != -1) {
				int a = i, b = leftChild[i];

				a = find_parent(a, parent);
				b = find_parent(b, parent);

				if (a == b) { // cycle will form if we join the edges
					return false;
				}

				toatal_comp -= 1;

				if (sze[a] >= sze[b]) {
					parent[b] = a;
					sze[a] += sze[b];
				} else {
					parent[a] = b;
					sze[b] += sze[a];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (rightChild[i] != -1) {
				int a = i, b = rightChild[i];

				a = find_parent(a, parent);
				b = find_parent(b, parent);

				if (a == b) { // cycle will form if we join the edges
					return false;
				}

				toatal_comp -= 1;

				if (sze[a] >= sze[b]) {
					parent[b] = a;
					sze[a] += sze[b];
				} else {
					parent[a] = b;
					sze[b] += sze[a];
				}
			}
		}

		return (toatal_comp == 1);
	}
};