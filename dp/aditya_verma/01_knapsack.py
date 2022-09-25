Weight = int(input('Capacity of knapsack :'))
n = int(input('Number of items :'))

print('Enter weight of {} items'.format(n))

weights = []
for index in range(n):
    item_weight = int(input())
    weights.append(item_weight)

print('Enter values of {} items'.format(n))

values = []
for index in range(n):
    item_value = int(input())
    values.append(item_value)


# Assume this function will give me the maximum profit for the array of size n-1
def knapsack(n, weights, values, Weight):
    if n == 0 or Weight == 0:
        return 0
    if weights[n-1] > Weight:
        return knapsack(n-1, weights, values, Weight)
    return max(values[n-1]+knapsack(n-1, weights, values, Weight-weights[n-1]), knapsack(n-1, weights, values, Weight))


print(f'Ans : {knapsack(n, weights, values, Weight)}')
