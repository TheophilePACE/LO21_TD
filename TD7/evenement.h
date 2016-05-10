


#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H
#include <iostream>
#include <string>
#include "timing.h"


namespace TIME{
    class Evt{
private:
    std::string sujet;
public:
    Evt(const std::string& s):sujet(s) {}
    const std::string& getDescription() const { return sujet; }

    virtual void afficher (std::ostream& f= std::cout) const =0 ;
    };




    class Evt1j : public Evt {
    private:
        Date date;
       // std::string sujet; NOT NEED BECAUSE CLASS EVT
    public:
        Evt1j(const Date& d, const std::string& s):date(d),Evt(s){} // modif avec evt()  NEED BECAUSE CLASS EVT
      //  const std::string& getDescription() const { return sujet; } NOT NEED BECAUSE CLASS EVT
        const Date& getDate() const { return date; }
        virtual void afficher(std::ostream& f= std::cout) const {
            f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<getDescription()<<"\n";
            }
        virtual ~Evt1j() {std::cout <<"\ndestruction d'un Evt1j\n";}

    };
class EvtPj : public Evt {
    private:
        Date datedeb;
        Date datefin;
       // std::string sujet; NOT NEED BECAUSE CLASS EVT
    public:
        EvtPj(const Date& db,const Date& df, const std::string& s):datedeb(db),datefin(df),Evt(s){} // modif avec evt()  NEED BECAUSE CLASS EVT
      //  const std::string& getDescription() const { return sujet; } NOT NEED BECAUSE CLASS EVT
        const Date& getDateDeb() const { return datedeb; }
        const Date& getDateFin () const { return datefin; }

        virtual void afficher(std::ostream& f= std::cout) const {
            f<<"***** Evt ********"<<"\n"<<"Datedeb="<<datedeb<<"Datefin="<<datefin<<" sujet="<<getDescription()<<"\n";
            }
        virtual ~EvtPj() {std::cout <<"\ndestruction d'un Evt1j\n";}

    };

    class Evt1jDur: public Evt1j {
    private:
        Horaire horaire;
        Duree duree;
    public:
        Evt1jDur(const Date& d,const std::string& s, const Horaire& h, const Duree t ): Evt1j(d,s), duree(t), horaire(h) {std::cout <<"Construction d'un objet de type Evt1jDur";}
        Horaire gethoraire() const {return horaire;}
        Duree getduree() const {return duree;}
        virtual void afficher(std::ostream& f= std::cout) const {

            f<<"duree : " <<duree <<"  Horaire : "<< horaire<<"\n" ;
            }
        virtual ~Evt1jDur() {std::cout <<"\ndestruction d'un Evt1jDur\n";}


    };


    class Rdv : public Evt1jDur {
private :
    std::string nomprenom ;
    std::string lieu;
public:
            Rdv(const Date& d,const std::string& s, const Horaire& h, const Duree t, const std::string& n, const std::string l) : lieu (l), nomprenom(n), Evt1jDur(d,s,h,t) {std::cout<<"Creation d'un RDV";}
            void afficher(std::ostream& f= std::cout) const {
                Evt1jDur::afficher(f);
                f<< "Rendez vous de "<< nomprenom << "ayant lieu a"<<lieu;
                };
            const std::string& getnomprenom () const {
            return nomprenom;}
            const std::string& getlieu () const {
            return lieu;}
            ~Rdv() {std::cout <<"\n destruction d'un Rdv \n";}
            Rdv& operator=(const Rdv& r){

            Evt1jDur* x=this;
            *x=r;
            nomprenom = r.nomprenom;
            lieu = r.lieu;
            return *this;
}

};

    class Agenda {
private:
    Evt ** tab;
    unsigned int nbEvenement;
    unsigned int nbmax;
    Agenda(const Agenda& A);
    Agenda operator=(Agenda B);
public:
    Agenda& operator<< ( Evt& e);
    Agenda() : nbEvenement(0), nbmax(0),tab(0){};


    };





}

//class EvtPj





std::ostream& operator<<(std::ostream& f,const TIME::Evt1j E);
//INUTILE CAR AFFICHE VIRTU
//std::ostream& Evt1jDur::operator<<(std::ostream f);
//std::ostream& Rdv::operator<<(std::ostream f);

#endif
