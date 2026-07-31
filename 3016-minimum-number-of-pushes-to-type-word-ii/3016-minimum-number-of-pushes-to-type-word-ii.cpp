#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> frequencies;
        for (auto pair : freqMap) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        int ans = 0;
        for (int i = 0; i < frequencies.size(); i++) {
            int taps = (i / 8) + 1;
            ans += frequencies[i] * taps;
        }

        return ans;
    }
};