#include <iostream>
#include <vector>
using namespace std;

int countPaths(const vector<vector<int>>& mat, int i, int j, int cost) {
    if (i < 0 || j < 0 || cost < 0) return 0;
    if (i == 0 && j == 0) return (cost == mat[0][0]) ? 1 : 0;
    return countPaths(mat, i - 1, j, cost - mat[i][j]) +
           countPaths(mat, i, j - 1, cost - mat[i][j]);
}

int countMemo(const vector<vector<int>>& mat, int i, int j, int cost,
              vector<vector<vector<int>>>& memo) {
    if (i < 0 || j < 0 || cost < 0) return 0;
    if (i == 0 && j == 0) return (cost == mat[0][0]) ? 1 : 0;
    int& res = memo[i][j][cost];
    if (res != -1) return res;
    return res = countMemo(mat, i - 1, j, cost - mat[i][j], memo) +
                 countMemo(mat, i, j - 1, cost - mat[i][j], memo);
}

int main() {
    vector<vector<int>> mat = {
        {4, 7, 1, 6},
        {5, 7, 3, 9},
        {3, 2, 1, 2},
        {7, 1, 6, 3}
    };
    int cost = 25;
    int M = mat.size(), N = mat[0].size();

    cout << "Plain recursion: " << countPaths(mat, M - 1, N - 1, cost) << endl;

    vector<vector<vector<int>>> memo(M, vector<vector<int>>(N, vector<int>(cost + 1, -1)));
    cout << "Memoized: " << countMemo(mat, M - 1, N - 1, cost, memo) << endl;
    return 0;
}
