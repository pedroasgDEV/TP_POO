# ifndef IMPRESSO_H
# define IMPRESSO_H

//Bibliotecas
using namespace std;

//Classes herdadas
#include "livro.h"

//Classe abstrata
class Impresso: public Livro{
    list<string> livrarias;
    int colunas;

public:

    //Construtores e Destrutores
    Impresso(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
             const string& idi, const list<string>& key, list<string> livs, int cols);
    ~Impresso();

    //Livrarias
    list<string> getLivrarias();
    void setLivrarias(list<string> livs);

    //Colunas
    int getColunas();
    void setColunas(int cols);

    //Sobrecargas
    friend ostream& operator<<(ostream&, Impresso&);

};


#endif