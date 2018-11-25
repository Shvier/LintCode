//
//  main.cpp
//  RainBowSort
//
//  Created by Shvier on 2018/11/25.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void divideConquer(vector<int> &colors, int left, int right, int colorStart, int colorEnd) {
    if (left >= right || colorStart > colorEnd) {
        return;
    }
    
    int start = left;
    int end = right;
    int pivot = (colorStart + colorEnd) >> 1;
    
    while (start <= end) {
        while (start <= end && colors[start] <= pivot) {
            start ++;
        }
        while (start <= end && colors[end] > pivot) {
            end --;
        }
        if (start <= end) {
            swap(colors[start], colors[end]);
            start ++;
            end --;
        }
    }
    
    divideConquer(colors, left, end, colorStart, pivot - 1);
    divideConquer(colors, start, right, pivot + 1, colorEnd);
}

void sortColors2(vector<int> &colors, int k) {
    // write your code here
    int size = (int)colors.size();
    if (size < 1) {
        return;
    }
    
    divideConquer(colors, 0, size - 1, 1, k);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> colors = {2, 1, 1, 2};
    sortColors2(colors, 1);
    return 0;
}
