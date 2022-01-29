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

// Brute Force:--> O(n^2);

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

		unordered_map<int, int> m;

		for (auto ele : nums1) {
			m[ele] = -1;
		}

		int n = nums2.size();

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums2[j] > nums2[i]) {
					m[nums2[i]] = nums2[j];
					break;
				}
			}
		}

		vector<int> res;

		for (auto ele : nums1) {
			res.pb(m[ele]);
		}

		return res;
	}
};

// Optimization:- (Use a Stack and Start Iteration from the back)

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

		unordered_map<int, int> m;

		for (auto ele : nums1) {
			m[ele] = -1;
		}

		int n = nums2.size();

		stack<int> s;

		for (int i = n - 1; i >= 0; i--) {

			while (!s.empty() && s.top() <= nums2[i]) {
				s.pop();
			}

			m[nums2[i]] = s.empty() ? -1 : s.top();

			s.push(nums2[i]);
		}

		vector<int> res;

		for (auto ele : nums1) {
			res.pb(m[ele]);
		}

		return res;
	}
};