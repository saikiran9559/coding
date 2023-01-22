class UserMainCode(object):
    @classmethod
    def arrRotate(cls, input1, input2,input3):
        if(input3 <= input1):
            n = input2[input3:] + input2[:input3]
            return n
        return -1

