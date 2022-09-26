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

    string ans = isSubsetSumRecursive(numbers, size, targetSum)?"YES":"NO";
    dbg(ans);
    
    return 0;
}