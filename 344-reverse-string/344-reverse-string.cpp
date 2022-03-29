class Solution {
public:
    
    vector<char> str;
    void rec(vector<char>& s,int i){
        if(i==s.size())
            return;
        rec(s,i+1);
        str.push_back(s[i]);
    }
    
    
    
    void reverseString(vector<char>& s) {
        rec(s,0);
        s=str;
    }
};