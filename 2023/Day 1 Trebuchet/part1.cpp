#include <iostream>
#include <fstream>
#include<vector>
#include <string>
using namespace std;

int calculate(string line)
{
    vector<char> digits;  
    for (int i = 0; i < line.length(); i++)
    {
        if (isdigit(line[i]))
        {
            digits.push_back(line[i]);
        }
    }
    int digit1 = digits[0] - '0';
    int digit2 = digits[digits.size()-1] - '0';

    int twoDigitNumber = digit1 * 10 + digit2;
   
    return twoDigitNumber;
}

int main()
{
    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 1 Trebuchet/input.txt");
    int sum = 0;
    string line;

    while (getline(inputFile, line)) {
        sum += calculate(line);
    }
 
    cout << sum;
    return 0;
}