//
// Created by Christopher Roland on 10/2/16.
//
#include <iostream>
#include <string>
#include <sstream>
#include "string_to_int.h"

using namespace std;

int StringToInt(string s) {

    int mult = 1;
    if (s[0]=='-') {
        mult = -1;
        s.erase(0,1);
    }


    int sum = 0;
    int n_digits=s.size();
    for (int i=(n_digits-1); i>=0 ; --i) {
        sum += CharToInt(s[i])*Pow10Int((n_digits-1)-i);
    }

    return mult*sum;
}


string IntToString(int i) {

    string out = "";
    if (i<0) {
        out += "-";
        i*=-1;
    }

    bool initiated = false;
    int remainder = i;

    for (int b=10; b>=0; --b) {     //set this number based on the size of an int --> 64 bits -->> couple billion?

        int denom = Pow10Int(b);
        int mult = remainder/denom;
        if (mult > 0) { initiated = true; }
        if (initiated) {
            out += DigitToChar(mult);
            remainder -= mult*denom;
        }
    }

    return out;
}

int Pow10Int(int n) {
    int out = 1;
    for (int i=0; i < n; ++i){
        out *= 10;
    }
    return out;
}

int CharToInt(char a) {
    int out = a;
    return out-48;
}

char DigitToChar(int i) {

    ostringstream os;
    os << i;
    char out = os.str()[0];
    return out;
}