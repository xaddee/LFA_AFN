//
// Created by Adelin on 3/10/2018.
//

#ifndef UNTITLED_STARE_H
#define UNTITLED_STARE_H


class stare {
private:
    int number;
    bool finish;
public:
    stare();

    ~stare();

    void setNumber(int);

    void setFinish(bool);

    bool getFinish();

    int getNumber();
};

stare::stare()
= default;

stare::~stare()
= default;

void stare::setNumber(int n) {
    number = n;
}

void stare::setFinish(bool f) {
    finish = f;
}

bool stare::getFinish() {
    return finish;
}

int stare::getNumber() {
    return number;
}

#endif //UNTITLED_STARE_H
