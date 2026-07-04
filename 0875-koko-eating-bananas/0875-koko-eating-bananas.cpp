class Solution {
public:
    long long speed(vector<int>& piles, int hourly) {
        long long total = 0;

        for (int i = 0; i < piles.size(); i++) {
            total += (long long)(piles[i] + hourly - 1) / hourly;
        }

        return total;
    }

    int find_max_element(vector<int>& piles) {
        int ans = INT_MIN;

        for (int i = 0; i < piles.size(); i++) {
            ans = max(ans, piles[i]);
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = find_max_element(piles);

        while (start <= end) {
            int mid = start + (end - start) / 2;

            long long eats = speed(piles, mid);

            if (eats <= h) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};