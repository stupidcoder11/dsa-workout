//	Link - https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3

#include <bits/stdc++.h>
using namespace std;

#define dbg(x)	cout << #x << ": " << x << "\n";
#define dbgarr(a, n, idx)	for(int i=0; i<(int)n; i++) cout << #a << "[" << i << "] = " << a[i] << "\n";
typedef long long int ll;

//	Solution function
int _01KnapsackRecursiveSolution(vector<int> weights, vector<int> values, int size, int capacity) {

    // If the knapsack capacity is zero or there are no items present then profit will be zero.
    if(capacity == 0 || size == 0) {
        return 0;
    }

    // Case 1: If an item's weight is within the knapsack capacity, then see whether considering that item will give maximum profit or not
    if(weights[size-1]<=capacity) {
        int profitOnTaking = values[size-1] + _01KnapsackRecursiveSolution(weights, values, size-1, capacity-weights[size-1]);
        int profitOnLeaving = _01KnapsackRecursiveSolution(weights, values, size-1, capacity);
        return max(profitOnTaking, profitOnLeaving);
    }

    // Case 2: If an item's weight isn't within the knapsack capacity, leave that item and proceed to next item.
    int profitOnLeaving = _01KnapsackRecursiveSolution(weights, values, size-1, capacity);
    return profitOnLeaving;
}

int _01KnapsackTopDownSolution(vector<int> weights, vector<int> values, int size, int capacity, vector<vector<int>>& dp) {

    // If the knapsack capacity is zero or there are no items present then profit will be zero.
    if(capacity == 0 || size == 0) {
        return 0;
    }

    if(dp[size-1][capacity] != -1) {
        return dp[size-1][capacity];
    }

    // Case 1: If an item's weight is within the knapsack capacity, then see whether considering that item will give maximum profit or not
    if(weights[size-1]<=capacity) {
        int profitOnTaking = values[size-1] + _01KnapsackRecursiveSolution(weights, values, size-1, capacity-weights[size-1]);
        int profitOnLeaving = _01KnapsackRecursiveSolution(weights, values, size-1, capacity);
        return dp[size-1][capacity] = max(profitOnTaking, profitOnLeaving);
    }

    // Case 2: If an item's weight isn't within the knapsack capacity, leave that item and proceed to next item.
    int profitOnLeaving = _01KnapsackRecursiveSolution(weights, values, size-1, capacity);
    return dp[size-1][capacity] = profitOnLeaving;
}

int _01KnapsackBottomUpSolution(vector<int> weights, vector<int> values, int size, int capacity) {
    int dp[size+1][capacity+1];

    for(int i=0; i<size+1; ++i) {
        for(int j=0; j<capacity+1; ++j) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(weights[i-1]<=j) {
                dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[size][capacity];
}

int main()
{
    ios_base::sync_with_stdio(false);	cin.tie(0);

    //	Input goes here
    int size;
    cin >> size;

    vector<int> weights(size, 0), values(size, 0);
    for(auto& weight: weights) {
        cin >> weight;
    }
    for(auto& value: values) {
        cin >> value;
    }

    int capacity;
    cin >> capacity;

    vector<vector<int>> dp(size+1, vector<int>(capacity+1, -1));
    
    // int maximumProfit = _01KnapsackRecursiveSolution(weights, values, size, capacity);
    // int maximumProfit = _01KnapsackTopDownSolution(weights, values, size, capacity, dp);
    int maximumProfit = _01KnapsackBottomUpSolution(weights, values, size, capacity);
    dbg(maximumProfit);
    
    return 0;
}