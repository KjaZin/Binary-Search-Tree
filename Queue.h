#include "Node.h"

class Queue {
private:
    Node* front;     // Pointer to the front of the queue
    Node* rear;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        // your code here
        front = nullptr;
        rear = nullptr;
        length = 0;

    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        // your code here
        
        if ( !isEmpty())
        {
            if ( length == 1)
            {
                front = nullptr;
                rear = nullptr;
            }
            else
            {
                Node* temp = front;
                front = temp->next;
                delete temp;
            }
        }
        length -= 1;
    }
    // Peek the front element without removing it
    int peek() {
        // your code here
        if ( front == nullptr)
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    // Check if the queue is empty
    bool isEmpty() {
        // your code here
        if (front != nullptr)
        {
            return false;
        }
        else
        {
            return  true;
        }
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {
      // your code here
      std::string AtoS;
      Node* temp = front;
      for ( int i = 0; i < length; i++)
      {
        AtoS += std::to_string(temp->data);
        if ( i < length - 1)
        {
            AtoS += ", ";
        }
        temp = temp->next;
      }
      return "Queue : {" + AtoS + "}";
    }
};
