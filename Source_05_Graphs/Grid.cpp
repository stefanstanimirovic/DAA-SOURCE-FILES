#include <iostream>
#include <vector>
using namespace std;

class Grid
{
private:
    vector<vector<char>> matrix; // tabla
    vector<vector<bool>> visited; // posecena polja table
    int size; // velicina trenutne komponente
    int largest_size; // velicina najvece komponente
    int num_components; // broj komponenti
public:
    Grid(vector<vector<char>> m) : matrix(m), size(0), largest_size(0), num_components(0)
    {}

    void DFSFromNode(int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] 
            || matrix[i][j] != 'O') {
            return;
        }

        visited[i][j] = true;
        size++;

        DFSFromNode(i - 1, j);
        DFSFromNode(i + 1, j);
        DFSFromNode(i, j - 1);
        DFSFromNode(i, j + 1);
    }

    pair<int, int> countComponentsAndLargestSize() {
        int n = matrix.size();
        int m = matrix[0].size();
        num_components = 0;
        largest_size = 0;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && matrix[i][j] == 'O') {
                    size = 0;
                    DFSFromNode(i, j);
                    num_components++;
                    largest_size = max(largest_size, size);
                }
            }
        }
        return make_pair(num_components, largest_size);
    }
};

int Grid_main() {
    vector<vector<char>> matrix = {
        {'X', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'X', 'O', 'X'},
        {'O', 'X', 'X', 'O', 'O'}
    };

    Grid grid(matrix);
    pair<int, int> result = grid.countComponentsAndLargestSize();
    cout << result.first << " " << result.second << endl;

    return 0;
}