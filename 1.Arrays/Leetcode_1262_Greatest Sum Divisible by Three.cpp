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

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {

		int n = nums.size();

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		if (sm % 3 == 0) {
			return sm;
		}

		int req = (sm % 3);

		if (req == 1) {

			int mn = INT_MAX;

			for (int i = 0; i < n; i++) {
				if (nums[i] % 3 == 1) {
					mn = min({mn, nums[i]});
				}
			}

			int y = INT_MAX, z = INT_MAX, pos1 = -1;

			for (int i = 0; i < n; i++) {
				if (nums[i] % 3 == 2) {
					if (nums[i] < y) {
						y = nums[i];
						pos1 = i;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (i == pos1) {
					continue;
				}

				if (nums[i] % 3 == 2) {
					if (nums[i] < z) {
						z = nums[i];
					}
				}
			}

			if (y == INT_MAX or z == INT_MAX) {
				return (sm - mn);
			}

			int val = (y + z);
			val = min(val, mn);

			return (sm - val);
		}

		int x = INT_MAX;

		for (int i = 0; i < n; i++) {
			if (nums[i] % 3 == 2) {
				x = min({x, nums[i]});
			}
		}

		int y = INT_MAX, z = INT_MAX, pos1 = -1;

		for (int i = 0; i < n; i++) {
			if (nums[i] % 3 == 1) {
				if (nums[i] < y) {
					y = nums[i];
					pos1 = i;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (i == pos1) {
				continue;
			}

			if (nums[i] % 3 == 1) {
				if (nums[i] < z) {
					z = nums[i];
				}
			}
		}

		if (y == INT_MAX or z == INT_MAX) {
			return (sm - x);
		}

		int val = (y + z);

		val = min({val, x});

		return (sm - val);
	}
};