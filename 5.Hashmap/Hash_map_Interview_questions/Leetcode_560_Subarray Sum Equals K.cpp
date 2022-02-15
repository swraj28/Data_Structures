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
	int subarraySum(vector<int>& nums, int k) {

		int n = nums.size();

		unordered_map<int, int> m;

		int cnt = 0;

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];

			if (sm == k) {
				cnt++;
				cnt += m[sm - k];
				m[sm]++;
			} else {
				int val = (sm - k);
				if (m.find(val) != m.end()) {
					cnt += m[val];
					m[sm]++;
				} else {
					m[sm]++;
				}
			}
		}

		return cnt;
	}
};