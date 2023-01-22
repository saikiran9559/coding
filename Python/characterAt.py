class UserMainCode(object):
    @classmethod
    def characterAt(cls, input1, input2):
        n = len(input1)
        for i in range(0,n,2):
            input2-=int(input1[i+1])
            if(input2<=0):
                return input1[i]
        return -1


            
