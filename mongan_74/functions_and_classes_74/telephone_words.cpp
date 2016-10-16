//
// Created by Christopher Roland on 10/16/16.
//

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "telephone_words.h"

using namespace std;

void EnumerateWords(const vector<int> & number) {

    ExtendWord(number, "");
}

void ExtendWord(const vector<int>& number, string partial) {

    int len = partial.size();


    if (len == number.size()) {
        cout << partial << endl;

    } else {

        if (number[len] <= 1) {
            ExtendWord(number, partial + to_string(number[len]));

        } else {
            for (int choice=0; choice < 3; choice++){
                ExtendWord(number, partial+GetCharacter(number[len], choice) );
            }
        }
    }




}


string GetCharacter(int digit, int choice) {

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