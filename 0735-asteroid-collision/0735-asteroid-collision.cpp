class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            bool alive = true;

            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                int sum = asteroids[i] + st.top();

                if (sum < 0) {
                    st.pop();
                }
                else if (sum > 0) {
                    alive = false;
                    break;
                }
                else {
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(asteroids[i]);
            }
        }

        vector<int> result(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};