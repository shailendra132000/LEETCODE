class Solution {
public:
    int trailingZeroes(int n) {
        
        int z=0;
       for(int i=5;i<=n;i=i*5)
       {
           z=z+n/i;
       }
       return z;
    }
};