#include <iostream>
#include <vector>


class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        if (k == 0 || n >= k - 1 + maxPts) {
            return 1.0;
		}

		// cant do double dp[n + 1]; as arrays cannot be initialized with a non-constant size so vector is used
		std::vector<double> dp(n + 1, 0.0);
		dp[0] = 1.0;

        double W = 1.0; //rolling probablity
		double ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = W / maxPts;
            if (i < k) {
                W += dp[i];
            }
            else {
                ans += dp[i];
            }
            if (i - maxPts >= 0 and (i - maxPts) < k) {
                W -= dp[i - maxPts];
            }
        }
        return ans;
    }
};

int main () {
    Solution solution;
    std::cout << solution.new21Game(6, 1, 10) << std::endl;
    return 0;
}
