#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int main() {

    ifstream inputFile("C:/Users/Dell/Desktop/New folder/input.txt");
    string line;

    vector<int> leftList;
    vector<int> rightList;
    int difference, distances = 0, similarity_score = 0;

    while (getline(inputFile, line)) {
       
        istringstream iss(line);
        int id1, id2;
        iss >> id1 >> id2;
        leftList.push_back(id1);
        rightList.push_back(id2);
       
    }

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    // Part 1
    for (int loc_id = 0; loc_id < leftList.size(); loc_id++)
    {
       
        difference = abs(leftList[loc_id] - rightList[loc_id]);
        distances += difference;
       
        // Part 2
        int count = 0;
        for (int it = 0; it < rightList.size(); it++) {
            if (leftList[loc_id] == rightList[it]) {
                count++;
            }
        }
        similarity_score += leftList[loc_id] * count;

    }
 
    cout << "Total distance: " << distances;
    cout << endl;
    cout << "Similarity score: " << similarity_score;

    return 0;
}

