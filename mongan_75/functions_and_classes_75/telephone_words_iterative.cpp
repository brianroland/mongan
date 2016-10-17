//
// Created by Christopher Roland on 10/16/16.
//

#include <sstream>
#include <vector>
#include <stack>
#include <iostream>
#include "telephone_words_iterative.h"

using namespace std;

void EnumerateWordsIterative(const vector<int> & number) {

    //create stack and initialize
    stack<string> my_stack;
    my_stack.push(string(""));

    while(!my_stack.empty()) {

        string partial = my_stack.top();
        my_stack.pop();

        int len = partial.size();

        if (len == number.size()) {
            cout << partial << endl;

        } else {

            if (number[len] <= 1) {
                my_stack.push(partial+string(1,number[len]) );

            } else {
                for (int choice=2; choice >= 0; --choice){
                    string next_char = GetCharacterIterative(number[len], choice);
                    my_stack.push(partial + next_char);
                }
            }
        }
    }
}


string GetCharacterIterative(int digit, int choice) {

    vector<char> alphabet;
    for (auto i=0; i<26; i++) { alphabet.push_back(65+i);}


    if (2 <= digit and digit <=6) {
        int i_alpha = 3 * (digit - 2) + choice;
        return string(1, alphabet[i_alpha]);

    } else if (7 <= digit and digit <=9) {
        int i_alpha = 3 * (digit - 2) + choice +1;
        string out = string(1,alphabet[i_alpha]);

        if (out=="Q") {
            return "P";
        } else {
            return out;
        }

    } else {
        return to_string(digit);
    }
}



