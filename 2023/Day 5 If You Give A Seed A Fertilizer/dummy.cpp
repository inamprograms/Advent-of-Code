#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;


int main() {
// light-to-temperature map:


// 68 64 13
    int start = 0;
    vector<int> g = {74, 42, 46, 34}; // w-l
    int source = 64;
    int destination = 68;
    int range = 13;
unordered_map<int , int> map;
    for (int i = 1; i <= range; i++) {
        map[source] = destination;
        source += 1;
        destination += 1;
    }


  for (int i = 0; i < g.size(); i++) {
    if (map.find(g[i]) != map.end()) {
        // cout << g[i]<<endl;
        int val = map[g[i]];
        g[i] = val;
        // cout << g[i] << " <><><><><> " << val << endl;
        // start++;
    }
  }





for (auto t :map) {
    cout << t.first << " --------> " << t.second << endl;

}



  for (auto p: g) {
    cout << p << " ";
  }

//    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 5 If You Give A Seed A Fertilizer/input.txt");
//     int sum = 0;
//     string line;

//     while (getline(inputFile, line)) {
//         if (line != "\0")
//         {
//             /* code */
//           cout << line << endl;
//         }
        
//     }
    
    return 0;
}



