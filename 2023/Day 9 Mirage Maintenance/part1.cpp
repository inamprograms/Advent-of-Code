#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;
vector<int> solve(string line) {

    vector<int> history;
    vector<int> difference;
    stack<vector<int>> differences;

    string val;
    bool flag = true;
    istringstream ss(line);
    while (ss >> val) {
        history.push_back(stoi(val));
    }
    differences.push(history);

    while (1)
    {   
        for (int i = 0; i < history.size()-1; i++)
        {
           
            difference.push_back(history[i+1] - history[i]);
             
        }
        int count = 0;
        for (int i = 0; i < difference.size(); i++)
        {
            if (difference[i] == 0) {
                count++;
            }
        }
        if (count == difference.size()) {
            break;
        }

        
        differences.push(difference);
        history = {};
        difference = {};

        history = differences.top();
     
    }

int right = 0, left = 0;
while (!differences.empty()) {
    
        vector<int> topVector = differences.top();

        // Part 1
        right += topVector[topVector.size()-1];
        // Part 2
        left = topVector[0] - left;
       
        differences.pop();
    }

return {right, left};
    
    

    
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 9 Mirage Maintenance/input.txt");
   
    string line;
    int res = 0;
    vector<int> ans;
    int part1 = 0, part2 = 0;
    while (getline(inputFile, line)) {
      
        ans = solve(line);
        part1 += ans[0];
        part2 += ans[1];

    }
    
    
  cout << part1 << endl;
  cout << part2 << endl;

    return 0;
} 






