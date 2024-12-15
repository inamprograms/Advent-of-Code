#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

int countDigits(long long number) {
    long long temp = number;
    int digitCount = 0;
    while (temp > 0) {
        temp /= 10;
        digitCount++;
    }

    return digitCount;
}

vector<long long> splitDitgits(long long num) {

    vector<long long> stones = {0,0};
    // Find the number of digits in the number
    // int digitCount = countDigits(num);
    int digitCount = log10(num) + 1;

    // Split the number into two parts
    int halfDigits = digitCount / 2; // Find the middle point
    long long divisor = pow(10, halfDigits); // Calculate divisor for splitting

    long long leftPart = num / divisor; // Extract left part
    long long rightPart = num % divisor; // Extract right part

    stones[0] = leftPart;
    stones[1] = rightPart;

    return stones;
}

int main() {

    list<long long> stoneNumbers;

    ifstream inputFile("../input.txt");
    string line;
    getline(inputFile, line);


    istringstream iss(line);
    long long num;
    while(iss>>num) {
        stoneNumbers.push_back(num);
    }
    
    for (int i = 0; i < 75; i++)
    {
        for (auto it = stoneNumbers.begin(); it != stoneNumbers.end(); it++) {
           
            int digitCount = log10(*it) + 1;
            if (*it == 0) {
                *it = 1;
            } else if(digitCount % 2 == 0) {

                vector<long long> two_stones = splitDitgits(*it);
                *it = two_stones[0];
                stoneNumbers.insert(next(it), two_stones[1]);
                it++;
            } else {
                *it *= 2024;
            }
        }
    }
    return 0;
}