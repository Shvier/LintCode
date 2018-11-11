//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by Shvier on 2018/11/11.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

using namespace std;

string longestPalindrome(string &s) {
    // write your code here
    int itr = 0;
    int leftOfItr = 0;
    int rightOfItr = 0;
    int leftOfAns = 0;
    int rightOfAns = 0;
    for (; itr < s.length(); ++ itr) {
        leftOfItr = itr;
        rightOfItr = itr;
        while (leftOfItr >= 0 && rightOfItr < s.length()) {
            if (s[leftOfItr] == s[rightOfItr]) {
                if (rightOfItr - leftOfItr > rightOfAns - leftOfAns) {
                    leftOfAns = leftOfItr;
                    rightOfAns = rightOfItr;
                }
                leftOfItr --;
                rightOfItr ++;
            } else {
                break;
            }
        }
        leftOfItr = itr;
        rightOfItr = itr + 1;
        while (leftOfItr >= 0 && rightOfItr < s.length()) {
            if (s[leftOfItr] == s[rightOfItr]) {
                if (rightOfItr - leftOfItr > rightOfAns - leftOfAns) {
                    leftOfAns = leftOfItr;
                    rightOfAns = rightOfItr;
                }
                leftOfItr --;
                rightOfItr ++;
            } else {
                break;
            }
        }
    }
    return s.substr(leftOfAns, rightOfAns - leftOfAns + 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "aa";
    std::cout << longestPalindrome(s) << endl;
    return 0;
}
