def recursive_subset_sum(numbers: list, size: int, sum: int) -> bool:
    if sum == 0:
        return True

    if size == 0:
        return False

    if numbers[size-1] <= sum:
        return recursive_subset_sum(numbers, size-1, sum) or recursive_subset_sum(numbers, size-1, sum-numbers[size-1])

    return recursive_subset_sum(numbers, size-1, sum)


def top_down_subset_sum(numbers, size, sum, dp):
    if sum == 0:
        return True
    if size == 0:
        return False

    if dp[size-1][sum] != -1:
        return dp[size-1][sum] == True

    if numbers[size-1] <= sum:
        pick = top_down_subset_sum(numbers, size-1, sum-numbers[size-1], dp)
        drop = top_down_subset_sum(numbers, size-1, sum, dp)
        dp[size-1][sum] = pick or drop
        return dp[size-1][sum]

    dp[size-1][sum] = top_down_subset_sum(numbers, size-1, sum, dp)
    return dp[size-1][sum]


def bottom_up_subset_sum(numbers, size, sum):

    dp = [[-1 for col in range(sum+1)] for row in range(size+1)]

    for col in range(sum+1):
        dp[0][col] = False

    for row in range(size+1):
        dp[row][0] = True

    for i in range(1, size+1):
        for j in range(1, sum+1):
            if numbers[size-1] <= sum:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-numbers[i-1]]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[size][sum]


def main():
    size = int(input())

    numbers = []
    for i in range(size):
        number = int(input())
        numbers.append(number)

    sum = int(input())

    dp = [[-1 for col in range(sum+1)] for row in range(size+1)]

    # ans = recursive_subset_sum(numbers, size, sum)
    # ans = top_down_subset_sum(numbers, size, sum, dp)
    ans = bottom_up_subset_sum(numbers, size, sum)
    print(ans)


if __name__ == "__main__":
    main()
