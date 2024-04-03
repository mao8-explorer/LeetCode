/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int slowIndex = 0;
        // for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        //     if(nums[fastIndex] != val){
        //         nums[slowIndex++] = nums[fastIndex];
        //     }
        // }
        // return slowIndex;
    // 双向双指针
    int leftIndex =0;
    int rightIndex =nums.size() - 1;
    while(leftIndex <= rightIndex){
        while (leftIndex <= rightIndex && nums[leftIndex] != val)
        {
            leftIndex++;
        }
        while (leftIndex <= rightIndex && nums[rightIndex] == val)
        {
            rightIndex--;
        }
        if(leftIndex < rightIndex){
            nums[leftIndex++] = nums[rightIndex--];
        }
    }
    return leftIndex;
    }
};
// @lc code=end

