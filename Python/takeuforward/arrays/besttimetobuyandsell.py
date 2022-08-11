'''
method 1
def maximumProfit(prices):
    # Write your code here.
    mini = prices[0]
    maxi=prices[0]
    profit=0
    for i in prices[1:]:
        if i >maxi:
            if i-mini>profit:
                maxi=i
                profit = maxi-mini
            continue
        if i <mini:
            mini = i
            maxi=i
    return profit
'''
#method 2
def maximumProfit(prices):
    profit =0
    mini = prices[0]
    for price in prices:
        mini = min(mini, price)
        profit = max(profit, price-mini)
    return profit

arr=[17,20,11,9,12,6]
arr1 = [98,101,66,72]
print(maximumProfit(arr))
print(maximumProfit(arr1))

