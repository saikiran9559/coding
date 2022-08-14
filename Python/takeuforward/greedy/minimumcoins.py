denominations = [1, 2, 5, 10, 20, 50, 100, 500, 1000]


def findMinimumCoins(amount):
    global denominantions
    n = 9
    count=0
    for i in range(n-1,-1,-1):
        if amount==0:
            break
        count += amount//denominations[i]
        amount = amount%denominations[i]
    return count

print(findMinimumCoins(2335))
