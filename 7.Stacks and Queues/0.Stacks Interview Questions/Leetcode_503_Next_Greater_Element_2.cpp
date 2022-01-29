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
    1.  To deal with circular array we can either copy the array and increase its size by twice and then perform the necessary operations.

    2.	We can make use of the modulo operator on the same array to mimic the properties of a circular array.
*/

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {

		int n = nums.size();

		vector<int> res(n, 0);

		stack<int> s;

		for (int i = (2 * n) - 1; i >= 0; i--) {

			while (!s.empty() && s.top() <= nums[i % n]) {
				s.pop();
			}

			res[i % n] = (s.empty()) ? -1 : s.top();

			s.push(nums[i % n]);
		}

		return res;
	}
};