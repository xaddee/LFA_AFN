#include <iostream>
#include "muchie.h"
#include <fstream>
using namespace std;


bool AFD(char *cuvant, stare start, muchie **matriceMuchii, int k) {
    if (k == strlen(cuvant) && start.finish)
        return true;
    else {
        for (int i = 0; i < start.nrmuchii; i++) {
            if (matriceMuchii[start.number][i].letter[0] == cuvant[k]) {
                k++;
                return AFD(cuvant, matriceMuchii[start.number][i].stop, matriceMuchii, k);
            }
        }
    }
    return false;
}

ifstream f("datein.txt");
int main() {
    char cuvant[21];
    int n;
    //cout << "Introduceti cuvantul ce trebuie testat: ";
    f >> cuvant;
    cout << cuvant;
    //cout << "Introduceti nr de stari: ";
    f >> n;
    cout << n;

    stare q[n];
    for (int i = 0; i < n; i++) {
        q[i].finish = false;
        q[i].number = i;
    }

    for (int i = 0; i < n; i++) {
        int x;
        //cout << "Este starea "<< i << " finala? (1/0) ";
        f >> x;
        if (x == 1) q[i].finish = true;
    }

    muchie **muchii;
    muchii = new muchie *[n];

    for (int i = 0; i < n; i++) {

        //cout << "Nr de muchii pt starea " << i << ": ";
        f >> q[i].nrmuchii;
        muchii[i] = new muchie[q[i].nrmuchii];
        for (int j = 0; j < q[i].nrmuchii; j++) {
            char *a;
            a = new char[1];
            int final;
            muchii[i][j].start = q[i];
            //cout << "Introduceti litera de pe muchia "<<j+1<< " a starii " << i << ":";
            f >> (*a);
            cout << (*a);
            muchii[i][j].letter = new char[1];
            strcpy(muchii[i][j].letter, a);
            //cout << "Introduceti starea in care ajunge (doar cifra): ";
            f >> final;
            cout << final;
            muchii[i][j].stop = q[final];
            delete[]a;
        }


    }

    if (AFD(cuvant, q[0], muchii, 0)) {
        cout << " Cuvantul apartine alfabetului";
    } else cout << "Cuvantul nu apartine alfabetului";

    return 0;
}