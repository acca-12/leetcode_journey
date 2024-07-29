class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;

        while (start < height.size() && height[start] == 0) {
            start++;
        }

        while (end >= 0 && height[end] == 0) {
            end--;
        }

        int trapped = 0;
        int leftMax = 0;
        int rightMax = 0;

        while (start < end) {
            if (height[start] <= height[end]) {
                if (height[start] >= leftMax) {
                    leftMax = height[start];
                } else {
                    trapped += leftMax - height[start];
                }
                start++;
            } else {
                if (height[end] >= rightMax) {
                    rightMax = height[end];
                } else {
                    trapped += rightMax - height[end];
                }
                end--;
            }
        }

        return trapped;
    }
};
