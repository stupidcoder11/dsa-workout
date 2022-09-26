//	Link - https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7

#include <bits/stdc++.h>
using namespace std;

#define dbg(x)	cout << #x << ": " << x << "\n";
#define dbgarr(a, n, idx)	for(int i=0; i<(int)n; i++) cout << #a << "[" << i << "] = " << a[i] << "\n";
typedef long long int ll;

//	Solution function
bool isSubsetSumRecursive(int numbers[], int size, int target) {
    if(target==0) {
        return true;
    }
    if(size==0) {
        return false;
    }

    if(numbers[size-1]<=target) {
        bool pick = isSubsetSumRecursive(numbers, size-1, target-numbers[size-1]);
        bool drop = isSubsetSumRecursive(numbers, size-1, target);
        return pick || drop;
    }

    return isSubsetSumRecursive(numbers, size-1, target);
} 

bool isSubsetSumBottomUp(int numbers[], int size, int target, vector<vector<int>>& dp) {
    if(target==0) {
        return true;
    }
    if(size==0) {
        return false;
    }

    if(dp[size-1][target] !=-1) {
        return dp[size-1][target]==1;
    }

    if(numbers[size-1]<=target) {
        bool pick = isSubsetSumBottomUp(numbers, size-1, target-numbers[size-1], dp);
        bool drop = isSubsetSumBottomUp(numbers, size-1, target, dp);
        return dp[size-1][target]=pick || drop;
    }

    return dp[size-1][target]=isSubsetSumBottomUp(numbers, size-1, target, dp);
} 

bool isSubsetSumTopDown(int numbers[], int size, int target) {
    int dp[size+1][target+1];
    memset(dp, -1, sizeof(dp));

    for(int j=0; j<target+1; ++j) {
        dp[0][j]=0;
    }
    for(int i=0; i<size+1; ++i) {
        dp[i][0]=1;
    }

    for(int i=1; i<size+1; ++i) {
        for(int j=1; j<target+1; ++j) {
            if(numbers[i-1]<=j) {
                dp[i][j]=dp[i-1][j-numbers[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[size][target];
} 

//	Driver function
int main()
{
    ios_base::sync_with_stdio(false);	cin.tie(0);

    //	Input goes here
    int size;
    cin >> size;
    int numbers[size];
    for(int& number: numbers) {
        cin >> number;
    }
    int targetSum;
    cin >> targetSum;

    vector<vector<int>> dp(size+1, vector<int>(targetSum+1, -1));

    // string ans = isSubsetSumRecursive(numbers, size, targetSum)?"YES":"NO";
    // string ans = isSubsetSumBottomUp(numbers, size, targetSum, dp)?"YES":"NO";
    string ans = isSubsetSumTopDown(numbers, size, targetSum)?"YES":"NO";
    dbg(ans);
    
    return 0;
}