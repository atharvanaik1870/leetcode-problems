class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        //ans iwll be 1st empty so just add the array directly
        //please notice that we are comparing the array and the answer array 
        //if the 1st elemnt of the array i.e arr[i][0] > ans.back()[1] this means that there is no over lap since the qst elemnt is bogger tha last of previous's last elemnt
        std::sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else {
                //if there is overlap then we update the [i][1] element that is last of curr array to max of current last and array's last
                ans.back()[1] = std::max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};
