
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
public:
    vector<vector<int>>ans;
    void Solve(vector<int>&nums, int index, int n) {
        if (index == n - 1) {
            ans.push_back(nums);
            return;
        }

        set<int>s;

        for (int i = index; i < n; i++) {
            if (s.count(nums[i]) == 1) {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[i], nums[index]);
            Solve(nums, index + 1, n);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        Solve(nums, 0, n);
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

    vector<vector<int>>ans = Obj.permuteUnique(nums);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}


