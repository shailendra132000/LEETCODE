class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ans=0;
        int l=0,h=height.size()-1;
        while(l<h)
        {
            ans=max(ans,(h-l)*min(height[l],height[h]));
            if(height[l]<height[h])l++;
            else h--;
        }
        return ans;
    }
};
        

