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
       The Key Idea here is to store the first and second max of odd and even position elements as per their frequencies.
       This is done because if both the max element in both the odd and even positions are same then we need to look to the
       second max element to support the given two conditions.
*/

class Solution {
public:
	int minimumOperations(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return 0;
		}

		if (n == 2) {
			if (nums[0] != nums[1]) {
				return 0;
			}

			return 1;
		}

		bool f = true;

		for (int i = 1; i < n; i++) {
			if (nums[i] != nums[i - 1]) {
				f = false;
				break;
			}
		}

		if (f) {
			return (n / 2);
		}

		unordered_map<int, int> odd, even;

		int total_even = 0, total_odd = 0;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even[nums[i]]++;
				total_even++;
			} else {
				odd[nums[i]]++;
				total_odd++;
			}
		}

		int mx1 = INT_MIN, mx2 = INT_MIN, even_1 = -1, even_2 = -1;

		for (auto ele : even) {
			if (ele.ss > mx1) {
				mx1 = ele.ss;
				even_1 = ele.ff;
			}
		}

		for (auto ele : even) {
			if (ele.ss > mx2 && ele.ff != even_1) {
				mx2 = ele.ss;
				even_2 = ele.ff;
			}
		}

		mx1 = INT_MIN, mx2 = INT_MIN;
		int odd_1 = -1, odd_2 = -1;

		for (auto ele : odd) {
			if (ele.ss > mx1) {
				mx1 = ele.ss;
				odd_1 = ele.ff;
			}
		}

		for (auto ele : odd) {
			if (ele.ss > mx2 && ele.ff != odd_1) {
				mx2 = ele.ss;
				odd_2 = ele.ff;
			}
		}

		int mn = INT_MAX;

		if (even_1 != -1 && odd_1 != -1 && even_1 != odd_1) {
			int total = (total_even - even[even_1]) + (total_odd - odd[odd_1]);
			mn = min({mn, total});
		}

		if (even_1 != -1 && odd_2 != -1 && even_1 != odd_2) {
			int total = (total_even - even[even_1]) + (total_odd - odd[odd_2]);
			mn = min({mn, total});
		}

		if (even_2 != -1 && odd_1 != -1 && even_2 != odd_1) {
			int total = (total_even - even[even_2]) + (total_odd - odd[odd_1]);
			mn = min({mn, total});
		}

		if (even_2 != -1 && odd_2 != -1 && even_2 != odd_2) {
			int total = (total_even - even[even_2]) + (total_odd - odd[odd_2]);
			mn = min({mn, total});
		}

		return mn;
	}
};