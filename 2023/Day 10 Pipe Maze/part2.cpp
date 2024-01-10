#include<iostream>
#include<fstream>
#include<sstream>
#include <algorithm>
#include<vector>
#include <cassert>
#include<set>
#include<unordered_set>
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

    unordered_set<char> maybeS = {'|', '-', 'J', 'L', '7', 'F'};
    unordered_set<char> intersectionSet;
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
                
                if (ch == 'S') {
                    intersectionSet = {'|', 'J', 'L'};
                    for (auto it = maybeS.begin(); it != maybeS.end();) {
                        if (intersectionSet.find(*it) == intersectionSet.end()) {
                            it = maybeS.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            } 

        if (r < grid.size() -1 &&
            string("S|7F").find(ch) != string::npos && 
            string("|JL").find(grid[r+1][c]) != string::npos &&
            loop.find(make_pair(r + 1, c)) == loop.end()) {

                loop.insert(make_pair(r + 1, c));
                q.push_back(make_pair(r + 1, c));

                if (ch == 'S') {
                    intersectionSet = {'|', '7', 'F'};
                    for (auto it = maybeS.begin(); it != maybeS.end();) {
                        if (intersectionSet.find(*it) == intersectionSet.end()) {
                            it = maybeS.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }

        if (c > 0 && 
            string("S-J7").find(ch) != string::npos && 
            string("-LF").find(grid[r][c - 1]) != string::npos &&
            loop.find(make_pair(r, c - 1)) == loop.end()) {
                loop.insert(make_pair(r, c - 1));
                q.push_back(make_pair(r, c - 1));

                if (ch == 'S') {
                    intersectionSet = {'-', 'J', '7'};
                    for (auto it = maybeS.begin(); it != maybeS.end();) {
                        if (intersectionSet.find(*it) == intersectionSet.end()) {
                            it = maybeS.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }

        if (c < grid[r].size() - 1 && 
            string("S-LF").find(ch) != string::npos && 
            string("-J7").find(grid[r][c + 1]) != string::npos &&
            loop.find(make_pair(r, c + 1)) == loop.end()) {
                loop.insert(make_pair(r, c + 1));
                q.push_back(make_pair(r, c + 1));

                if (ch == 'S') {
                    intersectionSet = {'-', 'L', 'F'};
                    for (auto it = maybeS.begin(); it != maybeS.end();) {
                        if (intersectionSet.find(*it) == intersectionSet.end()) {
                            it = maybeS.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }        
    }   
    char S;
    if (maybeS.size() == 1) {
        S = *maybeS.begin();
    }

    for (vector<char>& row : grid) {
        replace(row.begin(), row.end(), 'S', S);
    }

    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[r].size(); ++c) {
            grid[r][c] = (loop.find({r, c}) != loop.end()) ? grid[r][c] : '.';
        }
    }

    set<pair<int, int>> outside;

    for (int r = 0; r < grid.size(); r++) {
        bool within = false;
        int* up = nullptr;
        for (int c = 0; c < grid[r].size(); c++) {
            char ch = grid[r][c];

            if (ch == '|') {
                // assert(!up);
                assert(up == nullptr);
                within = !within;
            } else if (ch == '-') {
                // assert(up);
                assert(up != nullptr);
            } else if (ch == 'L' || ch == 'F') {
                // assert(!up);
                assert(up == nullptr);
                up = new int(ch == 'L' ? 1 : 0);
            } else if (ch == '7' || ch == 'J') {
                assert(up != nullptr);
                if ((ch == 'J' && *up == 0) || (ch == '7' && *up == 1)) {
                    within = !within;
                }
                delete up;  
                up = nullptr; 
            } else if (ch == '.') {

            } else {
                throw std::runtime_error("Unexpected character (horizontal): " + std::string(1, ch));
            }

            if (!within) {
                outside.insert({r, c});
            }
        }
    }

 
    int result = grid.size() * grid[0].size() - (outside.size() + loop.size());

    cout << result;
    

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






