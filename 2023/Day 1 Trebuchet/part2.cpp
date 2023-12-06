#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <unordered_map>
using namespace std;

int calculate(string line)
{
    vector<char> remaining;

    int lineLength = line.length();
    long long start = 0, end = 0, first = -1;
    long long secondStart = lineLength - 1, secondEnd = lineLength - 1, second = -1;
    string window1 = "", window2 = "";
    unordered_map<string, int> digits;

    digits["one"] = 1;
    digits["two"] = 2;
    digits["three"] = 3;
    digits["four"] = 4;
    digits["five"] = 5;
    digits["six"] = 6;
    digits["seven"] = 7;
    digits["eight"] = 8;
    digits["nine"] = 9;

    while (end < line.length())  {

        if (isdigit(line[start])) {
            first = line[start] - '0';
            break;
        }
       
        window1 = line.substr(start, end - start + 1);
 
        if (digits.find(window1) != digits.end()) {

            first = digits[window1];
            break;

        } else {

            end = end + 1;
            if ((end - start + 1) > 5) {
                start = start + 1;
                end = end - 2;  
            }
        }
    }
  
    if (first == -1) {
        for (int i = start; i < end ; i++)
        {

            if (isdigit(line[i]))
            {
                remaining.push_back(line[i]);
            }
        }        
        first = remaining[0] - '0';
        remaining = {};
    }

    while (secondStart >= 0)  {

        if (isdigit(line[secondEnd])) {
            second = line[secondEnd] - '0';
            break;
        }
        window2 = line.substr(secondStart, secondEnd - secondStart + 1);

 
        if (digits.find(window2) != digits.end()) {

            second = digits[window2];
            break;

        } else {

            secondStart = secondStart - 1;
            if ((secondEnd - secondStart + 1) > 5) {
                secondEnd = secondEnd - 1;
                secondStart = secondStart + 2;  
            }
        }
    }

    if (second == -1) {
        for (int i = secondEnd; i >= 0; i--)
        {
            if (isdigit(line[i]))
            {
                remaining.push_back(line[i]);
            }
        }        
        second = remaining[0] - '0';
        remaining = {};
    }

    int twoDigitNumber = first * 10 + second;
    return twoDigitNumber;
}

int main()
{
    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 1 Trebuchet/input.txt");
    long long sum = 0;
    string line;

    while (getline(inputFile, line)) {
        sum += calculate(line);
    }
    
    cout << sum;
    return 0;
}