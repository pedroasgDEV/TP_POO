# ifndef AUDIOBOOK_H
# define AUDIOBOOK_H

//Bibliotecas
using namespace std;

//Classes herdadas
#include "livro.h"

//Classe abstrata
class Audiobook: public Livro{
    float duracao;
    string formatoAudio;

public:

    //Construtores e Destrutores
    Audiobook(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
             const string& idi, const list<string>& key, float dur, string format);
    ~Audiobook();

    //Duração
    float getDuracao();
    void setDuracao(float dur);

    //Formato Audio
    string getformatoAudio();
    void setformatoAudio(string format);

    //Sobrecargas
    friend ostream& operator<<(ostream&, Audiobook&);
};


#endif