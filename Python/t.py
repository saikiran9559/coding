
# Python 3 program to print 
# Collatz sequence 
 

def printCollatz(n):

     

    # We simply follow steps

    # while we do not reach 1

    while n != 1:

        print(n, end = ' ')
 

        # If n is odd 

        if n & 1:

            n = 3 * n + 1
 

        # If even 

        else:

            n = n // 2
 

    # Print 1 at the end 

    print(n)
 
# Driver code 

printCollatz(5)
 
# This code is contributed 
# by vaibhav29498

