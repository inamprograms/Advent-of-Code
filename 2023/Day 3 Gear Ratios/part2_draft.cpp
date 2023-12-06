#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
vector<int> checkNumAdjToSymbol(char ch, int row, int col, vector<vector<char>>& grid) {
    
    if ( (col > 0) && (grid[row][col-1] == '*') ) {
        return {row, col-1};
    } else if ( (col < grid[0].size()-1) && (grid[row][col+1] == '*') ) {
        return {row, col+1};
    } else if ( (row < grid.size()-1) && (grid[row+1][col] == '*') ) {
        return {row+1, col};
    } else if (  (row > 0) && (grid[row-1][col] == '*') ) {
        return {row-1, col};
    } else if (  (row > 0 && col > 0) && (grid[row-1][col-1] == '*') ) {
        return {row-1, col-1};
    } else if ( (row > 0 && col < grid[0].size()-1) && (grid[row-1][col+1] == '*') ) {
        return {row-1, col+1};
    } else if ( (row < grid.size()-1 && col > 0) && (grid[row+1][col-1] == '*') ) {
        return {row+1, col-1};
    } else if ( (row < grid.size()-1 && col < grid[0].size()-1) && (grid[row+1][col+1] == '*') ) {
        return {row+1, col+1};
    } else {
        return {-1, -1};
    }
}
int helper(vector<vector<char>>& grid) {

    int sum = 0, temp1 = -1, temp2 = -1;
    string digit = "";
    string check = "";
    vector<int> gearsLoc = {-1, -1};
    string gear1 = "", gear2 = "";
    bool adjacent = false, noIn, update;

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col  < grid[0].size(); col++) {
            if (isdigit(grid[row][col]) && col != grid[0].size()-1) {
                digit += grid[row][col];
               
                gearsLoc = checkNumAdjToSymbol(grid[row][col], row, col, grid);

                noIn = true;
                if (gearsLoc[0] != -1 && gearsLoc[1] != -1) {
                    noIn = false;
                    update = true;
                    // cout<<gearsLoc[0]<<" "<<gearsLoc[1]<<endl; 7
                    if (temp1 == gearsLoc[0] && temp2 == gearsLoc[1]) {
                        check = "ok";
                        update = false;
                        // cout << "jalta";
                    } else {
                        
                        temp1 = gearsLoc[0];
                        temp2 = gearsLoc[1];                        
                    
                        // cout<<temp1<<" "<<temp2<<endl;
                        // 1 3
                        // 4 3
                        // 8 5
                        // 8 5
                        // cout << digit << endl;
                        // 467
                        // 617
                        // 7  
                        // 5
                    }
                }
            } else {               
                if (check != "ok" && gear1 == "") {
                        gear1 = digit;
                        cout << gear1 << endl;
                    
                } else {
                    if(check == "ok"){
                        gear2 = digit;
                        // cout << gear2 << endl;
                    }
                }
                digit = "";

                if (check == "ok") {
                    // cout << gear1 << " " << gear2 << endl;
                    // int ratio = stoi(gear1) * stoi(gear2);
                    // cout << ratio << endl;
                    gearsLoc[0] = -1;
                    gearsLoc[1] = -1;
                    gear1 = "";
                    gear2 = "";
                    temp1 = -1;
                    temp2 = -1;
                    check = "";
                    
                }
                // if (col == grid[0].size()-1) {
                //     digit += grid[row][col];

                //     if (checkNumAdjToSymbol(grid[row][col], row, col, grid)) {
                //         check = "ok";
                //     }  
                // }
                // if (digit != "") {
                    // if (check == "ok") {

                    //     sum += stoi(digit);
                    //     check = "";
                    // }
                    // digit = "";
                // }
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