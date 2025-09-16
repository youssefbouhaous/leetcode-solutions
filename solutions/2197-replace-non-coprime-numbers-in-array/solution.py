class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ans = [nums[0]]
        n = len(nums)
        for i in range(1,n):
            if math.gcd(ans[-1],nums[i])!=1:
                ans[-1] = math.lcm(ans[-1],nums[i])
                while len(ans) > 1:
                    if math.gcd(ans[-1],ans[-2])!=1:
                        ans[-2] = math.lcm(ans[-1],ans[-2])
                        ans.pop()
                    else:
                        break
            else:
                ans.append(nums[i])
        return ans