// DP solution with memento by hxdone

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
        vector<vector<int> > memento;
        vector<vector<int> > edge_memento;
        for (int i = 0; i <= m; ++i) {
            memento.push_back(vector<int>());
            edge_memento.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                memento[i].push_back(-1);
                edge_memento[i].push_back(-1);
            }
            memento[i].push_back(0);
            edge_memento[i].push_back(0);
        }
        for (int j = 0; j < n; ++j) { 
            memento[m][j] = 0;
            edge_memento[m][j] = 0;
        }

        int ret = maximalSquare(0, 0, matrix, memento, edge_memento);
        return ret;
    }
    
private:
    int maximalSquare(int i, int j, const vector<vector<char> >& matrix, vector<vector<int> >& memento, vector<vector<int> >& edge_memento) {
        if (memento[i][j] != -1)
            return memento[i][j];
        memento[i][j] = std::max(maximalSquare(i+1,j,matrix,memento,edge_memento), maximalSquare(i,j+1,matrix,memento,edge_memento));
        if (matrix[i][j] == '1') {
            int edge = squareEdge(i,j,matrix,edge_memento);
            memento[i][j] = std::max(edge*edge, memento[i][j]);
        }
        return memento[i][j];
    }
    
    int squareEdge(int i, int j, const vector<vector<char> >& matrix, vector<vector<int> >& edge_memento) {
        if (edge_memento[i][j] != -1) {
            return edge_memento[i][j];
		}
		if (matrix[i][j] == '0') {
			edge_memento[i][j] = 0;
			return edge_memento[i][j];
		}
        int edge = std::min(squareEdge(i+1, j, matrix, edge_memento), squareEdge(i, j+1, matrix, edge_memento));
        if (matrix[i+edge][j+edge] == '1')
            edge = edge+1;
        edge_memento[i][j] = edge;
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
