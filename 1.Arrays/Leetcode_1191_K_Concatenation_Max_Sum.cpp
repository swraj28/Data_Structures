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

     Key Idea:- We have to look at some observations to look at the results.

     1. If (k==1)--> Then it is simply Kaden's Algorithm.


     2. If (k>1 && sum<0)-->  Let us understand it by an example:- [a,b,c,d,e]--> array
        so we write the enitre array :- [a,b,c,d,e,f,a,b,c,d,e,f,a,b,c,d,e,f,.........]--> k times

        One thing that can be proposed here that either the max sum is present in the non circular part of the array or if the maximum sum is present
        in the circular then only it will be present in two concatenation.


        -->The max sum is present in the non-circular part of the array:-

        ---> let (d+e+f+a+b)-->yields max sum when two arrays are concatenated. Let 's' be the sum of the entire array.
        --->     totak_sm= (d+e+f+a+b)+ (k-2)*(s).  As we know 's' is less than zero. Therefore taking extra element will be going to reduce the max sum.

        --> The max sum is present in the curcular part of the array :-

        --->	let (a+b+c)-->yields max sum. Let 's' be the sum of the entire array.
        --->     totak_sm= (a+b+c)+ ((k-2)*(s))+(d+e+f).  As we know 's' is less than zero. T
        		herefore taking extra element will be going to reduce the max sum.


     3. if(k>1 && sum>=0)---->Let us understand it by an example:- [a,b,c,d,e]--> array
        so we write the enitre array :- [a,b,c,d,e,f,a,b,c,d,e,f,a,b,c,d,e,f,.........]--> k times

        Let s be the sum of the array :- s=(a+b+c+d+e+f) and (s>0).

        One thing that can be propose that the maximum sum won't lie in the non- circular part. It will always lie in the circular part only.

        we can prove this by contradiction:-

        --> Let (b+c+d) yields maximum sum when two arrays are concatenated. (a,b,c,d,e,f,a,b,c,d,e,f)

        ---> It can be written as (b+c+d)+(e+f+a+b+c+d)+ (e+f).
        ----> From Here wer know that (b+c+d) yields max sum and also (e+f+a+b+c+d)=s and s>=0. Therefore it going to contribute to the max sum.
*/

class Solution {
public:

	long long N = 1000000007;

	int kadanesForOne(vector<int>& arr, int n) {

		int finalans = arr[0];
		int curr = arr[0];

		for (int i = 1 ; i < n; i++) {
			curr = max(arr[i], arr[i] + curr);
			finalans = max(finalans, curr);
		}

		return finalans;
	}


	int kadanesForTwo(vector<int>& arr, int n) {

		int finalans = arr[0];
		int curr = arr[0];

		for (int i = 1 ; i < 2 * n; i++) {
			curr = max(arr[i % n], arr[i % n] + curr);
			finalans = max(finalans, curr);
		}

		return finalans;
	}

	int kConcatenationMaxSum(vector<int>& arr, int k) {

		int n = arr.size();

		int  ans = 0;

		long long sum = 0;

		for (int i = 0; i < n; i++) {
			sum += arr[i];
		}

		if (k == 1) {
			ans = (kadanesForOne(arr, n)) % N;
		} else if (sum > 0) {
			ans = (kadanesForTwo(arr, n) + ((k - 2) * (sum))) % N;
		} else {
			ans = (kadanesForTwo(arr, n)) % N;
		}

		if (ans < 0)return 0;

		return ans % N;
	}
};