//
// Created by Christopher Roland on 10/16/16.
//

#ifndef MONGAN_TELEPHONE_WORDS_H
#define MONGAN_TELEPHONE_WORDS_H

#include <string>

using namespace std;

string GetCharacter(int digit, int choice);

void EnumerateWords(const vector<int> & number);

void ExtendWord(const vector<int>& number, string partial);


#endif //MONGAN_TELEPHONE_WORDS_H
