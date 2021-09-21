class Solution {
public:
    int climbStairs(int n) {
        // To Climb stairs to cS(n + 1)
        // cS(n) + 1 step
        // cs(n - 1) + 2step, because cs(n - 1) + 1 is contained in cs(n), so fibonacci
        int cs[45] = {};
        cs[0] = 1;
        cs[1] = 2;
        for (int i = 2; i < 45; i++) {
            cs[i] = cs[i - 1] + cs[i - 2];
        }
        return cs[n - 1];
    }
};
