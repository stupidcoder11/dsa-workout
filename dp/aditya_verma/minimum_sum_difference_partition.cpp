//	Link -  https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10
//          https://www.interviewbit.com/problems/minimum-difference-subsets/

#include <bits/stdc++.h>
using namespace std;

#define dbg(x)	cout << #x << ": " << x << "\n";
#define dbgarr(a, n, idx)	for(int i=0; i<(int)n; i++) cout << #a << "[" << i << "] = " << a[i] << "\n";
typedef long long int ll;

//	Solution function
int minimumSubsetSumDiff(int numbers[], int size, int target) {

    int ans = INT_MAX;
    int dp[size+1][target+1];

    for(int j=0; j<target+1; ++j) {
        dp[0][j]=0;
    }
    for(int i=0; i<size+1; ++i) {
        dp[i][0]=1;
    }

    for(int i=1; i<size+1; ++i) {
        for(int j=1; j<target+1; ++j) {
            dp[i][j] = numbers[i-1]>j?dp[i-1][j]:dp[i-1][j-numbers[i-1]]||dp[i-1][j];
        }
    }

    for(int candidate=0; 2*candidate<=target; ++candidate) {
        if(dp[size][candidate]) {
            ans = min(ans, target-2*candidate);
        }
    }

    return ans;
} 

//	Driver function
int main()
{
    ios_base::sync_with_stdio(false);	cin.tie(0);

    //	Input goes here
    int size;
    cin >> size;

    int numbers[size];
    for(auto &num: numbers) {
        cin >> num;
    }

    int ans = minimumSubsetSumDiff(numbers, size, accumulate(numbers, numbers+size, 0));
    
    dbg(ans);

    return 0;
}