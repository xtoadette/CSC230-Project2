/*
 Name:  Stephanie Contino
 Date:  10/18/22
 File name: List.h
 Description: This program creates a linked list and tests inserting nodes before and after, push back and push front, as well as erasing nodes.
 */
#ifndef _LIST_H_
#define _LIST_H_

// Templated Node class
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
    Node() {};                          // Constructors
    Node(T data) { this->data = data; }
    // ~Node() { std::cout << "X"; };   // For debugging
};

// Templated List class
template <class T>
class List {
private:
    Node<T> *_first = nullptr;          // Always points to first list Node<T>
    Node<T> *_last  = nullptr;          // Always points to last list Node<T>
    int _size  = 0;                     // Always holds the size of the List<T>
public:
    List() {};                          // Constructor
    ~List();                            // Destructor
    int size() const;                   // Get List size (_size)
    Node<T> *first() const;             // Get pointer to first Node<T>
    Node<T> *last() const;              // Get pointer to last Node<T>
    T &front() const;                   // Get ref to data in first element
    T &back() const;                    // Get ref to data in last element
    void erase(Node<T> *n);             // Delete Node<T> from List<T>
    Node<T>* insert_after(Node<T> *n, const T &data);   // Insert Node<T> into List<T>
    Node<T>* insert_before(Node<T> *n, const T &data);  // Return pointer to new Node<T>
    Node<T>* push_front(const T &data); // Add data item to front of List
    Node<T>* push_back(const T &data);  // Add data item to end of List
    void pop_front();                   // Remove first Node<T> from List<T>
    void pop_back();                    // Remove last Node<T> from List<T>
};

template <class T>
List<T>::~List()
{
    while (this->_first != nullptr) //Checks if the first element is nullptr
    {
        this->pop_front();
    }
}

//Returns size
template <class T>
int List<T>::size() const
{
    return _size;
}

//returns front element address
template <class T>
Node<T>* List<T>::first() const
{
    return _first;
}

//returns last element address
template <class T>
Node<T>* List<T>::last() const
{
    return _last;
}

//returns front element data
template <class T>
T& List<T>::front() const
{
    return _first->data;
}

//returns last element data
template <class T>
T& List<T>::back() const
{
    return _last->data;
}

template <class T>
Node<T>* List<T>::insert_after(Node<T> *n, const T &data)
{
    //creates new node
    Node<T>* tmp = new Node<T>(data);
    
    //reassigns node pointers
    tmp->next = n->next;
    tmp->prev = n;
    n->next = tmp;
    
    //checks if it wasn't the last item in the list
    if (tmp->next != nullptr)
    {
        tmp->next->prev = tmp;
    }
    else
    {
        this->_last = tmp;
    }
    _size++;
    
    return tmp;
}

template <class T>
Node<T>* List<T>::insert_before(Node<T> *n, const T &data)
{
    //creates new node
    Node<T>* tmp = new Node<T>(data);
    
    //reassigns node pointers
    tmp->next = n;
    tmp->prev = n->prev;
    n->prev = tmp;
    
    //checks if it wasn't the last item in the list
    if (tmp->prev != nullptr)
    {
        tmp->prev->next = tmp;
    }
    else
    {
        this->_first = tmp;
    }
    _size++;
    
    return tmp;
}

template <class T>
void List<T>::erase(Node<T> *n)
{
    //checks if it wasn't the first or last item in the list
    if (n->prev != nullptr)
    {
        n->prev->next = n->next;
    }
    else
    {
        this->_first = n->next;
    }
    
    if (n->next != nullptr)
    {
        n->next->prev = n->prev;
    }
    else
    {
        this->_last = n->prev;
    }
    
    //deallocates memory
    delete n;
    
    _size--;
}

//pushes node to the front of the list
template <typename T>
Node<T>* List<T>::push_front(const T &data)
{
    Node<T>* tmp = new Node<T>(data);
    if (this->_size == 0)
    {
        _first = tmp;
        _last = tmp;
        _size = 1;
    }
    else
    {
        tmp = insert_before(_first, data);
    }
    return tmp;
    _size++;
}

//pushes node to the back of the list
template <typename T>
Node<T>* List<T>::push_back(const T &data)
{
    Node<T>* tmp = new Node<T>(data);
    if (this->_size == 0)
    {
        _first = tmp;
        _last = tmp;
        _size = 1;
    }
    else
    {
        tmp = insert_after(_last, data);
    }
    return tmp;
    _size++;
}

//removes first element
template <typename T>
void List<T>::pop_front()
{
    if (_size != 0)
    {
        erase(this->_first);
    }
}

//removes last element
template <typename T>
void List<T>::pop_back()
{
    if (_size != 0)
    {
        erase(this->_last);
    }
}

// Overload ostream insertion operator for List
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    Node<T> *n = list.first();
    os << "[";
    if (n != nullptr) {
        os << n->data;
        n = n->next;
    }
    while (n != nullptr) {
        os << ", " << n->data;
        n = n->next;
    }
    os << "]";
    return os;
}

#endif
