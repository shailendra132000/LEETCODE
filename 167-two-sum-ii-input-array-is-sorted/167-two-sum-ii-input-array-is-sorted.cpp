class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
		vector<int> ans;
		
		
        int p1=0;
        int p2 = numbers.size()-1;
        
         while (p1<p2){
             
             if (numbers[p1]+numbers[p2]==target){
                 
                 ans.push_back(p1+1);
                 ans.push_back(p2+1);
                 
                 return ans;
             }
             
             else if (numbers[p1]+numbers[p2]>target){
                 
                 p2--;
             }
             
             else{
				 
                 p1++;   
             }
         }
        
        return ans;
    }
};