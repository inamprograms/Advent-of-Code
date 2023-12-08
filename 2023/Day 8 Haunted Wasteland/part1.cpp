#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>
#include <algorithm>
#include<array>

using namespace std;

// unordered_map<string , array<string, 2>> maps;
unordered_map<string , vector<string>> maps;
// unordered_map<string , pair<string, string>> maps;


void parse(string line) {
    
    istringstream ss(line);
    string position, directions;
    getline(ss, position, '=');
    getline(ss, directions, '=');

    auto lastNonSpace = find_if(position.rbegin(), position.rend(), [](char ch) {
        return !std::isspace(ch);
    });
    position.erase(lastNonSpace.base(), position.end());

    directions.erase(remove(directions.begin(), directions.end(), '('), directions.end());
    directions.erase(remove(directions.begin(), directions.end(), ')'), directions.end());
    directions.erase(remove(directions.begin(), directions.end(), ' '), directions.end());
    directions.erase(remove(directions.begin(), directions.end(), ' '), directions.end());

    string leftMove, rightMove;
    istringstream ss1(directions);
    getline(ss1, leftMove, ',');
    getline(ss1, rightMove, ',');
    
    // maps[position] = {leftMove, rightMove};
    maps[position].push_back(leftMove);
    maps[position].push_back(rightMove);
    // maps[position] = make_pair(leftMove, rightMove);
    
    // cout  << position << " " << leftMove << " "<< rightMove << endl;
}

string curLoc, newLoc = "";
int followMap(string instructions, int count, string curLoc) {
    // array<string, 2> move;
    vector<string> move;
   
    // curLoc = "AAA ";
    // cout << count<< endl;
    for (int i = 0; i < instructions.size(); i++)  {

        move = maps[curLoc];
        
        if (instructions[i] == 'L') {
            newLoc = move[0];
        } else {
            newLoc = move[1];
        }

        curLoc = newLoc;
        count++;

        if (curLoc == "ZZZ") {
            return count;
        }      
    }

    if (curLoc != "ZZZ") {
        // cout << curLoc;
        count = followMap(instructions, count, curLoc);
    } 
    return count;
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 8 Haunted Wasteland/input.txt");
    string line;
    string instructions;
    getline(inputFile, instructions);
    // cout << instructions << endl;
    while (getline(inputFile, line)) {
        if (line != "\0")
        {
            parse(line);
        } 
    }

    cout << followMap(instructions, 0, "AAA");
    // for (const auto& entry : maps) {
    //     std::cout << "Key:" << entry.first << ",Value1:" << entry.second[0]
    //               << ",Value2:" << entry.second[1] << std::endl;
    // }
    return 0;
}