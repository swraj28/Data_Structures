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

// 1. Brute Force Approach :- By sorting the array (O(nlongn))

// 2. O(n)--> Using Unordered Map.

/*
         We will first assume that the longest consecutive Sequence starts at the particular index i in the first Iteration. Now in the second
         iteration if we manange to find (nums[i]-1) then the longest consecutive sequence will not start with (nums[i]). After the second
         iteration whichever elements in hashmap remains true, it indicates that a consecutive sequence will start from that number.
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		int n = nums.size();

		unordered_map<int, bool> m;

		for (int i = 0; i < n; i++) {
			m[nums[i]] = 1;
		}

		for (int i = 0; i < n; i++) {
			if (m.find(nums[i] - 1) != m.end()) {
				m[i] = 0;
			}
		}

		int mx = 0;

		for (auto ele : m) {
			if (ele.ss == 1) { // Starting Point of a Sequnce

				int st = ele.ff;
				int d = 1;

				while (m.find(st + d) != m.end()) {  // This will run for n times throughout as total number of elements in the array is n only. (Kind of Relaxation Operation in Dijkastra)
					d++;
				}

				mx = max(mx, d);
			}
		}

		return mx;
	}
};