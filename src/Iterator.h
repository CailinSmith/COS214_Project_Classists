#ifndef ITERATOR_H
#define ITERATOR_H

class Plant;

/**
 * @class Iterator
 * @author Alex Lange
 * @brief
 * Design Pattern: Iterator
 * Participant: Iterator Interface
 * 
 * This template class defines the interface for iterating over a collection of elements.
 * It provides methods to traverse a collection without exposing its underlying representation.
 * Concrete iterator classes implement this interface to provide specific traversal strategies.
 * 
 * @tparam T The type of elements to iterate over
 * @see Aggregate
 */
template<typename T>
class Iterator {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~Iterator() = default;
    
    /**
     * @brief Returns the first element in the collection
     * @return Pointer to the first element, or nullptr if none found
     */
    virtual T* first() = 0;
    
    /**
     * @brief Advances to and returns the next element
     * @return Pointer to the next element, or nullptr if iteration is complete
     */
    virtual T* next() = 0;
    
    /**
     * @brief Checks if the iteration has completed
     * @return true if iteration is complete, false otherwise
     */
    virtual bool isDone() const = 0;
    
    /**
     * @brief Returns the current element in the iteration
     * @return Pointer to the current element, or nullptr if invalid position
     */
    virtual T* currentItem() const = 0;
};

#endif
