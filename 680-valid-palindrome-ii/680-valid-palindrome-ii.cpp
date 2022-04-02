class Solution {
public:
    
    bool isp(string s,int i,int j)
    {
        while(i<j){
            if(s[i]!=s[j])
                return 0;
        i++,j--;
    }
    return 1;
}
    bool validPalindrome(string s) 
        
    {  if(isp(s,0,s.size()-1))
        return true;
        
        int i=0,j=s.size()-1;
        while(i<j && s[i]==s[j])
        {
          i++,j--;  
            
        }
            
        if(isp(s,i,j-1) || isp(s,i+1,j))
        return true;
     return false;
        
    }
};