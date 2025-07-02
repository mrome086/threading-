//
//  main.cpp
//  Threading
//
//  Created by Michael Romero on 9/12/21.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

void loopThread1 (int i, int j) {
    
    for (int i = 0; i <= j; i = i +1){
        // m.lock();
        cout<< "thread One " << i <<endl;
        this_thread::sleep_for(chrono::nanoseconds(1));
        // m.unlock();
    }
    printf("finish\n");
}

void loopThread2 (int i, int j) {
    
    for (int i = 0; i <= j; i = i +1){
        //m.lock();
        cout<< "thread Two " << i <<endl;
        this_thread::sleep_for(chrono::nanoseconds(1));
        //m.unlock();
    }
    printf("finish\n");
}

int main(int argc, const char * argv[]) {
    
    thread t1 (loopThread1,0,10);
    thread t2 (loopThread2,0,10);
    t1.join();
    t2.join();
    
    return 0;
}
