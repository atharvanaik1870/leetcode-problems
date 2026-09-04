class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;
    StockSpanner() {
        while (!st.empty()) {
            st.pop();
        }
        index = -1;
    }

    int next(int price) {
        index++;
        //using logic of previous greater element - only store previous elemnets which are greater then the current elemnet 
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
