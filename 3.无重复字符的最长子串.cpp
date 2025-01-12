/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始为-1，相当于字符串左边界的左侧，还没有开始移动
    int rk = -1,ans = 0;
    // 枚举左指针的位置，初始值隐形的表示为-1
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        // 左指针向右移动一格，移除一格字符
            occ.erase(s[i-1]);
        while(rk+1<n && !occ.count(s[rk+1])){
            // 不断的移动右指针
            occ.insert(s[rk+1]);
            ++rk;
        }
        // 第i到rk个字符是一个极长的无重复字符子串
        ans = max(ans,rk-i+1);
    }
    return ans;
    }
};
// @lc code=end

