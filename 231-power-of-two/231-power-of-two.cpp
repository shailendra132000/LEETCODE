class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==1)
            return true;
        if(n<1)return false;
        int t=2;
        for(int i=1;i<32;i++)

        {
            if(n==t)return true;
            if(t>=INT_MAX/2)return false;
            t*=2;
        }
        return false;
        
    
        
    }
};