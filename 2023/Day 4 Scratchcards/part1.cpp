#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int helper(string line) {
    int res = 0;
    string remaining;

    unordered_map<string, string> winningNumbers;
    vector<string> numbersHave;
   

    size_t colonPos = line.find(':');

    if (colonPos != string::npos) {
        remaining = line.substr(colonPos + 1);
    }

    istringstream ss(remaining);
    string won, have;
    
    getline(ss, won, '|');
    getline(ss, have, '|');

    istringstream ss1(won);
    string n;
    while (ss1 >> n) {
        winningNumbers[n] = n;
    }
    n = "";
    istringstream ss2(have);
    while (ss2 >> n) {
        numbersHave.push_back(n);
    }

    // Part 1
    for (int i = 0; i < numbersHave.size(); i++) {
        if(winningNumbers.find(numbersHave[i]) != winningNumbers.end()) {

            if (res == 0) {
                res = 1;
            } else {
                res = 2 * res;
            }
        }
    }
   
    return res;
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 4 Scratchcards/input.txt");
    int sum = 0;
    string line;

    while (getline(inputFile, line)) {
        sum += helper(line);   
    }
    
    cout << sum;
    return 0;
}