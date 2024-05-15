#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class JumperChessBoard
{
private:
    int n; // dimenzija table
    vector<vector<char>> board; // tabla
    vector<vector<bool>> visited; // posecena polja
    vector<vector<int>> dist; // rastojanja
    int xS, yS; // pocetna pozicija skakaca
    int xE, yE; // zavrsna pozicija skakaca
    static const vector<pair<int, int>> directions;
public:
    JumperChessBoard() : xS(-1), yS(-1), xE(-1), yE(-1) {
        cin >> n;
        board = vector<vector<char>>(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'S') {
                    xS = i;
                    yS = j;
                }
                else if (board[i][j] == 'E') {
                    xE = i;
                    yE = j;
                }
            }
        }
    }

    int shortestPath() {
        if (xS == -1 || yS == -1 || xE == -1 || yE == -1
            || board[xS][yS] == 'X' || board[xE][yE] == 'X') {
            return -1;
        }

        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        dist = vector<vector<int>>(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({ xS, yS });
        dist[xS][yS] = 0;
        visited[xS][yS] = true;
        bool found = false;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == xE && y == yE) {
                found = true;
                break;
            }

            for (pair<int, int> dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && 
                    !visited[nx][ny] && board[nx][ny] != 'X') {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }

        return found ? dist[xE][yE] : -1;
    }
};

const vector<pair<int, int>> JumperChessBoard::directions =
{ {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };

int JumperChessBoard_main() {
    JumperChessBoard board;
    int result = board.shortestPath();
    if (result != -1) {
        cout << "DA" << endl;
        cout << "Najkraci put: " << result << " koraka" << endl;
    }
    else {
        cout << "NE" << endl;
    }
    return 0;
}