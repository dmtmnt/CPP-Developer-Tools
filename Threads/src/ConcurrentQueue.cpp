#include "ConcurrentQueue.h"

// Explicit instantiations of ConcurrentQueue for common types
template class ConcurrentQueue<int>;
template class ConcurrentQueue<double>;

// Thread-safe method to add an item to the queue
template<typename T>
void ConcurrentQueue<T>::push(const T& value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(value);
    m_cv.notify_one();
}

// Thread-safe method to remove an item from the queue; blocks if the queue is empty
template<typename T>
bool ConcurrentQueue<T>::pop(T& value)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv.wait(lock, [this] { return !m_queue.empty(); });
    value = m_queue.front();
    m_queue.pop();
    return true;
}

// Check if the queue is empty
template <typename T>
bool ConcurrentQueue<T>::empty()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.empty();
}

// Test purpose only/
#include <iostream>
#include <thread>
#include <atomic>

std::mutex cout_mutex;
void startProducerConsumer()
{
    ConcurrentQueue<int> queue;
    std::atomic<bool> go{false}, done{false};
    const int num_iterations = 1000;

    std::thread producer([&]()
                         {
        while (!go) std::this_thread::yield();
        for (int i = 0; i < num_iterations; ++i) {
            queue.push(i);
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << "Produced: " << i << std::endl;
            }
        }
        done = true; });

    std::thread consumer([&]()
                         {
        while (!go) std::this_thread::yield();
        int data;
        while (!done || !queue.empty()) {
            if (queue.pop(data)) {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << "Consumed: " << data << std::endl;
            }
        } });

   // Start both threads
    go = true;
    producer.join();
    consumer.join();
}