#ifndef ESERCIZIO1_H
#define ESERCIZIO1_H

#define MAX_PRIORITY 10

struct messaggio {
    char testo[10000];
    int priority;
};

struct node {
    messaggio mess;
    node *next;
};

struct queue {
    node *head;
    node *tail;
};

enum retval {
    FALSE = 0,
    TRUE = 1
};

void init(queue &q);

retval enqueue(queue &q, messaggio mess);

retval dequeue(queue &q);

retval empty(const queue &q);

retval first(const queue &q, messaggio &mess);

void print(const queue &q);

#endif