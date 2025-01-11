#ifndef CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

// Template class for a thread-safe queue using mutexes and condition variables
template<typename T>
class ConcurrentQueue
{
public:
    void push(const T &value);
    bool pop(T &value);
    bool empty();

private:
    std::condition_variable m_cv;
    std::mutex m_mutex;
    std::queue<T> m_queue;
};

std::mutex cout_mutex;
void startProducerConsumer();

#endif // CONCURRENT_QUEUE_H