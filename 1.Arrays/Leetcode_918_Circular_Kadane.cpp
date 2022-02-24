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
	int maxSubarraySumCircular(vector<int>& nums) {

		int total = 0, cur_max = 0, cur_min = 0, mx_sum = nums[0], mn_sum = nums[0];

		int n = nums.size();

		for (int i = 0; i < n; i++) {

			total += nums[i];

			cur_max = max(nums[i], cur_max + nums[i]);

			cur_min = min(nums[i], cur_min + nums[i]);

			mx_sum = max(mx_sum, cur_max);

			mn_sum = min(mn_sum, cur_min);
		}

		return (mx_sum > 0) ? max(mx_sum, (total - mn_sum)) : mx_sum;
	}
};