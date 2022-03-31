class Solution {
public:
    bool isPowerOfThree(int n) {
        
        
        if(n==1)
            return true;
        if(n<1)return false;
        int t=3;
        for(int i=1;i<32;i++)

        {
            if(n==t)return true;
            if(t>=INT_MAX/3)return false;
            t*=3;
        }
        return false;
        
    
    }
};