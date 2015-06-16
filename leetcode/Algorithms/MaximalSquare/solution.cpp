// DP solution by hxdone

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;
        vector<vector<int> > memo;
        vector<vector<int> > edge_memo;
        for (int i = 0; i <= m; ++i) {
            memo.push_back(vector<int>());
            edge_memo.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                memo[i].push_back(-1);
                edge_memo[i].push_back(-1);
            }
            memo[i].push_back(0);
            edge_memo[i].push_back(0);
        }
        for (int j = 0; j < n; ++j) { 
            memo[m][j] = 0;
            edge_memo[m][j] = 0;
        }

        int ret = maximalSquare(0, 0, matrix, memo, edge_memo);
        return ret;
    }
    
private:
    int maximalSquare(int i, int j, const vector<vector<char> >& matrix, vector<vector<int> >& memo, vector<vector<int> >& edge_memo) {
        if (memo[i][j] != -1)
            return memo[i][j];
        memo[i][j] = std::max(maximalSquare(i+1,j,matrix,memo,edge_memo), maximalSquare(i,j+1,matrix,memo,edge_memo));
        if (matrix[i][j] == '1') {
            int edge = squareEdge(i,j,matrix,edge_memo);
            memo[i][j] = std::max(edge*edge, memo[i][j]);
        }
        return memo[i][j];
    }
    
    int squareEdge(int i, int j, const vector<vector<char> >& matrix, vector<vector<int> >& edge_memo) {
        if (edge_memo[i][j] != -1) {
            return edge_memo[i][j];
		}
		if (matrix[i][j] == '0') {
			edge_memo[i][j] = 0;
			return edge_memo[i][j];
		}
        int edge = std::min(squareEdge(i+1, j, matrix, edge_memo), squareEdge(i, j+1, matrix, edge_memo));
        if (matrix[i+edge][j+edge] == '1')
            edge = edge+1;
        edge_memo[i][j] = edge;
        return edge;
    }
};

int main() {
	Solution s;
	vector<vector<char> > matrix;
	for(int i = 0; i < 3; ++i)
		matrix.push_back(vector<char>());
	matrix[0].push_back('1');
	matrix[0].push_back('1');
	matrix[0].push_back('0');
	matrix[0].push_back('1');

	matrix[1].push_back('1');
	matrix[1].push_back('1');
	matrix[1].push_back('0');
	matrix[1].push_back('1');

	matrix[2].push_back('1');
	matrix[2].push_back('1');
	matrix[2].push_back('1');
	matrix[2].push_back('1');

	cout << "case 1: " << s.maximalSquare(matrix) << endl;
	return  0;
}
