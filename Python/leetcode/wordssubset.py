def isSubset( first, second):
    m = len(first)
    n = len(second)
    for j in range(n):
        if second.count(second[j])>first.count(second[j]):
            return False
    return True

print(isSubset("google",["e","o"]))       
    
   
# def wordSubsets( words1, words2):
#     """
#     :type words1: List[str]
#     :type words2: List[str]
#     :rtype: List[str]
#     """
#     output = []
#     for i in words1:
#         if isSubset(i,words2):
#             output.append(i)
#     return output

# words1 = ["amazon","apple","facebook","google","leetcode"]
# words2 = ["e","o"]

# print(wordSubsets(words1,words2))

