//
//  main.cpp
//  ValidPalindrome
//
//  Created by Shvier on 2018/11/10.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

using namespace std;

bool isValidCharacter(char c) {
    return (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9');
}

char toLowerCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c;
    }
    return c + 32;
}

bool isEqual(char c1, char c2) {
    return toLowerCase(c1) == toLowerCase(c2);
}

bool isPalindrome(string &s) {
    // write your code here
    if (s.length() < 1) {
        return true;
    }
    int start = 0;
    int end = (int)s.length() - 1;
    while (start < end) {
        if (isValidCharacter(s[start])) {
            if (isValidCharacter(s[end])) {
                if (isEqual(s[start], s[end])) {
                    start ++;
                    end --;
                    continue;
                } else {
                    break;
                }
            } else {
                end --;
                continue;
            }
        } else {
            start ++;
            continue;
        }
    }
    
    if ((abs(start - end) == 1 && isEqual(s[start], s[end])) ||
        start == end) {
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "aa";
    std::cout << isPalindrome(s) << endl;
    return 0;
}
