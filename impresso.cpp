//#include "impresso.h"
#include "classes.h"

Impresso::Impresso(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
                    const string& idi, const list<string>& key, list<string> livs, int cols):
                    Livro(esc, t, cap, ano, idi, key){ setLivrarias(livs); setColunas(cols); }

Impresso::~Impresso(){livrarias.clear();}

//Livrarias
list<string> Impresso::getLivrarias(){
    return livrarias;
}

void Impresso::setLivrarias(list<string> livs){
    livrarias = livs;
}

//Colunas
int Impresso::getColunas(){
    return colunas;
}

void Impresso::setColunas(int cols){
    colunas = cols;
}
