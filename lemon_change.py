class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        num_five = 0
        num_ten = 0

        if bills[0] != 5:
            return False
        
        num_five += 1
        for i in range(1, len(bills)):
            if(bills[i] == 5):
                num_five += 1
            if(bills[i] == 10):
                if(num_five > 0):
                    num_five -=1
                    num_ten += 1
                else:
                    return False
            if(bills[i] == 20):
                if(num_ten > 0 and num_five > 0):
                    num_ten -= 1
                    num_five -= 1
                elif(num_five >= 3):
                    num_five -= 3
                else:
                    return False

        return True    
