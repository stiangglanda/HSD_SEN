///////////////////////////////////////////////////////////////////////////
// Workfile : RingBuffer.cpp
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : RingBuffer Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <iostream>
#include <iterator>
#include <vector>

template <typename TValue>
class RingBuffer {
public:

    explicit RingBuffer(size_t const capacity);

    //CopyCTor -> if necessary
    RingBuffer(RingBuffer& other);

    //DTor -> if necessary
    ~RingBuffer();

    //AssingOperator -> if necessary
    void operator=(RingBuffer const& other) = delete;

    bool IsEmpty() const;

    //enqueues an element
    void Enqueue(TValue element);
    //dequeues an element; if empty -> message: "ringbuffer is empty!"
    void Dequeue(TValue& element);
    //print all elements in buffer
    void Print(std::ostream& ost = std::cout) const;

    size_t Capacity() const { return buffer.size(); };//remove
private:
    const size_t mCapacity;
    size_t mSize = 0;
    size_t mHead = 0;
    size_t mTail = 0;
    std::vector<TValue *> buffer;

};

template<typename TValue>
RingBuffer<TValue>::RingBuffer(size_t const capacity) : mCapacity(capacity), buffer(capacity) {}

template<typename TValue>
RingBuffer<TValue>::RingBuffer(RingBuffer &other) :
mCapacity(other.mCapacity), buffer(other.mCapacity),
mHead(other.mHead), mTail(other.mTail), mSize(other.mSize) {
    int index = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        buffer.at(index) = new TValue(*other.buffer.at(index));
        index = (index + 1) % mCapacity;
    }
}

template<typename TValue>
RingBuffer<TValue>::~RingBuffer() {
    int index = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        delete buffer.at(index);
        index = (index + 1) % mCapacity;
    }
}

template<typename TValue>
bool RingBuffer<TValue>::IsEmpty() const {
    return mSize == 0;
}

template<typename TValue>
void RingBuffer<TValue>::Enqueue(TValue element) {
    if (mSize < mCapacity) {
        mSize++;
    } else {
        delete buffer.at(mTail);
        mTail = (mTail + 1) % mCapacity;
    }
    buffer.at(mHead) = new TValue(element);
    mHead = (mHead + 1) % mCapacity;
}

template<typename TValue>
void RingBuffer<TValue>::Dequeue(TValue& element) {

    if (!IsEmpty()) {
        element = *buffer.at(mTail);
        delete buffer.at(mTail);
        mTail = (mTail + 1) % mCapacity;
        mSize--;
    } else {
        throw std::out_of_range("ringbuffer is empty!");
    }
}

template<typename TValue>
void RingBuffer<TValue>::Print(std::ostream &ost) const {
    ost << "Print: ";
    int index = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        ost << *buffer.at(index) << " ";
        index = (index + 1) % mCapacity;
    }
    ost << std::endl;
}

#endif
