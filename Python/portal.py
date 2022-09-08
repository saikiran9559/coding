
# Python 3 program to print 
# Collatz sequence

output = []

def printCollatz(n):

    global output
     

    # We simply follow steps

    # while we do not reach 1

    while n != 1:

        output.append(n)
 

        # If n is odd 

        if n & 1:

            n = 3 * n + 1
 

        # If even 

        else:

            n = n // 2
 

    # Print 1 at the end 
    output.append(n)

def fun(n):
    global output
    printCollatz(n)
    return output[0]

print(fun(5))
