
#include <cstring>

typedef struct {
    bool finish;
    int number;
    int numberOfEdges;
} State;

typedef struct {
    char *letter;
    State start;
    State stop;
} Edge;