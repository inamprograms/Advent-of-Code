#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

void checkCorruptedMemory(string line);
int main() {

    ifstream inputFile("input.txt");
    string line;

    while (getline(inputFile, line)) {
       
        istringstream iss(line);
    }

    checkCorruptedMemory(line);

    return 0;
}

void checkCorruptedMemory(string line) {
    string instruction = "mul(X,Y)";
    int it = 0;
    string currentNumber = "";
    long long ans = 0;
    int num1, num2;
    for (char ch = 0; ch < line.size(); ch++)
    {
        
        if (line[ch] == instruction[it]) {
            if (instruction[it] == ')') {
                
                it = 0;
            }
            else
                it++;
            continue;
        } else if (instruction[it] == 'X' || instruction[it] == 'Y' && isdigit(line[ch])) {
            while (isdigit(line[ch])) 
            {
                currentNumber = currentNumber + line[ch];   
                ch++;
            }  
            // cout << currentNumber << " ";
            if (line[ch] == ',') {
                num1 = stoi(currentNumber);
            } 
            if (line[ch] == ')') {
                num2 = stoi(currentNumber);
                long long res = num1 * num2;
                ans += res;
                cout << ans << " ";
                num1 = 0;
                num2 = 0;
            }
            currentNumber = "";
            it++;
            ch--;            
        } else {
            // cout << endl;
            it = 0;
            num1 = 1;
            num2 = 0;

        }


    }
    
}
