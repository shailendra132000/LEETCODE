class Solution {
public:
    
    void rec(vector<char>& s,int i,int j){
        if(i>j)
            return;
        swap(s[i],s[j]);
        rec(s,++i,--j);
    }
    
    
    
    void reverseString(vector<char>& s) {
        rec(s,0,s.size()-1);
    }
};