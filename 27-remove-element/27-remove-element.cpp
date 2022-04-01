class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==val){
                count++;
            }else{
                nums[left]=nums[right];
                left++;
            }
        }
        return nums.size()-count;
    }
};