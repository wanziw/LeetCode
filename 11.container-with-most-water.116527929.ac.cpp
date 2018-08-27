class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0, volume; 
        int left = 0, right = height.size() - 1;
        while(left < right) { 
            volume = (right - left) * min(height[left], height[right]);
            answer < volume?answer = volume:answer = answer;
            height[left] < height[right]?left++:right--;
        }
        return answer;
    }
};
