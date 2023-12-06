#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
bool checkNumAdjToSymbol(char ch, int row, int col, vector<vector<char>>& grid) {
    if (
            (col > 0) && (grid[row][col-1] != '.' && !isalnum(grid[row][col-1])) ||
            (col < grid[0].size()-1) && (grid[row][col+1] != '.' && !isalnum(grid[row][col+1])) || 
            (row < grid.size()-1) && (grid[row+1][col] != '.' && !isalnum(grid[row+1][col])) || 
            (row > 0) && (grid[row-1][col] != '.' && !isalnum(grid[row-1][col])) || 
            (row > 0 && col > 0) && (grid[row-1][col-1] != '.' && !isalnum(grid[row-1][col-1])) || 
            (row > 0 && col < grid[0].size()-1) && (grid[row-1][col+1] != '.' && !isalnum(grid[row-1][col+1])) || 
            (row < grid.size()-1 && col > 0) && (grid[row+1][col-1] != '.' && !isalnum(grid[row+1][col-1])) || 
            (row < grid.size()-1 && col < grid[0].size()-1) && (grid[row+1][col+1] != '.' && !isalnum(grid[row+1][col+1])) 
    ) {
        return true;
    } 

    return false;
}
int helper(vector<vector<char>>& grid) {

    int sum = 0;
    string digit = "";
    string check = "";

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col  < grid[0].size(); col++) {
            if (isdigit(grid[row][col]) && col != grid[0].size()-1) {
                digit += grid[row][col];

                if (checkNumAdjToSymbol(grid[row][col], row, col, grid)) {
                        check = "ok";
                }  

            } else {

                if (col == grid[0].size()-1) {
                    digit += grid[row][col];

                    if (checkNumAdjToSymbol(grid[row][col], row, col, grid)) {
                        check = "ok";
                    }  
                }
                if (digit != "") {
                    if (check == "ok") {
                        sum += stoi(digit);
                        check = "";
                    }
                    digit = "";
                }
            }
        }
    }
    return sum;
   
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 3 Gear Ratios/input.txt");
    vector<vector<char>> data;
    string line;

    while (getline(inputFile, line)) {

        vector<char> row(line.begin(), line.end());
        data.push_back(row);
    }
    
    int ans = helper(data);
  
    cout << ans;
    return 0;
}