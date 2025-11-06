#ifndef LINKED_BAG_H
#define LINKED_BAG_H

#include <memory>
#include <vector>

template<class T>
class Node {
private:
    T item;
    std::shared_ptr<Node<T>> next;

public:
    Node() : next(nullptr) {}
    Node(const T& anItem) : item(anItem), next(nullptr) {}
    Node(const T& anItem, std::shared_ptr<Node<T>> nextNodePtr) : item(anItem), next(nextNodePtr) {}

    void setItem(const T& anItem) { item = anItem; }
    void setNext(std::shared_ptr<Node<T>> nextNodePtr) { next = nextNodePtr; }
    
    T getItem() const { return item; }
    std::shared_ptr<Node<T>> getNext() const { return next; }
};

template<class T>
class LinkedBag {
private:
    std::shared_ptr<Node<T>> headPtr;
    int itemCount;

public:
    LinkedBag() : headPtr(nullptr), itemCount(0) {}
    
    // Copy constructor (part of BIG 3)
    LinkedBag(const LinkedBag<T>& aBag) {
        itemCount = aBag.itemCount;
        auto origChainPtr = aBag.headPtr;
        if (origChainPtr == nullptr) {
            headPtr = nullptr;
        } else {
            headPtr = std::make_shared<Node<T>>(origChainPtr->getItem());
            auto newChainPtr = headPtr;
            origChainPtr = origChainPtr->getNext();
            while (origChainPtr != nullptr) {
                auto nextNodePtr = std::make_shared<Node<T>>(origChainPtr->getItem());
                newChainPtr->setNext(nextNodePtr);
                newChainPtr = nextNodePtr;
                origChainPtr = origChainPtr->getNext();
            }
        }
    }
    
    // Destructor (part of BIG 3)
    ~LinkedBag() {
        clear();
    }
    
    // Assignment operator (part of BIG 3)
    LinkedBag<T>& operator=(const LinkedBag<T>& rightHandSide) {
        if (this != &rightHandSide) {
            clear();
            itemCount = rightHandSide.itemCount;
            auto origChainPtr = rightHandSide.headPtr;
            if (origChainPtr != nullptr) {
                headPtr = std::make_shared<Node<T>>(origChainPtr->getItem());
                auto newChainPtr = headPtr;
                origChainPtr = origChainPtr->getNext();
                while (origChainPtr != nullptr) {
                    auto nextNodePtr = std::make_shared<Node<T>>(origChainPtr->getItem());
                    newChainPtr->setNext(nextNodePtr);
                    newChainPtr = nextNodePtr;
                    origChainPtr = origChainPtr->getNext();
                }
            }
        }
        return *this;
    }

    bool add(const T& newEntry) {
        auto nextNodePtr = std::make_shared<Node<T>>(newEntry, headPtr);
        headPtr = nextNodePtr;
        itemCount++;
        return true;
    }

    std::vector<T> toVector() const {
        std::vector<T> bagContents;
        auto curPtr = headPtr;
        while (curPtr != nullptr) {
            bagContents.push_back(curPtr->getItem());
            curPtr = curPtr->getNext();
        }
        return bagContents;
    }

    bool remove(const T& anEntry) {
        auto entryNodePtr = getPointerTo(anEntry);
        if (entryNodePtr != nullptr) {
            entryNodePtr->setItem(headPtr->getItem());
            auto nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            itemCount--;
            return true;
        }
        return false;
    }

    void clear() {
        headPtr = nullptr;  // Smart pointer will automatically delete the chain
        itemCount = 0;
    }

    bool contains(const T& anEntry) const {
        return (getPointerTo(anEntry) != nullptr);
    }

    int getCurrentSize() const { return itemCount; }
    bool isEmpty() const { return itemCount == 0; }

private:
    std::shared_ptr<Node<T>> getPointerTo(const T& target) const {
        bool found = false;
        auto curPtr = headPtr;
        while (!found && curPtr != nullptr) {
            if (*curPtr->getItem() == *target) {
                found = true;
            } else {
                curPtr = curPtr->getNext();
            }
        }
        return curPtr;
    }
};

#endif