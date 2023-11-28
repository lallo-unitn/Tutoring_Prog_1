#include <iostream>
#include "esercizio1.h"

using namespace std;

/* Initialize the priority queue. */
void init(queue &q) {
    q.head = nullptr;
    q.tail = nullptr;
}

/* Enqueue a message with its priority into the priority queue. */
retval enqueue(queue &q, messaggio mess) {
    retval res{FALSE};

    /* Create a new node for the message. */
    node *temp = new(nothrow) node;

    /* Pointer to keep track of the previous node during iteration. */
    node *prev = nullptr;

    if (temp != nullptr) {
        /* Initialize the new node with the message and set next pointer to nullptr. */
        temp->mess = mess;
        temp->next = nullptr;

        /* If the queue is empty, set the new node as both head and tail. */
        if (q.head == nullptr) {
            q.head = temp;
            q.tail = q.head;
            res = TRUE;
        } else {
            /* If the queue is not empty, iterate through the queue to find the correct
             * position for the new node. */
            node *iter = q.head;
            bool exitFlag = false;
            while (!exitFlag) {
                /* If the end of the queue is reached and the new node has equal or higher priority,
                 * add it to the end. */
                if (iter->next == nullptr && iter->mess.priority >= temp->mess.priority) {
                    q.tail->next = temp;
                    q.tail = temp;
                    exitFlag = true;
                }
                    /* If the new node has higher priority, insert it before the current node. */
                else if (iter->mess.priority < temp->mess.priority) {
                    if (iter == q.head) {
                        temp->next = q.head;
                        q.head = temp;
                    } else {
                        prev->next = temp;
                        temp->next = iter;
                    }
                    exitFlag = true;
                } else {
                    /* Move to the next node. */
                    prev = iter;
                    iter = iter->next;
                }
            }
            res = TRUE;
        }
    }

    return res;
}

/* Dequeue the message with the highest priority from the priority queue. */
retval dequeue(queue &q) {
    retval res{FALSE};

    /* If the queue is not empty, remove the head node. */
    if (q.head != nullptr) {
        node *temp = q.head;
        q.head = q.head->next;
        delete temp;
        res = TRUE;
    }

    return res;
}

/* Check if the priority queue is empty. */
retval empty(const queue &q) {
    retval res{FALSE};

    /* If the head is nullptr, the queue is empty. */
    if (q.head == nullptr) {
        res = TRUE;
    }

    return res;
}

/* Get the message with the highest priority without removing it from the priority queue. */
retval first(const queue &q, messaggio &mess) {
    retval res{FALSE};

    /* If the queue is not empty, retrieve the message from the head node. */
    if (!empty(q)) {
        mess = q.head->mess;
        res = TRUE;
    }

    return res;
}

/* Print the messages and their priorities in the priority queue. */
void print(const queue &q) {
    node *temp = q.head;

    /* Iterate through the queue and print each message and its priority. */
    while (temp != nullptr) {
        cout << temp->mess.testo << endl;
        cout << temp->mess.priority << endl;
        temp = temp->next;
    }
}
