class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                //-ve number detected
                while (!st.empty() && st.top() > 0 &&
                       st.top() < std::abs(asteroids[i]))
                    st.pop();

                if (!st.empty() && st.top() == std::abs(asteroids[i]))
                    st.pop();
                else if (st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        if (st.empty())
            return ans;
        else {
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }

            std::reverse(ans.begin(), ans.end());
            return ans; 
        }
    }
};
