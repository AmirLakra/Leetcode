#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    bool canMakeBouquets(const std::vector<int>& bloomDay, int days, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; 
                }
            } else {
                count = 0; 
            }
        }
        return bouquets >= m;
    }

public:
    int find_max_days(const std::vector<int>& bloomDay) {
        int max_ans = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            max_ans = std::max(max_ans, bloomDay[i]);
        }
        return max_ans;
    }

    int find_min_days(const std::vector<int>& bloomDay) {
        int min_ans = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++) {
            min_ans = std::min(min_ans, bloomDay[i]);
        }
        return min_ans;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int start = find_min_days(bloomDay);
        int end = find_max_days(bloomDay);
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canMakeBouquets(bloomDay, mid, m, k)) {
                ans = mid;     
                end = mid - 1;
            } else {
                start = mid + 1; 
            }
        }

        return ans;
    }
};