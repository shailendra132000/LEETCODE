class Solution {
public:
    unordered_map<char,vector<string> > mp;
    vector<string> ans;
   void f_backtrack(int start, string curr, string digits)
{
	int n = digits.size();
	if(start==n)
	{
		ans.push_back(curr);
		
	}
	vector<string> vect = mp[digits[start]];
	for(int i=0; i<vect.size(); i++)
	{
		string s = vect[i];
		curr += s;
		f_backtrack(start+1,curr,digits);
		curr.pop_back();
	}
}
vector<string> letterCombinations(string digits) {
	if(digits=="")
	{
		vector<string> vect;
		return vect;
	}
	
	mp['2'] = {"a","b","c"};
	mp['3'] = {"d","e","f"};
	mp['4'] = {"g","h","i"};
	mp['5'] = {"j","k","l"};
	mp['6'] = {"m","n","o"};
	mp['7'] = {"p","q","r","s"};
	mp['8'] = {"t","u","v"};
	mp['9'] = {"w","x","y","z"};
	f_backtrack(0,"",digits);
	return ans;
}
};