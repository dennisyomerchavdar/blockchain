//
// Created by omer on 25.06.2020.
//

#ifndef BLOCKCHAIN_SEMAPHORE_H
#define BLOCKCHAIN_SEMAPHORE_H
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore (int count_ = 0)
            : count(count_) {}

    inline void notify()
    {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }

    inline void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);

        while(count == 0){
            cv.wait(lock);
        }
        count--;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};




#endif //BLOCKCHAIN_SEMAPHORE_H
