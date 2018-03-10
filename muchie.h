//
// Created by Adelin on 3/10/2018.
//

#ifndef UNTITLED_MUCHIE_H
#define UNTITLED_MUCHIE_H
#include "stare.h"
#include <cstring>

class muchie {
private:
    char* letter;
    stare start;
    stare stop;
public:
    muchie();
   ~muchie();
    void setStart(int, bool );
    void setStop(int, bool );
    void setLetter(char *);
    char* getLetter();

};
muchie::muchie()
= default;

muchie::~muchie()
= default;

void muchie::setStart(int n, bool f)
{
    start.setNumber(n);
    start.setFinish(f);

}

void muchie::setStop(int n, bool f)
{
    stop.setNumber(n);
    stop.setFinish(f);
}

void muchie::setLetter(char* l)
{
    strcpy(letter,l);
}

char* muchie::getLetter()
{
    return letter;
}
#endif //UNTITLED_MUCHIE_H
