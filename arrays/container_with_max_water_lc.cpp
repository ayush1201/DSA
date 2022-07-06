class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        //we create 2 pointers left and right and simply store the maximum area enclosed within left and right pointers and then iterate the pointer which is smaller than other since we need to look for a greater height to maximize the area.
        
        int left=0;
        int right=n-1;
        int area=0;

        while(left<right){
            area=max(area,min(height[left],height[right])*(right-left));
            if(height[left]<=height[right])
                left++;
            else{
                right--;
            }
        }
        return area;
    }
};