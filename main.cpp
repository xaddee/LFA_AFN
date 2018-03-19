#include <iostream>
#include "muchie.h"
#include <fstream>
using namespace std;

/**
 * Param @word is a char representing the word that we verify
 * Param @startOfEdge represents the state that we start with
 * Param @egesMatrix represents an matrix of all the edges that we readed ( start -letter- stop)
 * Param @currentLetterIndex is an integer used to keep count of the letter that we are verifying (I used it because i didn't want to delete the word or make a copy of it)
 * returns true or false, represents if the word belongs to the alphabet
 */
bool AFD(char *word, State startOfEdge, Edge **edgesMatrix, int currentLetterIndex) {
    if (currentLetterIndex == strlen(word) - 1 && startOfEdge.finish) return true;

    if (currentLetterIndex == strlen(word) - 1 && !startOfEdge.finish) return false;

    if (currentLetterIndex <= strlen(word) - 1 && startOfEdge.numberOfEdges == 0) return false;

    for (int i = 0; i < startOfEdge.numberOfEdges; i++)
        if (edgesMatrix[startOfEdge.number][i].letter[0] == word[currentLetterIndex]) {
            currentLetterIndex++;
            return AFD(word, edgesMatrix[startOfEdge.number][i].stop, edgesMatrix, currentLetterIndex);
        }
}

// The empty word is "#";

int main() {
    ifstream h("../datein2.txt"); // used for giving aditional examples without destroying the other txt file
    ifstream f("../datein.txt"); // testing file

    char word[21];
    int nStates;
    //Reads the word that needs to be tested
    f >> word;
    cout << word;
    //Reads the number of states
    f >> nStates;
    cout << nStates << "\n";

    // Q represents the state. exp: q[0] is the initial state;
    State State[nStates];
    // Initializes the states;
    for (int i = 0; i < nStates; i++) {
        State[i].finish = false;
        State[i].number = i;
    }

    for (int i = 0; i < nStates; i++) {
        int finalOrNot;
        //Sees if the i state is final or not (1 true, 0 false);
        f >> finalOrNot;
        if (finalOrNot == 1) State[i].finish = true;
    }

    Edge **edges;
    edges = new Edge *[nStates];

    for (int i = 0; i < nStates; i++) {
        // reads how many edges does the state i have;
        cout << "Nr de muchii pt starea " << i << ": ";
        f >> State[i].numberOfEdges;
        cout << State[i].numberOfEdges << "\n";
        edges[i] = new Edge[State[i].numberOfEdges];

        for (int j = 0; j < State[i].numberOfEdges; j++) {
            char *letter; // Used to see what letter brings us to witch state;
            letter = new char[1];

            int finalEdgeState; // the state that we ended up into
            edges[i][j].start = State[i];

            //Read the letter
            f >> (*letter);
            edges[i][j].letter = new char[1];
            strcpy(edges[i][j].letter, letter); // save the letter into our matrix;

            // Reads only the number of the state that we reached with the specific letter;
            f >> finalEdgeState;
            edges[i][j].stop = State[finalEdgeState];
            cout << edges[i][j].start.number << " " << edges[i][j].letter[0] << " " << edges[i][j].stop.number << "\n";

            delete[]letter;
        }


    }
    cout << "\n";
    if (word == "#") {
        if (State[0].finish) cout << "Cuvantul apartine alfabetului";
        else cout << "Cuvantul nu apartine alfabetului";
    } else if (AFD(word, State[0], edges, 0)) cout << " Cuvantul apartine alfabetului";
    else cout << "Cuvantul nu apartine alfabetului";

    return 0;
}