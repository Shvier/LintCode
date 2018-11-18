//
//  main.cpp
//  FindKClosestElements
//
//  Created by Shvier on 2018/11/18.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isLeftCloser(vector<int> &A, int target, int start, int end) {
    if (start < 0) {
        return false;
    }
    if (end >= (int)A.size()) {
        return true;
    }
    int offsetForStart = abs(target - A[start]);
    int offsetForEnd = abs(target - A[end]);
    if (offsetForStart != offsetForEnd) {
        return offsetForStart < offsetForEnd;
    }
    return true;
}

vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
    // write your code here
    int size = (int)A.size();
    if (size < 1) {
        return {};
    }
    
    int left = 0;
    int right = size - 1;
    int start = 0;
    int end = 0;
    
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (A[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    if (A[right] < target) {
        start = right;
    } else if (A[left] < target) {
        start = left;
    }
    end = start + 1;
    
    vector<int> res;
    for (int index = 0; index < k; ++ index) {
        if (isLeftCloser(A, target, start, end)) {
            res.push_back(A[start]);
            start --;
        } else {
            res.push_back(A[end]);
            end ++;
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {1, 4, 6, 8};
    kClosestNumbers(A, 3, 3);
    return 0;
}
