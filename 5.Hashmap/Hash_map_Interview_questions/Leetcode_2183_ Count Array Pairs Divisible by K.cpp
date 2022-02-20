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

        Key Idea:-


        As it is asked in the question -> (nums[i]*nums[j])%k=0;
        							--> We can write is as (nums[i]* nums[j])= m*k (let m be some constant and let nums[i]=x and nums[j]=y)
        							--> (x*y)= m*k

        							--->since (x*y) is divisible by k therefore (x*y) must be containing all the factors of k. Some factors of k
        							----> is being contributed by x and some might by contributed by y or all may be contributed by x or y.

        							--> We will store the previously processed factor in some hashmap.

*/

class Solution {
public:
	long long coutPairs(vector<int>& nums, int k) {

		int n = nums.size();

		unordered_map<ll, ll> divisors;

		ll cnt = 0;

		for (int i = 0; i < n; i++) {

			int x = nums[i];

			int cont_x_res = __gcd(x, k);

			int cont_y_res = k / cont_x_res;

			for (auto ele : divisors) {  // This approach will work as total number of divisors will not be large.

				if (ele.ff % cont_y_res == 0) {
					cnt += (ll)ele.ss;
				}
			}

			divisors[cont_x_res]++;
		}

		return cnt;
	}
};