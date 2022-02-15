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

// Storing Prefix in unordered map:- o(n) time and o(n) space

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {

		int n = nums.size();

		unordered_map<int, int> m;

		int total_sm = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] == 0) {
				continue;
			}

			total_sm += nums[i];

			m[total_sm] = i;
		}

		int mn = INT_MAX;

		int sm = 0;

		if (m.find(x) != m.end()) {
			int idx = m[x];

			int total = (n - idx);

			mn = min(mn, total);
		}

		for (int i = 0; i < n; i++) {
			sm += nums[i];

			int req = (x - sm);

			if (req == 0) {

				int total = (i + 1);

				mn = min({mn, total});
				continue;
			}

			if (m.find(req) != m.end()) {
				int idx = m[req];

				if (idx <= i) {
					continue;
				}

				int total = (i + 1) + (n - idx);

				mn = min(mn, total);
			}
		}

		return (mn == INT_MAX) ? -1 : mn;
	}
};