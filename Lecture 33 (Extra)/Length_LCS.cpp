class Solution {
public:
	int dp[1001][1001];
	int LengthLCS(string &s, string &t, int i, int j) {

		if (i >= s.length() or j >= t.length()) {
			return 0;
		}

		if (dp[i][j] != -1) {
			return dp[i][j];
		}


		if (s[i] == t[j]) {
			return dp[i][j] = 1 + LengthLCS(s, t, i + 1, j + 1);
		} else {

			//S[i] is in my Answer.
			int Option1 = LengthLCS(s, t, i + 1, j);

			//t[j] is in my Answer.
			int Option2 = LengthLCS(s, t, i, j + 1);

			return dp[i][j] = max(Option1, Option2);

		}
	}

	int longestCommonSubsequence(string s, string t) {
		memset(dp, -1, sizeof(dp));
		return LengthLCS(s, t, 0, 0);
	}

};