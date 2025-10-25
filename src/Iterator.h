#ifndef ITERATOR_H
#define ITERATOR_H

class Plant;

template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T* first() = 0;
    virtual T* next() = 0;
    virtual bool isDone() const = 0;
    virtual T* currentItem() const = 0;
};

#endif
