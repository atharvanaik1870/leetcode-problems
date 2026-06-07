//Using Boyer-Moore Majority Voting

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //usng morre's voting also extened version
        int cnt1=0, cnt2=0;
        int el1;
        int el2;
        int n = nums.size();

        for (int i=0;i<n;i++)
        {
            if (cnt1 == 0 && nums[i]!=el2)
            {
                cnt1 =1 ;
                el1=nums[i];
            }
            else if (cnt2 == 0 && nums[i]!=el1)
            {
                cnt2 = 1;
                el2=nums[i];
            }
            else if(nums[i] == el1)
            {
                cnt1++;
            }
            else if(nums[i] == el2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        //check if those 2 els are the majority elements
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        vector<int> v1;
        n=n/3 + 1;
        if(cnt1 >= n) v1.push_back(el1);
        if(cnt2 >= n) v1.push_back(el2);

        return v1;
    }
};

//Approach 2 : using hasmap (TimeCOmplexity O(logN))
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int , int> m;
        vector <int> v1;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
        } 
        n=n/3;
        for(auto x: m)
        {
            if (x.second > n)
            {
                v1.push_back(x.first);
            }
        }
        return v1;
    }
};
