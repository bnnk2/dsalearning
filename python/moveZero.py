def moveZeroes(nums):
        if len(nums) <= 1:
            return nums
        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1

nums = [0,1,0,3,12]
moveZeroes(nums)
print(nums)

nums = [0,0,3,12]
moveZeroes(nums)
print(nums)



