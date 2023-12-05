#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int calculate(string line)
{

    int start = 0;
    int end = line.length() - 1;
    char first = '!', second = '!';

    while (start <= end)
    {
// 7u
        if (isdigit(line[start]) && first == '!')
        {
            first = line[start];
        }
        if (isdigit(line[end]) && second == '!')
        {
            second = line[end];
        }

        if (first != '!' && second != '!')
        {
            break;
        }

        start++;
        end--;
    }

    if (first == '!' || second == '!') {
        if (first != '!') {
            second = first;
        } else {
            first = second;
        }
    }

    int digit1 = first - '0';
    int digit2 = second - '0';

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