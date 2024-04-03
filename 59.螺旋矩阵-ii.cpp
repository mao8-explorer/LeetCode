/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int startx = 0;
        int starty = 0;
        int loop = n / 2;
        int offset = 1; // 收缩边界
        int count = 1;
        int mid = n / 2;
        int i,j;
        while(loop--){
            // 左闭右开 
            for( j = starty; j < n - offset ; j ++ ){
                res[startx][j] = count++;
            }
            for( i = startx; i < n -offset ; i ++ ){
                res[i][j] = count++;
            }
            for(; j > starty; j--){
                res[i][j] = count++;
            }
            for(; i > startx; i--){
                res[i][j] = count++;
            }
            offset++;
            startx++;
            starty++;
        }
        if(n%2){
            res[mid][mid] = count;
        }
    return res;

    }
};
// @lc code=end

