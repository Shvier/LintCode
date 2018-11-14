//
//  main.cpp
//  LongestPalindromicSubsequence
//
//  Created by Shvier on 2018/11/14.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

using namespace std;

int longestPalindromeSubseq(string &s) {
    // write your code here
    int length = (int)s.length();
    if (length < 1) {
        return 0;
    }
    int dp[length][length];
    for (int i = length - 1; i >= 0; -- i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < length; ++ j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][length-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "bbbab";
    std::cout << longestPalindromeSubseq(s) << endl;
    return 0;
}
