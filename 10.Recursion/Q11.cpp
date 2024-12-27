// Rat in a Maze problem:-


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &visit, vector<vector<int>> &m, int n) {
    // Check if the cell is within bounds and not visited, and the path is open (1)
    if (x < 0 || x >= n || y < 0 || y >= n || visit[x][y] == 1 || m[x][y] == 0) 
        return false;
    return true;
}

void solve(vector<vector<int>> &m, int n, vector<vector<int>> &visit, int x, int y, string path, vector<string> &ans) {
    // Base case: Reach the bottom-right corner
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    
    // Mark the cell as visited
    visit[x][y] = 1;

    // Explore paths in lexicographical order: Down, Left, Right, Up
    if (isSafe(x + 1, y, visit, m, n)) {
        path.push_back('D');
        solve(m, n, visit, x + 1, y, path, ans);
        path.pop_back();
    }
    if (isSafe(x, y - 1, visit, m, n)) {
        path.push_back('L');
        solve(m, n, visit, x, y - 1, path, ans);
        path.pop_back();
    }
    if (isSafe(x, y + 1, visit, m, n)) {
        path.push_back('R');
        solve(m, n, visit, x, y + 1, path, ans);
        path.pop_back();
    }
    if (isSafe(x - 1, y, visit, m, n)) {
        path.push_back('U');
        solve(m, n, visit, x - 1, y, path, ans);
        path.pop_back();
    }

    // Backtrack: Unmark the cell as visited
    visit[x][y] = 0;
}


vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> ans;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return ans; 

    vector<vector<int>> visit(n, vector<int>(n,0));
    string path = "";
    
    solve(m,n, visit, 0, 0, path, ans);
    
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze matrix (0 for open path, 1 for blocked path):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    // Display the maze
    cout << "The maze is:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"================================="<<endl;
    vector<string> paths = findPath(maze,n);
    if (paths.empty()) {
        cout << "No path exists." << endl;
    } else {
        cout << "The paths are:" << endl;
        for (const string &path : paths) {
            cout << path << endl;
        }
    }
    return 0;
}
