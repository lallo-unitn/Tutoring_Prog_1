using namespace std;
#include <iostream>
#include "esercizio1.h"

void init(queue &q)
{

    q.head = NULL;
    q.tail = NULL;
}

retval enqueue(queue &q, messaggio mess)
{

    retval res{FALSE};

    node *temp = new (nothrow) node;

    node *prev = NULL;

    if (temp != NULL)
    {
        temp->mess = mess;
        temp->next = NULL;

        if (q.head == NULL)
        {
            q.head = temp;
            q.tail = q.head;
            res = TRUE;
        }
        else
        {
            cout << "DEBUG" << endl;
            node *iter = q.head;
            bool exitFlag = false;
            while (!exitFlag)
            {
                if (iter->next == NULL && iter->mess.priorita >= temp->mess.priorita)
                {
                    q.tail->next = temp;
                    q.tail = temp;
                    exitFlag = true;
                    cout << "DEBUG2" << endl;
                }
                else if (iter->mess.priorita < temp->mess.priorita)
                {
                    if (iter == q.head)
                    {
                        temp->next = q.head;
                        q.head = temp;
                    }
                    else
                    {
                        prev->next = temp;
                        temp->next = iter;
                    }
                    exitFlag = true;
                    cout << "DEBUG3" << endl;
                }
                else
                {
                    prev = iter;
                    iter = iter->next;
                    cout << "ITER" << endl;
                }
            }
            res = TRUE;
        }
    }

    return res;
}

retval dequeue(queue &q)
{

    retval res{FALSE};

    if (q.head != NULL)
    {
        node *temp = q.head;
        q.head = q.head->next;
        delete temp;
        res = TRUE;
    }

    return res;
}

retval empty(const queue &q)
{

    retval res{FALSE};

    if (q.head == NULL)
    {
        res = TRUE;
    }

    return res;
}

retval first(const queue &q, messaggio &mess)
{

    retval res{FALSE};

    if (!empty(q))
    {

        mess = q.head->mess;
        res = TRUE;
    }

    return res;
}

void print(const queue &q)
{

    node *temp = q.head;

    while (temp != NULL)
    {
        cout << temp->mess.testo << endl;
        cout << temp->mess.priorita << endl;
        temp = temp->next;
    }

    delete temp;
}