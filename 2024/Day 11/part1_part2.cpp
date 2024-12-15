#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// Function to split and mutate the stone
vector<long long> mutate(long long stone) {
    vector<long long> result;

    if (stone == 0) {
        result.push_back(1); // Return {1} for stone == 0
    } else {
        string digits = to_string(stone);
        int len = digits.length();
        int half = len / 2;

        if (len % 2 == 0) {
            // Even-length number, split into two parts
            long long left = stoll(digits.substr(0, half));
            long long right = stoll(digits.substr(half));
            result.push_back(left);
            result.push_back(right);
        } else {
            // Odd-length number, multiply by 2024
            result.push_back(stone * 2024);
        }
    }

    return result;
}

// Main function to process the stones
long long part1(const string& puzzle_input) {
    unordered_map<long long, long long> stones; // Map for Counter

    // Initialize the stones with input counts
    size_t pos = 0;
    string token;
    string input = puzzle_input;

    while ((pos = input.find(' ')) != string::npos) {
        token = input.substr(0, pos);
        long long num = stoll(token);
        stones[num]++;
        input.erase(0, pos + 1);
    }
    stones[stoll(input)]++; // Add the last number

    // Perform 75 iterations
    for (int i = 0; i < 75; i++) {
        unordered_map<long long, long long> new_stones;

        for (const auto& pair : stones) {
            long long stone = pair.first;
            long long count = pair.second;

            vector<long long> children = mutate(stone);

            for (long long child : children) {
                new_stones[child] += count;
            }
        }

        stones = new_stones; // Update stones
    }

    // Calculate the sum of all counts
    long long total_count = 0;
    for (const auto& pair : stones) {
        total_count += pair.second;
    }

    return total_count;
}

int main() {
    string puzzle_input = "";
    cout << part1(puzzle_input) << endl;
    return 0;
}
