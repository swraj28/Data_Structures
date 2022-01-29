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

// Link:- https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

// Hint :- (Next Greater Element Using Stack)+ (Dynamic Programming(i.e.,Prefix Sum))

class Solution {
public:
	vector <int> calculateSpan(int price[], int n) {

		vector<int> dp(n, 1);

		stack<pair<int, int>> s;

		for (int i = 0; i < n; i++) {

			while (!s.empty() && s.top().first <= price[i]) {
				int x = s.top().second;

				dp[i] += dp[x];
				s.pop();
			}

			s.push({price[i], i});
		}

		return dp;
	}
};