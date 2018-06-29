/*
Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_height = 0;
        int min_height = 0;
        
        while(l < r) {
            min_height = min(height[l], height[r]);
            max_height = max(max_height, min_height * (r - l));
            
            //int i = l+1;
            //int j = r-1;

            while(height[l] <= min_height && l < r) l++;
            //l = i;
            
            while(height[r] <= min_height && l < r) r--;
            //r = j;       
        }
        
        return max_height;
    }
};
