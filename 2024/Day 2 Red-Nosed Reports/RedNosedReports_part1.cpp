#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;
bool check_report(vector<int>& report);
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

        if (check_report(report)) {
            count++;
        }
    }
    cout <<"safe: "<< count;

    return 0;
}


bool check_report(vector<int>& report) {

    bool isSafe = false;
    bool remove = false;
    // Check if ascending order
    if (report[0] < report[1]) {
        int level = 0;
        while (level < report.size()-1) {
            // Check for:
            // 1. Levels are either all increasing or all decreasing
            // 2. Any two adjacent levels differ by at least one and at most three.
            
            int diff = report[level+1] - report[level];
            if (report[level] < report[level+1] && diff >= 1 && diff <= 3)
                level++;
            else
                break;
        }
        
        if (level == report.size()-1) {
            // report is safe
            isSafe = true;
            // cout << "ascending ";
        }

    } else {

        int level = 0;
        while (level < report.size()-1 && report[level] > report[level+1]) {

            int diff = report[level] - report[level+1];
            if (diff >= 1 && diff <= 3)
                level++;
            else
                break;
        }
        
        if (level == report.size()-1) {
            // report is safe
            isSafe = true;
            // cout << " decending ";
        }

    }
    return isSafe;
    // cout << isSafe;
    
}