//
//  main.cpp
//  KMP
//
//  Created by Shvier on 2018/11/10.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

using namespace std;

void generatePMT(int pmt[], string target) {
    int start = 0;
    int end = start + 1;
    while (end < target.length()) {
        if (target[start] == target[end]) {
            pmt[end] = pmt[end - 1] + 1;
            start ++;
            end ++;
        } else {
            if (start != 0) {
                start = 0;
            } else {
                pmt[end] = 0;
                end ++;
            }
        }
    }
}

int strStr(string &source, string &target) {
    // Write your code here
    if (target.length() < 1) {
        return 0;
    }
    
    if (source.length() < 1) {
        return -1;
    }
    
    int pmt[target.length()];
    generatePMT(pmt, target);
    int sourceItr = 0;
    int targetItr = 0;
    while (sourceItr < source.length() && targetItr < target.length()) {
        if (source[sourceItr] == target[targetItr]) {
            sourceItr ++;
            targetItr ++;
        } else {
            if (targetItr != 0) {
                targetItr = pmt[targetItr - 1];
            } else {
                sourceItr ++;
            }
        }
    }
    
    if (targetItr == target.length()) {
        return sourceItr - targetItr;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string target = "ABCDABD";
    int pmt[target.length()];
    generatePMT(pmt, target);
    for (int e : pmt) {
        cout << e << endl;
    }
    
    return 0;
}
