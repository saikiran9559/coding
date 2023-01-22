import random
a = []
while(len(a)<55):
    b = random.randint(1,55)
    if b not in a:
        a.append(b)
print(a)
