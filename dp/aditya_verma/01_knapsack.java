import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

class _01Knapsack {

    private static int knapsack(int size, int capacity, ArrayList<Integer> weights, ArrayList<Integer> values, int [][]dp) {
        if(size==0 || capacity==0) {
            return 0;
        }

        if(dp[size][capacity]!=-1) {
            return dp[size][capacity];
        }

        if(weights.get(size-1)<=capacity) {
            int take = values.get(size-1) + knapsack(size-1, capacity-weights.get(size-1), weights, values, dp);
            int notTake = knapsack(size-1, capacity, weights, values, dp);

            return dp[size][capacity] = Math.max(take, notTake);
        }

        return dp[size][capacity] = knapsack(size-1, capacity, weights, values, dp);
    }
    
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the number of items");
        int size = scn.nextInt();
        ArrayList<Integer> weights = new ArrayList<Integer>();
        ArrayList<Integer> values = new ArrayList<Integer>();
        System.out.println("Enter weights of " + size + " items");
        for(int index=0; index<size; index++) {
            weights.add(scn.nextInt());
        }
        System.out.println("Enter values of " + size + " items");
        for(int index=0; index<size; index++) {
            values.add(scn.nextInt());
        }
        System.out.println("Enter capacity of knapsack");
        int capacity = scn.nextInt();

        int dp[][] = new int [size+1][capacity+1];

        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        int maximumProfit = knapsack(size, capacity, weights, values, dp);
        System.out.println("maximumProfit : " + maximumProfit);

        scn.close();
    }
}