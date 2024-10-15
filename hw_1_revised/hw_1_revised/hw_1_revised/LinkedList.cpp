#include "LinkedList.h"
#include <iostream>
//Node constructor:
Node::Node()
{
    value = "default";
    next = NULL;
}

//LinkedList constructor:
LinkedList::LinkedList()
{
    head = NULL;
}

//LinkedList copy constructor:
LinkedList::LinkedList(const LinkedList& rhs)
{
    if(rhs.head == NULL)
    {
        head = rhs.head;
    }
    else
    {
        Node *temp = rhs.head;
        Node *n = new Node;
        n->value = temp->value;
        head = n;
        temp = temp->next;
        while(temp != NULL)
        {
            Node *x = new Node;
            n->next = x;
            n = x;
            x->value = temp->value;
            temp = temp->next;
        }
    }
}

//LinkedList destructor:
LinkedList::~LinkedList()
{
    Node *remove = head;
    while(remove != NULL)
    {
        Node *n = remove->next; //these 3 lines.
        delete remove; //have to be.
        remove = n; //in this precise order.
        //need to delete before reassignment of remove.
        //otherwise delete wrong node.
        //are we deleting address or actual node???
    } //close while loop.
    std::cout << "destructor called" << std::endl;
    head = NULL; //not having this line was breaking my program.
    //had to assign head to NULL after deleting Linked List.
    //cant have head pointing to nothing / lost in program.
} //close destructor.

//LinkedList assignment operator:
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(&rhs == this)
    {
        return *this;
    }
    else
    {
        Node *remove;
        remove = head;
        while(remove != NULL)
        {
            Node *n = remove->next;
            delete remove;
            remove = n;
        } //close while loop.
        if(rhs.head == NULL)
        {
            head = rhs.head;
        }
        else
        {
            Node *temp = rhs.head;
            Node *n = new Node;
            n->value = temp->value;
            head = n;
            temp = temp->next;
            while(temp != NULL)
            {
                Node *x = new Node;
                n->next = x;
                n = x;
                x->value = temp->value;
                temp = temp->next;
            } //close nested while loop.
        } //close nested else.
    } //close outer else.
    return *this; //still dont understand this line???
} //close assignment function.

//LinkedList insertToFront() function:
void LinkedList::insertToFront(const ItemType &val)
{
    Node *n = new Node();
    n->value = val;
    n->next = NULL;
    if(head == NULL)
    {
        head = n;
    }
    else if(head != NULL)
    {
        n->next = head;
        head = n;
    }
} //close insertToFront() function.

//LinkedList printList() function:
void LinkedList::printList() const
{
    Node *current = head;
    while(current != NULL)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
} //close printList() function.

//LinkedList get() function:
bool LinkedList::get(int i, ItemType& item) const //read-only.
{
    //i is an index location of a node.
    //item stores the string at selected index/node.
    bool flag = false;
    Node *current = head;
    int counter = 0; //not 1 bc indexing starts at 0.
    while(current != NULL)
    {
        if(counter == i)
        {
            item = current->value;
            flag = true;
            break; //exit loop.
        }
        else
        {
            current = current->next;
            counter = counter + 1;
            flag = false;
        }
    } //close while loop.
    return flag;
} //close get() function.

//LinkedList reverseList() function:
void LinkedList::reverseList()
{
    //need 3 ptrs to traverse.
    //not moving nodes around.
    //moving/shifting ptr arrows around.
    Node *previous = NULL; //need 3 ptrs to traverse.
    Node *current = head;
    Node *nexT = NULL;
    while(current != NULL)
    {
        nexT = current->next;
        current->next = previous;
        previous = current;
        current = nexT;
    }
    head = previous;
} //close reverseList() function.

//LinkedList printReverse() function:
void LinkedList::printReverse() const //read-only
//cannot change object data.
{
    for(int i = size() - 1; i > -1; i--)
    //start at end of list and traverse backwards.
    {
    ItemType x; //new var creation every iteration.
    get(i, x); //ListSeven.get(1, x);
    std::cout << x;
    }
} //close printReverse() function.

//LinkedList append() function:
void LinkedList::append(const LinkedList &other)
{
    Node* current = head;
    //*need to create deep copy of list(s)
    //so far creating shallow ones.
    if(head == NULL) //current list is EMPTY:
    {
        if(other.head == NULL) //other list IS empty:
            //when do we use -> versus . operator???
        {
            return; //bc appending empty to empty.
            //returning nothing???
        }
        else //other list is NOT empty:
        {
            //create a deep copy of list being appended.
            LinkedList deepCopyOther(other);
            //calling copy constructor???
            
            head = deepCopyOther.head;
            deepCopyOther.head = NULL;
        }
    } //close outer if.
    else //current list is NOT EMPTY:
    {
        if(other.head == NULL) //other list IS empty:
        {
            return;
        }
        else //other list is NOT empty:
        {
            //1) traverse to end of current list:
            while(current->next != NULL)
                //would current != NULL work in this case???
            {
                current = current->next;
            } //close while loop
            
            //2)make deep copy of other.
            LinkedList deepCopyOther(other);
            
            //3)link current last node to head of other node.
            current->next = deepCopyOther.head;
            
            //4)handle empty pointer remaining.
            deepCopyOther.head = NULL;
        }
    } //close outer else.
} //close append() function.
          
//LinkedList swap() function:
void LinkedList::swap(LinkedList &other)
{
    Node *n = head;
    head = other.head;
    other.head = n;
    n = NULL;
} //close swap() function.

//LinkedList size() function:
int LinkedList::size() const
{
    Node *current = head;
    int counter = 0;
    while(current != NULL)
    {
        counter = counter + 1;
        current = current->next;
    }
    return counter;
} //close size() function.

