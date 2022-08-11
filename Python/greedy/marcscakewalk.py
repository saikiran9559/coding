from math import pow
arr = [7,4,9,6]
n = len(arr)
def marcsCakewalk(calorie):
    n = len(calorie)
    calorie.sort()
    miles = 0
    for i in range(n):
        miles += int(pow(2,i)) * calorie[n-i-1]
    return miles

print(marcsCakewalk(arr))
