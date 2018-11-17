//
//  main.cpp
//  MiddleofLinkedList
//
//  Created by Shvier on 2018/11/16.
//  Copyright © 2018 Shvier. All rights reserved.
//

#include <iostream>

// Definition of singly-linked-list:
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode * middleNode(ListNode * head) {
    // write your code here
    if (head == NULL) {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
