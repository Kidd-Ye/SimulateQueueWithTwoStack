//
//  main.cpp
//  SimulateQueueWithTwoStack
//
//  Created by kidd on 2018/6/22.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXSIZE 3

struct Stack{
    int data[MAXSIZE];
    int top = -1;
};

bool StackEmpty(Stack &s){
    if (s.top == -1) {
        return true;
    }
    return false;
}

bool StackOverflow(Stack &s){
    if (s.top == MAXSIZE - 1) {
        return true;
    }
    return false;
}

void Push(Stack &s, int x){
    s.top++;
    s.data[s.top] = x;
//    cout<< x << "进栈" << endl;
}

void Pop(Stack &s, int &x){
    x = s.data[s.top];
    s.top -= 1;
//    cout<< x << "出栈" << endl;
}

void EnQueue(Stack &s1, Stack &s2, int element){
    if (StackOverflow(s1) && !StackEmpty(s2)) {
        cout<< "Queue is full." << element <<"不能入队" << endl;
        return;
    }
    if (StackOverflow(s1) && StackEmpty(s2)) {
        int temp = 0;
        cout<< "将s1中的数据全部插入s2." << endl;
        while (!StackEmpty(s1)) {
            Pop(s1, temp);
            Push(s2, temp);
        }
    }
    Push(s1, element);
    cout<< element << "进队" << endl;
}

void DeQueue(Stack &s1, Stack &s2){
    int temp = 0;
    if (StackEmpty(s2)) {
        if (StackEmpty(s1)) {
            cout<< "Queue is empty." << endl;
            return;
        }else{
            cout<< "将s1中的数据全部插入s2." << endl;
            while (!StackEmpty(s1)) {
                Pop(s1, temp);
                Push(s2, temp);
            }
        }
    }
    Pop(s2, temp);
    cout<< temp << "出队" << endl;
}

int main(int argc, const char * argv[]) {
    
    Stack s1,s2;
    EnQueue(s1, s2, 1);
    EnQueue(s1, s2, 2);
    EnQueue(s1, s2, 3);
    EnQueue(s1, s2, 4);
    EnQueue(s1, s2, 5);
    EnQueue(s1, s2, 6);
    EnQueue(s1, s2, 7);
    
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    EnQueue(s1, s2, 5);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    
    return 0;
}
