//
// Created by Adelin on 3/10/2018.
//

#ifndef UNTITLED_MUCHIE_H
#define UNTITLED_MUCHIE_H

#include <cstring>

typedef struct {
    bool finish;
    int number;
    int numberOfEdges;
} State;

class Edge {
public:
    char *letter;
    State start;
    State stop;
};

#endif //UNTITLED_MUCHIE_H
