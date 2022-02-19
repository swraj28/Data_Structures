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
      Approach:
		Even numbers can be divided multiple times until it converts to an odd number.
		Odd numbers can be doubled only once as it converts to an even number.
		Therefore, even numbers can never be increased.
*/

class Solution {
public:
	int minimumDeviation(vector<int>& nums) {

		int n = nums.size();

		multiset<int> s;

		for (int i = 0; i < n; i++) {
			if (nums[i] % 2) {
				s.insert(nums[i] * 2);
			} else {
				s.insert(nums[i]);
			}
		}

		int mn = INT_MAX;

		while (true) {

			auto itr1 = s.begin(), itr2 = s.end();
			itr2--;

			int val1 = (*itr1), val2 = (*itr2);

			if (val2 % 2) {
				mn = min({mn, (val2 - val1)});
				break;
			}

			mn = min({mn, (val2 - val1)});

			val2 /= 2;

			s.erase(itr2);

			s.insert(val2);
		}

		return mn;
	}
};