class Solution {
public:
    int numberOfSteps(int n, int res = 0) {
        return n ? numberOfSteps(n & 1 ? n - 1 : n >> 1, res + 1) : res;
    }
};