class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {

        int n = a.size();
        sort(a.begin(), a.end());
        vector<pair<int, int>>b;

        for (int i = 0; i < n; i++) {
            b.push_back({B[i], i});
        }

        sort(b.begin(), b.end());
        vector<int>ans(n, -1);

        vector<int>Extra;
        int j = 0;

        for (int i = 0; i < n; i++) {

            if (a[i] > b[j].first) {
                ans[b[j].second] = a[i];
                j++;
            } else {
                Extra.push_back(a[i]);
            }

        }

        if (Extra.size() == 0) {
            return ans;
        }

        j = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == -1) {
                ans[i] = Extra[j];
                j++;
            }

            if (j == Extra.size()) {
                break;
            }
        }

        return ans;

    }
};