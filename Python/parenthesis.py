
result = list()

def paranthesis(n,left,right,res):
    global result
    if (left==n and left==right):
        result.append(res)
    if left<n:
        paranthesis(n,left+1,right,res+"(")
    if right<left:
        paranthesis(n,left,right+1,res+")")
paranthesis(2,0,0,"")
print(result)
print(len(result))
