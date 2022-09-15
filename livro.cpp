#include "classes.h"

//Construtor e destrutor
Livro::Livro(vector<string> esc, string t, vector<string> cap, int ano, string idi, vector<string> key){
        setEscritores(esc); setTitulo(t); setCapitulos(cap); setAnoPublicacao(ano);
        setIdiomaOriginal(idi); setKeywords(key);
    }

Livro::~Livro(){escritores.clear(); capitulos.clear(); keywords.clear();}

//escritores
vector<string> Livro::getEscritores(){ return escritores; }
void Livro::setEscritores(vector<string> esc){ escritores = esc; }

//Titulo
string Livro::getTitulo(){ return titulo; }
void Livro::setTitulo(string t){ titulo = t;}

//Capitulos
vector<string> Livro::getCapitulos(){ return capitulos; }
void Livro::setCapitulos(vector<string> cap) { capitulos = cap; }

//Ano de publicaçãp
int Livro::getAnoPublicacao() { return anoPubvectorringcacao; }
void Livro::setAnoPublicacao(int ano) { anoPubvectorringcacao = ano; }

//Idioma Original
string Livro::getIdiomaOriginal() { return idiomaOriginal; }
void Livro::setIdiomaOriginal(string idi) { idiomaOriginal = idi; }

//Keywords
vector<string> Livro::getKeywords() { return keywords; }
void Livro::setKeywords(vector<string> key) { keywords = key; }

//Sobrecarga operador
ostream& operator<<(ostream& out, const Livro& liv){

    //Imprimir titulo
    if(liv.titulo.size() > 30) for(int i = 0; i < 30; i++) out << liv.titulo[i];
    else out << liv.titulo;

    out << " | ";

    //Imprimir escritor
    if(liv.escritores.front().size() > 30) for(int i = 0; i < 30; i++) out << liv.escritores.front()[i];
    else out << liv.escritores.front();

    out << "|";

    //Imprimir idioma 
    if(liv.idiomaOriginal.size() > 10) for(int i = 0; i < 10; i++) out << liv.idiomaOriginal[i];
    else out << liv.idiomaOriginal;

    out << " | ";

    //Imprimir o numero de capitulos
    int tam = liv.capitulos.size();
    if(tam < 10) out << "  " + to_string(tam);
    else if(tam < 100) out << ' ' + to_string(tam);
    else out << to_string(tam);

    out << "|";

    //Imprimir o numero de keywords
    tam = liv.keywords.size();
    if(tam < 10) out << ' ' + to_string(tam);
    else out <<  to_string(tam);

    return out;
}
