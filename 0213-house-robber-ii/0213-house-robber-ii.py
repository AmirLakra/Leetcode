class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0],nums[1])
        def house_linear(money: List[int]) -> int:
            a,b = 0,0
            for i in money:
                a,b = b,max(b,a+i)
            return b
        return max(house_linear(nums[1:]) , house_linear(nums[:-1]))