class Solution {
public:

    int uniquePaths2(int m, int n) {

        if (m == 0 and n == 0) {
            return 1;
        }


        if (m < 0 or n < 0) {
            return 0;
        }

        int Option1 = uniquePaths2(m, n - 1);
        int Option2 = uniquePaths2(m - 1, n);

        return Option1 + Option2;
    }


    int uniquePaths(int m, int n) {
        return uniquePaths2(m - 1, n - 1);
    }
};




