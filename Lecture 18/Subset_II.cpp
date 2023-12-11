
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
    vector<vector<int>>ans;
public:
    void Solve(vector<int>nums, int index, vector<int>&Current) {
        ans.push_back(Current);

        for (int i = index; i < nums.size(); i++) {
            if (i != index and nums[i] == nums[i - 1]) {
                continue;
            }

            Current.push_back(nums[i]);
            Solve(nums, i + 1, Current);
            Current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        vector<int>Current;
        sort(nums.begin(), nums.end());
        Solve(nums, 0, Current);
        return ans;
    }
};



int main() {

    Solution Obj;
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>>ans = Obj.subsetsWithDup(nums);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}