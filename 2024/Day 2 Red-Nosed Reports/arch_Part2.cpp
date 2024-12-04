#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;
bool check_report(vector<int>& report, int index);
int level_to_remove(vector<int>& report);
int main() {

    ifstream inputFile("input.txt");
    string line;
    vector<vector<int>> reports;

    while (getline(inputFile, line)) {

        int levels;
        vector<int> report;
        
        istringstream iss(line);
        while (iss >> levels)
        {
            report.push_back(levels);
        }
        reports.push_back(report);
    }

    int count = 0;
    for (vector<int> report : reports) {


        int index = level_to_remove(report);
        // cout << index << " ";

        if (index != 0) {
            if (check_report(report, index)) {
                count++;
            }

        } else 
            count++;
    }
    cout <<"safe: "<< count;

    return 0;
}


int level_to_remove(vector<int>& report) {
    int level = 0;
    if (report[0] < report[1]) {
        while (level < report.size()-1) {
             
            int diff = report[level+ 1] - report[level];
            if (report[level] < report[level+ 1] && diff >= 1 && diff <= 3) 
                level++;
            else{
                int diff = report[level] - report[level - 1];
                if (report[level] > report[level - 1] && diff >= 1 && diff <= 3) {
                    level++;
                    continue;
                }
                return level;     
            } 
        }

    } else {

        while (level < report.size()-1) {

            int diff = report[level] - report[level+ 1];
            if (report[level] > report[level+1] && diff >= 1 && diff <= 3) 
                level++;
            else 
                return level;
        }
    }
    return level;    
}


bool check_report(vector<int>& report, int levelToRemove) {

    bool isSafe = false;
    bool remove = false;
    
    int left = levelToRemove - 1;
    int right = levelToRemove + 1;
    
    // Check if ascending order
    if (report[0] < report[1]) {
        while (right < report.size()) {
            // Check for:
            // 1. Levels are either all increasing or all decreasing
            // 2. Any two adjacent levels differ by at least one and at most three.
            
            if (left == levelToRemove) {
                left++;
            }
                
            int diff = report[right] - report[left];
    
            if (report[left] < report[right] && diff >= 1 && diff <= 3) {
                right++;
                left++;
            }
            else {
                break;
            }
                
        }
        
        if (right == report.size()) {
            // report is safe
            isSafe = true;
            // cout << "ascending ";
        }

    } else {
// if (report[i-1] >= report[i] || (report[i] - report[i-1]) > 3) {
//                 safe = false;
//                 break;
//             }
        while (right < report.size()) {
// 9 7 6 2 1
            if (left == levelToRemove) {
                left++;
            }

            int diff = report[left] - report[right];
            if (report[left] > report[right] && diff >= 1 && diff <= 3) {
                right++;
                left++;
            }
            else {
               break;
            }
        }
        
        if (right == report.size()) {
            // report is safe
            isSafe = true;
            // cout << " decending ";
        }

    }
    return isSafe;
    // cout << isSafe;
    
}