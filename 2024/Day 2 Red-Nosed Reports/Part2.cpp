#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

// https://www.reddit.com/r/adventofcode/comments/1h4ncyr/2024_day_2_solutions/

using namespace std;
bool checkReportIsSafe(vector<int>& report);
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
        if (checkReportIsSafe(report)){
            count++;
            continue;
        }
        for (int i = 0; i < report.size(); i++) {
            vector<int> subReport = report;
            subReport.erase(subReport.begin() + i);
            if (checkReportIsSafe(subReport)) {
                count++;
                break;
            }
        }
    }
    cout <<"Safe: "<< count;
    return 0;
}

bool checkReportIsSafe(vector<int>& report) {
    bool isDecreasing = report[0] > report[1];
    bool isSafe = true;
    for (int level = 1; level < report.size(); level++)
    {
        if (isDecreasing) {
            if (report[level-1] <= report[level] || (report[level-1] - report[level]) > 3) {
                isSafe = false;
                break;
            }
        } else {
            if (report[level-1] >= report[level] || (report[level] - report[level-1]) > 3) {
                isSafe = false;
                break;
            }
        }
    }

    return isSafe;
    
}