class Solution {
public:
    bool isPalindrome(int x) {
        long x_copy = x;
        long reverse = 0;
        while (x_copy > 0) {
            reverse = reverse*10 + x_copy%10;
            x_copy/=10;
        }
        return reverse == x ? 1:0;
    }
};