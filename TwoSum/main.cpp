//
//  main.cpp
//  TwoSum
//
//  Created by Shvier on 2018/11/15.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    // write your code here
    unordered_map<int, int> hashMap;
    unordered_map<int, int>::iterator itr;
    for (int index = 0; index < numbers.size(); ++ index) {
        int num = numbers[index];
        int x = target - num;
        if ((itr = hashMap.find(x)) != hashMap.end()) {
            int left = min(index, itr->second);
            int right = max(index, itr->second);
            vector<int> res = {left, right};
            return res;
        }
        hashMap.insert(make_pair(num, index));
    }
    return {};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    twoSum(numbers, target);
    return 0;
}
