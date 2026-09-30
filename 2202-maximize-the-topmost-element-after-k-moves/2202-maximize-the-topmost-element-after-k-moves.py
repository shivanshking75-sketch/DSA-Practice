class Solution(object):
    def maximumTop(self, nums, k):
        if len(nums)==1:
            if k%2==1:
                return -1
            else:
                return nums[0]
        if k>len(nums):
            return max(nums)
        elif k==0:
            return nums[0]
        elif k==1:
            return nums[1]
        else:
            i=0
            maxval=-1
            while(i<k-1):
                maxval=max(maxval,nums[i])
                i+=1
            return max(maxval,nums[i+1]) if i<len(nums)-1 else maxval