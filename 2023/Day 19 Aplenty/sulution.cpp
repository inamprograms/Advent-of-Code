#include<iostream>
#include<fstream>
#include<sstream>
#include<map> 
#include<vector> 

using namespace std;


map<string, vector<pair<string, string>>> workFlows;
vector<pair<string, string>> values;
map<string, int> ratings;
void addValues(string flow, string step) {
    
    string first = "", second = "";
    istringstream ss(step);
    getline(ss, first, ':');
    getline(ss, second, ':');
    // first = first;
    // second = second;
    if (second == "") {
        second = first;
        first = "";
    }
    values.push_back(make_pair(first, second));

    
    // cout << " 1. " <<first << " 2. "<< second;
    workFlows[flow] = values;
    // values = {};
}
void parseWorkflows(string line) {

    istringstream ss(line);
    string flow, steps;
    getline(ss, flow, '{');
    getline(ss, steps, '{');
    steps.pop_back();
    // cout << flow << "    :";

    istringstream ss1(steps);
    while (ss1)
    {
        string step;
        getline(ss1, step, ',');
        // cout << step;
        if (step != "\0") {
            addValues(flow, step);
        }
        // a<2006:qkq m>2090:A rfg 

    }

    values = {};
    // cout<< endl;
}
void parseRating(string line) {
    line = line.substr(1, line.size()-2);

    istringstream ss(line);
    string rate;
    while (getline(ss, rate, ',')) {
    
        istringstream ss1(rate);
        string ch, v;
        getline(ss1, ch, '=');
        getline(ss1, v, '=');

        ratings[ch] = stoi(v);

    }    
}
string res;
string solve(vector<pair<string, string>> flow) {
    // in{s<1351:px,qqz}

    // vector<pair<string, string>> data;
    // data = workFlows["in"];

    string move, ch, rel, val;
    for (auto r: flow) {
        // s<1351 px: qqz:
      
        if (r.first != "") {
            
            // cout << r.first << " " << r.second << ":";
            size_t pos = r.first.find_first_of("<>");
            if (pos != string::npos) {
       
                ch = r.first.substr(0, pos);
                rel = r.first.substr(pos, 1);
                if (pos + 1 < r.first.length()) {
                    val = r.first.substr(pos + 1);
                } 
            }

            // cout << rel;
            if (rel == "<") {

                if (ch == "s") {
                    int s;
                    s = ratings[ch];
                    if (s < stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                    
                } else if (ch == "m") {
                    int m;
                    m = ratings[ch];
                    if (m < stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                } else if (ch == "a") {
                    int a;
                    a = ratings[ch];
                    if (a < stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }

                } else if (ch == "x") {
                    int x;
                    x = ratings[ch];
                    if (x < stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                }
            } else {

                if (ch == "s") {
                    int s;
                    s = ratings[ch];
                    if (s > stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                    
                } else if (ch == "m") {
                    int m;
                    m = ratings[ch];
                    if (m > stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                } else if (ch == "a") {
                    int a;
                    a = ratings[ch];
                    if (a > stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }

                } else if (ch == "x") {
                    int x;
                    x = ratings[ch];
                    if (x > stoi(val)) {
                        move = r.second;
                        // cout << move;
                        if (move == "A" || move == "R") {
                            return move;
                        }
                        res = solve(workFlows[move]);
                        break;
                    } else {
                        continue;
                    }
                }

            }

            
        } else {
            move = r.second;
            // cout << move;
            if (move == "A" || move == "R") {
                return move;
            }
            res = solve(workFlows[move]);
        }

    }
    
    // cout << endl;
    return res;
    // ratings.clear();
}
int main() {

    ifstream inputFile("input.txt");
    string line;
    while (getline(inputFile, line)) {
        if (line == "\0") {
            break;
        }
        parseWorkflows(line);
    }

    string rating;
    int finalAns = 0;
    while (getline(inputFile, rating)) {
        string ans;
        parseRating(rating);
        res = "";
        ans = solve(workFlows["in"]);

        if (ans == "A") {
            finalAns += ratings["m"];
            finalAns += ratings["x"];
            finalAns += ratings["a"];
            finalAns += ratings["s"];
        }

    }
    cout << finalAns;
//  for (auto ans: values) {
//         cout << ans.first << " " << ans.second << endl;
//     }
//    for (const auto& workflow : workFlows) {
//         std::cout << "-------" << workflow.first << "-------" << endl;
        
//         for (const auto& ans : workflow.second) {
//             cout << ans.first << " " << ans.second << endl;
//         }
// //         cout << endl;
//     }
    // px
    //     a<2006:qkq,
    //     m>2090:A,
    //     rfg
    // pv
    //     a>1716:R,
    //     A
    // in
    //     s<1351:px,
    //     qqz

    // {
    //  x=787
    //  m=2655
    //  a=1222
    //  s=2876
    // }
    // parse
    // store into map or structure

    //start look into the in.
        //  s<1351:px,
            // if (s<1351 == true)
            //     move to second pair
            // else 
            //     move to next pair 
        
  
    return 0;
}