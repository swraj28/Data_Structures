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

// 1. Brute Force:-

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int n = nums.size();

		unordered_map<int, int> m;

		for (int i = 0; i < n; i++) {
			m[nums[i]]++;
		}

		int cnt = 0;

		nums.clear();

		for (auto i : m) {
			if (i.ss == 1) {
				nums.pb(i.ff);
				cnt++;
			} else  {
				nums.pb(i.ff);
				nums.pb(i.ff);
				cnt += 2;
			}
		}

		return cnt;
	}
};

// 2. Optimized

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int n = nums.size();

		int cnt = 1;
		int idx = 1;

		int total = 1;

		for (int i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1]) {
				cnt += 1;
				if (cnt <= 2) {
					nums[idx] = nums[i];
					idx++;
					total++;
				}
			} else {
				cnt = 1;
				nums[idx] = nums[i];
				idx++;
				total++;
			}
		}

		return total;
	}
};