class Solution {
public:
    
    int len=0;
    void rec(vector<char>& s,int i){
        if(i==s.size())
            return;
        rec(s,i+1);
        if(i<s.size()/2)
            swap(s[i],s[s.size()-1-i]);
    }
    
    
    
    void reverseString(vector<char>& s) {
        rec(s,0);
    }
};