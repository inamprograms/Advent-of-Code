#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>
#include <algorithm>

using namespace std;

unordered_map<int, vector<vector<string>>> map;
unordered_map<long long, long long> source_to_destination;
vector<long long> output, visited;
int n, key;


int checkNewMap (string line) {
      
    if (line[0] == 's' && line[1] == 'e' && line[2] == 'e' && line[3] == 'd' && line[4] == 's') {
        return 0;
    } else if (line == "seed-to-soil map:") {
        return 1;
    } else if (line == "soil-to-fertilizer map:") {
        return 2;
    } else if (line == "fertilizer-to-water map:") {
        return 3;
    } else if (line == "water-to-light map:") {
        return 4;
    } else if (line == "light-to-temperature map:") {
        return 5;
    } else if (line == "temperature-to-humidity map:") {
        return 6;
    } else if (line == "humidity-to-location map:") {
        return 7;
    } else {
        return -1;
    }

}
void parse(string line) {

    vector<string> data;
    string remaining;

    n = checkNewMap(line);
    
    if (n != -1) {
        key = n;
    }

    if (n != -1) {
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            line = line.substr(colonPos+1);
        }
    } 
    // Getting input line by line to parse
    // Storing each gvien map into a hashmap with key 0 - 7 
    //     key represents map like seed-soil and value as two D vector of all passible ranges of map
    // looping through 0-7 to get data from map to process:  getLowestLocationNumber(int i)
            // getData(i) to get data from map for i(key)
            // store data in tow D vector
            // if i is 0 then it means seeds otherwise any map 
            // createMap(vector<string>& vec, bool check) -> check is 0 or 1
            // This maps the each input 1-7 maps to given source to destination one by one 
            // Lookup into source_to_destination map for every output 
            //     if found in map then update the output ohert wise keep same
            



    istringstream ss(line);
    string value;
    while (ss >> value) {
        data.push_back(value);
    }

    auto it = map.find(key);
    if (it == map.end()) {
        map[key] = {data};
    } else {
        it->second.push_back(data);
    }
    // map[key].push_back(data);
}
vector<vector<string>> getData(int key) { 
    vector<vector<string>> ranges;
    auto it = map.find(key);
    if (it != map.end()) {
        ranges = it->second;
    }
    return ranges;
}
void createMap(vector<string>& vec, bool check) {
   long long destination, source, range;

     if (check != 0) {

        long long arr[3];
        for (size_t i = 0; i < vec.size(); ++i) {
            arr[i] = stoll(vec[i]);
        }
        destination = arr[0];
        source = arr[1];
        range = arr[2];
        

        for (long long i = 1; i <= range; i++) {
            source_to_destination[source] = destination;
            source += 1;
            destination += 1;
        }
        
    } else {
        for (auto v: vec) {
            // outputMap[stoll(v)] = stoll(v);
            output.push_back(stoll(v));
        } 
    }
}
void lookUpInMap() {

    for (int s = 0; s < output.size(); s++) {

        bool found = binary_search(visited.begin(), visited.end(), s);
        if (!found) {
            if (source_to_destination.find(output[s]) != source_to_destination.end()) {
               
                long long value = source_to_destination[output[s]];
                output[s] = value;
                visited.push_back(s);
            }
            //  529476798 890019635 624017612
            //  1236480411 837883389  571881366 
        }
        
        // cout << source.first << " --------> " << source.second << endl;
    }
}
void getLowestLocationNumber(int i) {
    vector<vector<string>> given;
    if (i == 0) {
        given = getData(i);
        createMap(given[0], 0); 

    } else {
      
        given = getData(i);
        
        for (auto v: given) {
            createMap(v, 1);
            lookUpInMap();
            source_to_destination.clear();
        }
    }

   
    
    // return 0;
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 5 If You Give A Seed A Fertilizer/input.txt");
   
    string line;
    string seeds;

    while (getline(inputFile, line)) {
        if (line != "\0")
        {
            parse(line);
            
        } 
    }
    for (int i = 0; i <= 7; i++) {
        visited = {};
        getLowestLocationNumber(i);
    }
    
    auto lowest_loc_num = min_element(output.begin(), output.end());
    cout << *lowest_loc_num <<  endl;

    //   for (const auto& entry : map) {
    //     std::cout << "Key: " << entry.first << std::endl;
        

    //     for (const auto& vec : entry.second) {
    //         for (const auto& str : vec) {
    //             std::cout << str << ' ';
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    // for (auto p: output) {
    // cout << p<< " ";
    //     }

    return 0;
}


