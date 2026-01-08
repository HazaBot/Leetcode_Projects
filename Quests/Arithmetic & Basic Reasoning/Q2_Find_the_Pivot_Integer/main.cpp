#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

std::vector<int> arr;
std::vector<int> prefixSum;


int n = 49;

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return 1;
		arr = std::vector<int>(n, 0);
        prefixSum = std::vector<int>(n, 0);
        std::iota(arr.begin(), arr.end(), 1);
        std::partial_sum(arr.begin(), arr.end(), prefixSum.begin());

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == (prefixSum.back() - prefixSum[i] + arr[i])) {
                return arr[i];
            }
        }
        return -1;
    }
};


class SolutionImproved {
public:
    int pivotInteger(int n) {
		int totalSum = n * (n + 1) / 2;
		int x = sqrt(totalSum);
		if (x * x == totalSum) { // Check if totalSum is a perfect square doesnt work in pure maths but with an int it does
			return x;
        }
        return -1;
    }
};


int main() {
    SolutionImproved solution;
    cout << solution.pivotInteger(n) << endl;
};