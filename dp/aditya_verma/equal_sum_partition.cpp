//	Link - https://www.youtube.com/watch?v=UmMh7xp07kY

#include <bits/stdc++.h>
using namespace std;

#define dbg(x)	cout << #x << ": " << x << "\n";
#define dbgarr(a, n, idx)	for(int i=0; i<(int)n; i++) cout << #a << "[" << i << "] = " << a[i] << "\n";
typedef long long int ll;

//	Solution function
bool isSubsetSum(int numbers[], int size, int target) {

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

    int list[size];
    memset(list, -1, sizeof(list));

    for(auto& number: list) {
        cin >> number;
    }

    /*
     The trick is that in this type of question if we can check that if there's a subset present which has sum equal to half of the 
     sum of the given set then, it will be sure that the set can be divided into two subsets which have same sum 
     i.e sum(P1) = sum(P2) = S
    */

    int total = 0;
    for(auto number: list) {
        total += number;
    }
    
    string ans = (total&1)?"NO":isSubsetSum(list, size, total/2)?"YES":"NO";
    dbg(ans)

    return 0;
}