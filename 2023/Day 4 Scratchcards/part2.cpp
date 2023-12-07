#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<vector>

#define MAXROWS 300
using namespace std;

struct Card
{
    int cardNum;
	int matches;
	long count;
};

int total = 0;

Card* cards = new Card[MAXROWS];
int helper(string line, int cardNo) {

    int matches = 0;
    string remaining;

    unordered_map<string, string> winningNumbers;
    vector<string> numbersHave;
   

    size_t colonPos = line.find(':');

    if (colonPos != string::npos) {
        remaining = line.substr(colonPos + 1);
    }

    istringstream ss(remaining);
    string won, have;
    
    getline(ss, won, '|');
    getline(ss, have, '|');

    istringstream ss1(won);
    string n;
    while (ss1 >> n) {
        winningNumbers[n] = n;
    }
    n = "";
    istringstream ss2(have);
    while (ss2 >> n) {
        numbersHave.push_back(n);
    }

    
    for (int i = 0; i < numbersHave.size(); i++) {
        if(winningNumbers.find(numbersHave[i]) != winningNumbers.end()) {
            matches++;
        }
    }

    cards[cardNo].cardNum = cardNo;
	cards[cardNo].matches = matches;
	cards[cardNo].count = 1;
    return 0;
}

int calc(Card* cards, int idx) {
    
    if (cards[idx].cardNum != '\0') {
        total++;
        
        if(cards[idx].matches == 0) {
            return 1;
        }

        cards[idx].count++;

        if (cards[idx].matches > 0) {
            for (int j = 0; j < cards[idx].matches; j++) {
                calc(cards, idx + 1 + j);
            }
        }
    }

    return total;
}
int main() {

    ifstream inputFile("D:/Git Hub Repos/Advent of Code/2023/Day 4 Scratchcards/input.txt");
    int sum = 0;
    int cardCount = 0;
    string line;

    while (getline(inputFile, line)) {
        cardCount++;
        helper(line, cardCount); 
    }
    
    for (int i = 1; i <= cardCount; i++) {
        calc(cards, i);
    } 
    cout << total;
    delete[] cards;
    return 0;
}