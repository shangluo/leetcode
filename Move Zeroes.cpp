class Solution {
public
    void moveZeroes(vectorint& nums) {
        int i = 0;
        int j = 0;
        
        while (j  nums.size())
        {
            if (nums[j] != 0)
            {
                if (i != j)
                {
                    nums[i] = nums[j];
                }
                ++i;
            }
            ++j;
        }
        
        while (i  nums.size())
        {
            nums[i++] = 0;
        }
    }
};