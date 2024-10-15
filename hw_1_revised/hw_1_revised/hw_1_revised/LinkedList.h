#ifndef LinkedList_h
#define LinkedList_h
#include <string>
typedef std::string ItemType;

struct Node
{
    ItemType value;
    Node *next;
public:
    Node();
}; //end Node structure.

class LinkedList
{
public:
    Node *head; //points to the head of List.
public:
//constructor:
    LinkedList();
//copy constructor:
    LinkedList(const LinkedList& rhs);
//destructor:
    ~LinkedList();
//assigment operator function:
    const LinkedList& operator=(const LinkedList& rhs);
//insertToFront() function:
    void insertToFront(const ItemType &val);
//printList() function:
    void printList() const;
//bool get(int i, ItemType& item) const:
    bool get(int i, ItemType& item) const;
//void reverseList():
    void reverseList();
//void printReverse() const:
    void printReverse() const;
//void append(const LinkedList &other):
    void append(const LinkedList &other);
//void swap(LinkedList &other):
    void swap(LinkedList &other);
//size() function:
    int size() const;
}; //end LinkedList class.

#endif /* LinkedList_h */

