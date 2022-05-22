class Solution {
public:
    int countSubstrings(string s){
    int n = s.size(), count = 0;
    int dp[n][n];
    for (int gap = 0; gap < n; gap++){
        for (int i = 0, j = gap; j < n; i++, j++){
            if (gap == 0){ // when the string is like a, b, c so it's a palindrome
                count++;
                dp[i][j] = 1;
            } else if (gap == 1){ // when the string is of length 2 like ab, bb, cd
                if (s[i] == s[j]) // if the string of i and j are equal then it's a palindrome
                {
                    dp[i][j] = 1;
                    count++;
                }else{
                    dp[i][j] =  0;
                }
            }
            else
            {// for the gap greater than and equal to 2  if the string of i and j are equal than check for  dp[i+1][j-1] is also a palindrome then it will be also 
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    count++;
                }else{
                    dp[i][j] =  0;
                }
            }
        }
    }
    return count;
}
};