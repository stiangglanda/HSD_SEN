///////////////////////////////////////////////////////////////////////////
// Workfile : RingBuffer.h
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : RingBuffer Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <iostream>
#include <vector>

static std::string const cErrEmpty = "ringbuffer is empty!";
static std::string const cErrCap = "Capacity mismatch!";
static std::string const cErrCapCTor = "Capacity of RingBuffer must be greater than 0!";

template <typename TValue>
class RingBuffer {
public:

    explicit RingBuffer(size_t const capacity);

    // Creates a deep copy of an existing RingBuffer
    RingBuffer(RingBuffer const& other);

    // Cleans up all dynamically allocated elements
    ~RingBuffer();

    // Deep copies elements from another buffer of same capacity
    RingBuffer& operator=(RingBuffer const& other);

    // returns true if the buffer is empty
    bool IsEmpty() const;

    //enqueues an element
    void Enqueue(TValue const& element);
    //dequeues an element; if empty -> message: "ringbuffer is empty!"
    void Dequeue(TValue& element);
    //print all elements in buffer
    void Print(std::ostream& ost = std::cout) const;
private:
    void Clear();
    const size_t mCapacity;
    size_t mSize = 0;
    size_t mHead = 0;
    size_t mTail = 0;
    std::vector<TValue *> buffer;
};

template<typename TValue>
RingBuffer<TValue>::RingBuffer(size_t const capacity) : mCapacity(capacity), buffer(capacity) {
    if (mCapacity == 0) {
        throw std::invalid_argument(cErrCapCTor);
    }
}

template<typename TValue>
RingBuffer<TValue>::RingBuffer(RingBuffer const& other) :
mCapacity(other.mCapacity), buffer(other.mCapacity),
mHead(other.mHead), mTail(other.mTail), mSize(other.mSize) {
    size_t index = mTail;

    for (size_t i = 0; i < mSize; ++i) {
        TValue* sourcePtr = other.buffer.at(index);
        if (sourcePtr != nullptr) {
            buffer.at(index) = new TValue(*sourcePtr);
        } else {
            buffer.at(index) = nullptr;
        }

        index = (index + 1) % mCapacity;
    }
}

template<typename TValue>
RingBuffer<TValue>::~RingBuffer() {
    Clear();
}

template<typename TValue>
RingBuffer<TValue> & RingBuffer<TValue>::operator=(RingBuffer const &other) {
    if (this == &other) {
        return *this;
    }
    if (mCapacity != other.mCapacity) {
        throw std::invalid_argument(cErrCap);
    }

    Clear();
    mHead=other.mHead;
    mTail=other.mTail;
    mSize=other.mSize;

    size_t index = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        TValue* sourcePtr = other.buffer.at(index);
        if (sourcePtr != nullptr) {
            buffer.at(index) = new TValue(*sourcePtr);
        } else {
            buffer.at(index) = nullptr;
        }
        index = (index + 1) % mCapacity;
    }
    return *this;
}

template<typename TValue>
bool RingBuffer<TValue>::IsEmpty() const {
    return mSize == 0;
}

template<typename TValue>
void RingBuffer<TValue>::Enqueue(TValue const& element) {
    if (mSize < mCapacity) {
        mSize++;
    } else {
        delete buffer.at(mTail);
        buffer.at(mTail) = nullptr;
        mTail = (mTail + 1) % mCapacity;
    }
    buffer.at(mHead) = new TValue(element);
    mHead = (mHead + 1) % mCapacity;
}

template<typename TValue>
void RingBuffer<TValue>::Dequeue(TValue& element) {

    if (!IsEmpty()) {
        TValue* ptr = buffer.at(mTail);
        if (ptr != nullptr) {
            element = *ptr;
            delete ptr;
        }
        buffer.at(mTail) = nullptr;
        mTail = (mTail + 1) % mCapacity;
        mSize--;
    } else {
        throw std::out_of_range(cErrEmpty);
    }
}

template<typename TValue>
void RingBuffer<TValue>::Print(std::ostream &ost) const {
    size_t index = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        TValue* ptr = buffer.at(index);
        if (ptr != nullptr) {
            ost << *ptr << " ";
        }
        index = (index + 1) % mCapacity;
    }
    ost << std::endl;
}

template<typename TValue>
void RingBuffer<TValue>::Clear() {
    size_t deleteIndex = mTail;
    for (size_t i = 0; i < mSize; ++i) {
        delete buffer.at(deleteIndex);
        buffer.at(deleteIndex) = nullptr;
        deleteIndex = (deleteIndex + 1) % mCapacity;
    }
}

#endif
