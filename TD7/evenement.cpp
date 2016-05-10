
#include <iostream>
#include "timing.h"
#include "evenement.h"
//using namespace TIME;
//evenement.cpp
std::ostream& operator<<(std::ostream f,const TIME::Evt1j& E){
    E.afficher(f);
    return f;
}

TIME::Agenda& TIME::Agenda::operator<<(  TIME::Evt& e)
{
    if(nbEvenement >= nbmax){
        Evt ** newtab = new Evt*[nbmax+10];
        for( unsigned int i =0; i<nbEvenement;i++)
        {
            newtab[i]=tab[i];
        }

        nbmax+=10;
        Evt** oldtab =tab;
        delete[] oldtab;
        tab=newtab;

    }
    tab[nbEvenement++]=&e;


    return *this;}
