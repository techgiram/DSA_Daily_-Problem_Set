class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0; // To store the maximum area
        int lp = 0; // Left pointer
        int rp = height.length - 1; // Right pointer

        while (lp < rp) {
            int width = rp - lp;
            int ht = Math.min(height[lp], height[rp]);
            int currWater = width * ht;

            maxWater = Math.max(maxWater, currWater);

            // Move the pointer with smaller height
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        return maxWater;
    }
}
