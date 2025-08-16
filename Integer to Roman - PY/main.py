from typing import List

#Works however scored low on memory test. Should revisit. 

class Solution:
    def intToRoman(self, num: int) -> str:
        romanChar = [
            (1000, "M"),
            (500, "D"),
            (100, "C"),
            (50, "L"),
            (10, "X"),
            (5, "V"),
            (1, "I")
        ]
        numeral = ""
        while num != 0:
            count = 0
            i = 0
            ii = 0
            iii = 0
            numStr = str(num)
            numLen =len(numStr)
            smaller = None
            larger = None
            if numStr[0] == "4" or numStr[0] == "9":
                place = 10 ** (len(numStr) - 1)
                ph = int(numStr[0]) * place
                if numStr[0] == "4":
                    target = place * 5
                elif numStr[0] == "9":
                    target = place * 10
                larger = None
                for value, symbol in romanChar:
                    if value == place:
                        smaller = (value, symbol)
                    if value == target:
                        larger = (value, symbol)
                    if smaller and larger:
                        break
                num = num - (larger[0] - smaller[0])
                numeral += smaller[1]
                numeral += larger[1]
                continue
            else:
                for iii in range(len(romanChar)):
                    if num - romanChar[iii][0] < 0:
                        continue
                    else:
                        num = num - romanChar[iii][0]
                        numeral += romanChar[iii][1]
                        break
                
        return numeral

# Extreamly simple way of doing it >:(
# class Solution:
#     def intToRoman(self, num: int) -> str:
#         value_symbols = [
#             (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
#             (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'),
#             (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
#         ]
        
#         res = []

#         for value, symbol in value_symbols:
#             if num == 0:
#                 break
#             count = num // value
#             res.append(symbol * count)
#             num -= count * value

#         return ''.join(res)    


sol = Solution()
print(sol.intToRoman(1994))
