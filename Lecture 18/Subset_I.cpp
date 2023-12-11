
#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
    vector<vector<int>>ans;

    void Solve(vector<int>nums, int index, vector<int>Current, int n) {

        if (index == n) {
            ans.push_back(Current);
            return;
        }

        //Include
        Current.push_back(nums[index]);
        Solve(nums, index + 1, Current, n);

        //Backtracking
        Current.pop_back();


        //Exclude
        Solve(nums, index + 1, Current, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>Current;
        Solve(nums, 0, Current, n);
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

    vector<vector<int>>ans = Obj.subsets(nums);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}