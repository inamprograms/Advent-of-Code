#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int helper(string line) {
    int power = 0;
    int redCubes = INT_MIN, greenCubes = INT_MIN, blueCubes = INT_MIN;
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
            int n = stoi(num);

            // Part 2
            if (color == "red") {
                redCubes = max(redCubes, n);
            } else if (color == "green") {
                greenCubes = max(greenCubes, n);
            } else {
                blueCubes = max(blueCubes, n);
            }
        }
        power = redCubes * greenCubes * blueCubes;
    }
    return power;

}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 2 Cube Conundrum/input.txt");
    int sum = 0;
    string line;

    while (getline(inputFile, line)) {

        int ans = helper(line);
        sum  += ans;
    }
    
    cout << sum;
    return 0;
}