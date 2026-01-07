#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> arr = { 3, 5, 1, 6, 6};

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end()); // usese introsort 
		int step = arr[1] - arr[0];
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] != step) {
				return false;
           }
        }
    return true;
    }
};

int main() {
    Solution solution;
    cout << solution.canMakeArithmeticProgression(arr) << endl;

};
