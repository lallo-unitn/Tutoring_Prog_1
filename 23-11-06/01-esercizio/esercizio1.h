#ifndef ESERCIZIO_1
#define ESERCIZIO_1

#define MAX_PERS 1000
#define MAX_NOME 20
#define MAX_COGNOME 30

struct address
{
    char via[MAX_NOME];
    int civico;
    char comune[MAX_NOME];
    int cap;
    char prov[3];
};

struct pearson
{
    char name[MAX_NOME];
    char surname[MAX_COGNOME];
    address pearsonAddress;
};

struct group
{
    int npers;
    pearson *names[MAX_PERS];
    pearson *surnames[MAX_PERS];
};

//Asks user for pearson physical address
void setAddress(address &a);

//Prints pearson physical address in stdout
void printAddress(const address &a);

//Asks user for pearson name
void setName(char s[]);

//Prints pearson name in stdout
void printName(const char s[]);

//Asks user for pearson surname
void setSurname(char s[]);

//Prints pearson surname in stdout
void printSurname(const char s[]);

//Calls functions setName, setSurname, setAddress
void setPearson(pearson &p);

//Calls functions printName, printSurname, printAddress
void printPerson(pearson &p);

//Calls function printPerson on all records
void printPeopleArray(pearson *p[], int n);

//Initializes group to zero pearsons
void initGroup(group &g);

//Add given person to group, then call sortByName on group.names[] and sortBySurname on goup.surnames[]
bool addPersonToGroup(const pearson &p, group &g);

//Print group.names[]
void printGroupByName(group &g);

//Print group.surnames[]
void printGroupBySurname(group &g);

//Swap two struct person. Used in sorting
void swap(pearson &p1, pearson &p2);

//Sort array of structs person by name
void sortByName(pearson *p[], int n);

//Sort array of structs person by surname
void sortBySurname(pearson *p[], int n);

//Search person by name
pearson *searchByName(char name[], group g);

//Wrapped function for searchByName()
pearson *searchByNameWrap(char name[], pearson *p[], int inizio, int fine);

//Search person by surname
pearson *searchBySurname(char surname[], group g);

//Wrapped function for searchBySurname()
pearson *searchBySurnameWrap(char surname[], pearson *p[], int inizio, int fine);

#endif