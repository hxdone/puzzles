// Iterative DP solution by hxdone

#include<iostream>
#include<vector>
#include<cstring>
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
        int* memento = new int[(m+1)*(n+1)];
        int* edge_memento =  new int[(m+1)*(n+1)]; 
        memset(memento, 0, sizeof(int)*(m+1)*(n+1));
        memset(edge_memento, 0, sizeof(int)*(m+1)*(n+1));

        for (int i = m-1; i >= 0; --i )
            for (int j = n-1; j >= 0; --j) {
                squareEdge(i, j, matrix, edge_memento);
                maximalSquare(i, j, matrix, memento, edge_memento);
            }
        int ret = memento[0];
        delete[] memento;
        delete[] edge_memento;
        return ret;
    }
    
private:
    int maximalSquare(int i, int j, const vector<vector<char> >& matrix, int* memento, int* edge_memento) {
        int n =  matrix[0].size();
        memento[i*n+j] = std::max(memento[(i+1)*n+j], memento[i*n+j+1]);
        if (matrix[i][j] == '1') {
            int edge = edge_memento[i*n+j];
            memento[i*n+j] = std::max(edge*edge, memento[i*n+j]);
        }
        return memento[i*n+j];
    }
    
    int squareEdge(int i, int j, const vector<vector<char> >& matrix, int* edge_memento) {
        int n =  matrix[0].size();
        if (matrix[i][j] == '0') {
            edge_memento[i*n+j] = 0;
            return edge_memento[i*n+j];
        }
        int edge = std::min(edge_memento[(i+1)*n+j], edge_memento[i*n+j+1]);
        if (matrix[i+edge][j+edge] == '1')
            ++edge;
        edge_memento[i*n+j] = edge;
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
    for (int i = 0 ;i < 10000; ++i)
        cout << "case 1: " << s.maximalSquare(matrix) << endl;
    return  0;
}
