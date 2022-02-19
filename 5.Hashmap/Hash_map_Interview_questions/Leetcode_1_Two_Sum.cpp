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
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int> m;

		vector<int> v;

		for (int i = 0; i < nums.size(); i++) {

			int x = target - nums[i];

			auto itr = m.find(x);

			if (itr != m.end()) {
				v.push_back(i);
				v.push_back(itr->second);
				break;
			}

			m[nums[i]] = i;
		}

		return v;

	}
};