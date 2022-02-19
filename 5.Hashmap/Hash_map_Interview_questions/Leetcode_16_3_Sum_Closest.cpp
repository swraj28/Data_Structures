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
	int threeSumClosest(vector<int>& nums, int target) {

		int n = nums.size();

		sort(all(nums));

		int mn = INT_MAX;

		int val = -1;

		for (int i = 0; i < n; i++) {

			int j = i + 1, k = n - 1;

			while (j < k) {

				if (nums[i] + nums[j] + nums[k] == target) {

					val = target;
					break;

				} else if (nums[i] + nums[j] + nums[k] < target) {
					int x = (nums[i] + nums[j] + nums[k]);

					int d = abs(target - x);

					if (d < mn) {
						mn = d;
						val = x;
					}

					j++;
				} else {

					int x = (nums[i] + nums[j] + nums[k]);

					int d = abs(target - x);

					if (d < mn) {
						mn = d;
						val = x;
					}

					k--;
				}
			}

			if (val == target) {
				break;
			}
		}

		return val;
	}
};