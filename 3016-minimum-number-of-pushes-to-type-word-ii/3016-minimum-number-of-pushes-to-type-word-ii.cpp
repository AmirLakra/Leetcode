#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        // Step 2: Extract frequencies and sort them in descending order
        vector<int> frequencies;
        for (auto pair : freqMap) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        // Step 3: Compute total pushes
        int totalPushes = 0;
        for (int i = 0; i < frequencies.size(); i++) {
            int pushesPerChar = (i / 8) + 1; // 1st-8th: 1 push, 9th-16th: 2 pushes, etc.
            totalPushes += frequencies[i] * pushesPerChar;
        }

        return totalPushes;
    }
};