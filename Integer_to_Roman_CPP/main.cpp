#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanChar = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };
		string result = "";
        for (auto& [value, symbol] : romanChar) {
            if (num == 0) break;
            int count = num / value;
            for (int i = 0; i < count; i++) {
                result += symbol;
            }
            num -= count * value;
        }
		return result;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(4) << endl;

};
