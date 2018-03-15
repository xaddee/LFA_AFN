//
// Created by Adelin on 3/10/2018.
//

#ifndef UNTITLED_MUCHIE_H
#define UNTITLED_MUCHIE_H

typedef struct {
    bool finish;
    int number;
    int nrmuchii;
} stare;

#include <cstring>

class muchie {
public:
    char *letter;
    stare start;
    stare stop;
};
/*public:
    muchie();
   ~muchie();
    void setStart(stare);
    void setStop(stare);
    void setLetter(char*);
    char* getLetter();

};
muchie::muchie()
= default;

muchie::~muchie()
= default;

void muchie::setStart(stare q)
{
  start = q;

}

void muchie::setStop(stare q)
{
    stop = q;
}

void muchie::setLetter(char* l)
{
    strcpy(letter,l);
}

char* muchie::getLetter()
{
    return letter;
}*/
#endif //UNTITLED_MUCHIE_H
