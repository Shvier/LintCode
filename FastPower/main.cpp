//
//  main.cpp
//  FastPower
//
//  Created by Shvier on 2018/11/20.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

int fastPower(int a, int b, int n) {
    // write your code here
    long long ans = 1;
    long long temp = a;
    
    while (n != 0) {
        if (n % 2 == 1) {
            ans = (ans * temp) % b;
        }
        temp = temp * temp % b;
        n = n / 2;
    }
    return ans % b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << fastPower(11, 123898, 12345) << std::endl;
    return 0;
}
