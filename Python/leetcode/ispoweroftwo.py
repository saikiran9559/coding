import math
def isPowerOfTwo( n):
    """
    :type n: int
    :rtype: bool
    """
    val = math.log(n,2)
    print(val)
    if int(val) == val:
        return True 
    return False

print(isPowerOfTwo(536870912))
