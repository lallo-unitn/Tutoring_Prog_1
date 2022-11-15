#include <iostream>
#include <cstring>
#include "esercizio1.h"

using namespace std;

void setAddress(address &a)
{
    cout << "\n Inserisci via: ";
    cin >> a.via;
    cout << "\n Inserisci civico: ";
    cin >> a.civico;
    cout << "\n Inserisci comune: ";
    cin >> a.comune;
    cout << "\n Inserisci cap: ";
    cin >> a.cap;
    cout << "\n Inserisci prov: ";
    cin >> a.prov;
}

void printAddress(address &a)
{
    cout << "Via: " << a.via << endl;
    cout << "Civico: " << a.civico << endl;
    cout << "Comune: " << a.comune << endl;
    cout << "cap: " << a.cap << endl;
    cout << "prov: " << a.prov << endl;
    cout << endl;
}

void setName(char s[])
{
    cout << "\n Inserisci name: ";
    cin >> s;
}

void printName(char s[])
{
    cout << "name: " << s << endl;
}

void setSurname(char s[])
{
    cout << "\n Inserisci surname: ";
    cin >> s;
}

void printSurname(char s[])
{
    cout << "surname: " << s << endl;
}

void setPearson(pearson &p)
{
    setName(p.name);
    setSurname(p.surname);
    setAddress(p.pearsonAddress);
}

void printPerson(pearson &p)
{
    printName(p.name);
    printSurname(p.surname);
    printAddress(p.pearsonAddress);
}

void initGroup(group &g)
{
    g.npers = 0;
}

bool addPersonToGroup(const pearson &p, group &g)
{
    bool res = true;
    if (g.npers == MAX_PERS)
        res = false;
    else
    {
        pearson *tmp;
        tmp = new (pearson);
        *tmp = p;
        g.names[g.npers] = tmp;
        g.surnames[g.npers] = tmp;
        g.npers++;
        sortByName(g.names, g.npers);
        sortBySurname(g.surnames, g.npers);
    }
    return res;
}

void printGroupByName(group &g)
{
    printPeopleArray(g.names, g.npers);
}

void printGroupBySurname(group &g)
{
    printPeopleArray(g.surnames, g.npers);
}

void printPeopleArray(pearson *p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printPerson(*p[i]);
    }
}

void swap(pearson *&p1, pearson *&p2)
{
    pearson *temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

// procedura di bubble sort, per name
void sortByName(pearson *p[], int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (strcmp(p[j]->name, p[j + 1]->name) > 0)
                swap(p[j], p[j + 1]);
}

// procedura di bubble sort, per surname
void sortBySurname(pearson *p[], int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (strcmp(p[j]->surname, p[j + 1]->surname) > 0)
                swap(p[j], p[j + 1]);
}

pearson *searchByName(char name[], group g)
{
    return searchByNameWrap(name, g.names, 0, g.npers - 1);
}

// procedura di ricerca dicotomica, per name
pearson *searchByNameWrap(char name[], pearson *p[], int inizio, int fine)
{
    int pivot, cmp;
    pearson *res;
    if (inizio > fine)
        res = NULL;
    else
    {
        pivot = (inizio + fine) / 2;
        cmp = strcmp(p[pivot]->name, name);
        if (cmp == 0)
            res = p[pivot];
        else if (cmp > 0)
            res = searchByNameWrap(name, p, inizio, pivot - 1);
        else
            res = searchByNameWrap(name, p, pivot + 1, fine);
    }
    return res;
}

pearson *searchBySurname(char surname[], group g)
{
    return searchBySurnameWrap(surname, g.surnames, 0, g.npers - 1);
}

// procedura di ricerca dicotomica, per surname
pearson *searchBySurnameWrap(char surname[], pearson *p[], int inizio, int fine)
{
    int pivot, cmp;
    pearson *res;
    if (inizio > fine)
        res = NULL;
    else
    {
        pivot = (inizio + fine) / 2;
        cmp = strcmp(p[pivot]->surname, surname);
        if (cmp == 0)
            res = p[pivot];
        else if (cmp > 0)
            res = searchBySurnameWrap(surname, p, inizio, pivot - 1);
        else
            res = searchBySurnameWrap(surname, p, pivot + 1, fine);
    }
    return res;
}