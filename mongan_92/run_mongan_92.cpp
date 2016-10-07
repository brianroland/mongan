//
// Created by Christopher Roland on 10/7/16.
// from http://en.cppreference.com/w/cpp/thread/condition_variable
//
// master-worker pattern
//

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;


void worker_thread()
{
    //wait until main() sends data
    std::unique_lock<std::mutex> lk(m);      //Create a lock that does nothing but allows cv to communicate with mutex
    cv.wait(lk, []{ return ready;});         //Block worker_thread from cpu until lk is released
    //and at that point acquire the lock

    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    lk.unlock();            //release the lock
    cv.notify_one();        //signal to a listener on this cv
}

int main()
{
    std::thread worker(worker_thread);      //create thread object, it waits until notified via lock-on-mutex

    data = "Example data";
    {
        std::lock_guard<std::mutex> lk(m);       //lock the mutex until the end of the block
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lk(m);     //create lock, do not apply it
        cv.wait(lk, []{return processed; });    //Connect the lock to the condition variable
    }
    std::cout << "Bank in main(), data = " << data << std::endl;

    worker.join();
}