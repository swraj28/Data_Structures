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

// T.c:- O(n) and S.c:- O(n)

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return nums;
		}

		int req = (n / 3) + 1;
		vector<int> ans;

		unordered_map<int, int> m;

		for (int i = 0; i < n; i++) {
			m[nums[i]]++;
		}

		for (auto ele : m) {
			if (ele.ss >= req) {
				ans.pb(ele.ff);
			}
		}

		return ans;
	}
};

/*
    Since the number of elements needs to be more than floor(n/3) to be majority --> Min. req= (n/3)+1

    Therefore from here we can say that at max 2 majority elements can be present as per the question

    Total number of elements coverd if we require 2 majority elements --> ((n/3)+1)+((n/3)+1)=((2*n)/3)+2.

    Therefore we are left with only (n/3)-2 eleemts and that cannot contribute to the majority elements.
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return nums;
		}

		int req = (n / 3) + 1;
		vector<int> ans;

		int maj_ele1 = -1, maj_ele2 = -1, cnt1 = 0, cnt2 = 0;

		for (int i = 0; i < n; i++) {

			if (nums[i] == maj_ele1) {
				cnt1++;
			} else if (nums[i] == maj_ele2) {
				cnt2++;
			} else if (cnt1 == 0) {
				cnt1++;
				maj_ele1 = nums[i];
			} else if (cnt2 == 0) {
				cnt2++;
				maj_ele2 = nums[i];
			} else {
				cnt1--, cnt2--;
			}
		}

		cnt1 = 0, cnt2 = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == maj_ele1) {
				cnt1++;
			} else if (nums[i] == maj_ele2) {
				cnt2++;
			}
		}

		if (cnt1 >= req) {
			ans.pb(maj_ele1);
		}

		if (cnt2 >= req) {
			ans.pb(maj_ele2);
		}

		return ans;
	}
};