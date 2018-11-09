//
//  main.cpp
//  LintCode
//
//  Created by Shvier on 2018/11/9.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string &s) {
    // write your code here
    map<char, int> hashTable;
    for (char c : s) {
        ++ hashTable[c];
    }
    
    int result = 0;
    bool hasSingle = false;
    map<char, int>::iterator iter;
    iter = hashTable.begin();
    while (iter != hashTable.end()) {
        if (iter->second % 2 == 0) {
            result += iter->second;
        } else {
            result += iter->second - 1;
            hasSingle = true;
        }
        ++ iter;
    }
    return hasSingle ? result + 1 : result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str = "abcbe";
    std::cout << longestPalindrome(str);
    return 0;
}
