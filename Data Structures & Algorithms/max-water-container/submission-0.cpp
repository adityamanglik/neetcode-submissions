class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int i = 0, j = heights.size() - 1;
        while(i != j){
            int area = min(heights[i], heights[j])*(j - i);
            if (area > maxArea)
                maxArea = area;
            if (heights[i] < heights[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};
