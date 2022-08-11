values = {}
keys =[]
count=0
def factorial(n):
    global values, count
    count+=1
    if n in keys:
        print(n,len(keys))
        return values[n]
    if n==0 or n==1:
        keys.append(n)
        values[n]=1
        return 1
    keys.append(n)
    val = n*factorial(n-1)
    values[n]=val
    return val

print(factorial(5),count)
print(keys)
count=0
print(factorial(4),count)
print(keys)
# print(values)