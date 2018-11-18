//
//  main.cpp
//  MaximumNumberinMountainSequence
//
//  Created by Shvier on 2018/11/18.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int mountainSequence(vector<int> &nums) {
    // write your code here
    int size = (int)nums.size();
    if (size < 1) {
        return -1;
    }
    int left = 0;
    int right = size - 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return max(nums[left], nums[right]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
