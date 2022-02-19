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

// Brute Force :- O(n^3) Solution:-

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(all(nums));

		for (int i = 0; i < n; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			for (int j = i + 1; j < n; j++) {

				if (j != i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}

				for (int k = j + 1; k < n; k++) {

					if (k != j + 1 && nums[k] == nums[k - 1]) {
						continue;
					}

					int x = nums[i] + nums[j] + nums[k];

					if (x == 0) {
						ans.pb({nums[i], nums[j], nums[k]});
					}
				}
			}
		}

		return ans;
	}
};

// Optimized Solution:- O(n^2) Solution :- (But in worst case this solution may behave as O(n^3) Solution).--> Hashmap

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(all(nums));

		unordered_set<int> s;

		for (int i = 0; i < n; i++) {

			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			s.clear();

			for (int j = i + 1; j < n; j++) {

				if (s.find(- nums[i] - nums[j]) != s.end()) {
					ans.pb({nums[i], nums[j], (- nums[i] - nums[j])});

					while ((j + 1) < n && nums[j] == nums[j + 1]) {
						j++;
					}
				}

				s.insert(nums[j]);
			}
		}

		return ans;
	}
};

// Using Two Pointers:-

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(all(nums));

		for (int i = 0; i < n; i++) {

			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			int j = i + 1, k = n - 1;

			while (j < k) {

				if (nums[i] + nums[j] + nums[k] == 0) {
					ans.pb({nums[i], nums[j], nums[k]});

					j++;

					while (j < k && nums[j] == nums[j - 1]) {
						j++;
					}
				} else if (nums[i] + nums[j] + nums[k] < 0) {
					j++;
				} else {
					k--;
				}
			}
		}

		return ans;
	}
};