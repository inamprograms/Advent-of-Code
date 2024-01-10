#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include <deque>
using namespace std;
vector<vector<char>> grid;
void solve() {
    int sr = -1, sc = -1;
    // Find starting row and column index
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == 'S') {
                sr = row;
                sc = col;
                break;
            } else {
                continue;
            }
        }
        if (sr != -1 && sc != -1) {
            break;
        }
    }

    // Find the path
    set<pair<int, int>> loop = {{sr, sc}};
    deque<pair<int, int>> q = {{sr, sc}};

    while (!q.empty())
    {
        pair<int, int> left = q.front();
        int r = left.first;
        int c = left.second;
        q.pop_front();

        char ch = grid[r][c];

        if (r > 0 && 
            string("S|JL").find(ch) != string::npos && 
            string("|7F").find(grid[r-1][c]) != string::npos &&
            loop.find(make_pair(r - 1, c)) == loop.end()) {

                loop.insert(make_pair(r - 1, c));
                q.push_back(make_pair(r - 1, c));
            } 

        if (r < grid.size() -1 &&
            string("S|7F").find(ch) != string::npos && 
            string("|JL").find(grid[r+1][c]) != string::npos &&
            loop.find(make_pair(r + 1, c)) == loop.end()) {

                loop.insert(make_pair(r + 1, c));
                q.push_back(make_pair(r + 1, c));
            }

        if (c > 0 && 
            string("S-J7").find(ch) != string::npos && 
            string("-LF").find(grid[r][c - 1]) != string::npos &&
            loop.find(make_pair(r, c - 1)) == loop.end()) {
                loop.insert(make_pair(r, c - 1));
                q.push_back(make_pair(r, c - 1));
            }

        if (c < grid[r].size() - 1 && 
            string("S-LF").find(ch) != string::npos && 
            string("-J7").find(grid[r][c + 1]) != string::npos &&
            loop.find(make_pair(r, c + 1)) == loop.end()) {
                loop.insert(make_pair(r, c + 1));
                q.push_back(make_pair(r, c + 1));
            }        
    }   
    int pathLength = loop.size();
    cout << pathLength / 2;
    

}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 10 Pipe Maze/input.txt");
   
    string line;
    while (getline(inputFile, line)) {

        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
       
    }

    solve();
    
    
  

    return 0;
} 






