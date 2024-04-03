/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // 滑动窗口法解决连续子数组的遍历问题
        int i = 0 ; //初始化起始指针
        int sum = 0 ;
        int sublength;
        int result = __INT32_MAX__; // 满足启动result > sublength 的初始条件
        for (int j = 0; j < nums.size(); j++) //先使能fast指针
        {
            sum += nums[j];
            while (sum>=target)
            {
                sublength = j - i + 1 ; // 当前状态的数组长度
                result = result > sublength ? sublength : result;
                sum -= nums[i++];
            }
        }
        return result == __INT32_MAX__ ? 0 : result; 
        
    }
};
// @lc code=end

