#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

bool helper(string line) {

    string remaining;

    unordered_map<string, int> bag;
    bag["red"] = 12;
    bag["green"] = 13;
    bag["blue"] = 14;

    size_t colonPos = line.find(':');

    if (colonPos != string::npos) {
        remaining = line.substr(colonPos + 1);
    }

    istringstream ss(remaining);
    vector<string> subsets;
    string subset;
    while (getline(ss, subset, ';')) {
        subsets.push_back(subset);
    }

    for (const auto& set : subsets) {

        istringstream ss(set);
        vector<string> cubes;
        string cube;
        while (getline(ss, cube, ',')) {

            istringstream ss(cube);
            string color, num;
            ss >> num >> color;
      
            if (stoi(num) > bag[color]) {
                return false;
            }
        }
    }

    return true;

}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 2 Cube Conundrum/input.txt");
    int sum = 0, game_no = 1;
    string line;

    while (getline(inputFile, line)) {

        bool check = helper(line);

        if (check) {
            sum  += game_no;
        }
        game_no++;
    }
    
    cout << sum;
    return 0;
}