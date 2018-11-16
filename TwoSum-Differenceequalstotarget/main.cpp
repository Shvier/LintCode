//
//  main.cpp
//  TwoSum-Differenceequalstotarget
//
//  Created by Shvier on 2018/11/16.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum7(vector<int> &nums, int target) {
    // write your code here
    int space = (int)nums.size();
    if (space < 1) {
        return {};
    }
    unordered_map<int, int> hashMap;
    unordered_map<int, int>::iterator itr;
    for (int index = 0; index < space; ++ index) {
        int num = nums[index];
        int x = num + target;
        if ((itr = hashMap.find(x)) != hashMap.end()) {
            int left = min(index, itr->second) + 1;
            int right = max(index, itr->second) + 1;
            vector<int> res = {left, right};
            return res;
        }
        x = num - target;
        if ((itr = hashMap.find(x)) != hashMap.end()) {
            int left = min(index, itr->second) + 1;
            int right = max(index, itr->second) + 1;
            vector<int> res = {left, right};
            return res;
        }
        hashMap.insert(make_pair(num, index));
    }
    return {};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
