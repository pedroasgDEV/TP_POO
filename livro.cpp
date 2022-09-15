#include "classes.h"

//Construtor e destrutor
Livro::Livro(list<string> esc, string t, list<string> cap, int ano, string idi, list<string> key){
        setEscritores(esc); setTitulo(t); setCapitulos(cap); setAnoPublicacao(ano);
        setIdiomaOriginal(idi); setKeywords(key);
    }

Livro::~Livro(){escritores.clear(); capitulos.clear(); keywords.clear();}

//escritores
list<string> Livro::getEscritores(){ return escritores; }
void Livro::setEscritores(list<string> esc){ escritores = esc; }

//Titulo
string Livro::getTitulo(){ return titulo; }
void Livro::setTitulo(string t){ titulo = t;}

//Capitulos
list<string> Livro::getCapitulos(){ return capitulos; }
void Livro::setCapitulos(list<string> cap) { capitulos = cap; }

//Ano de publicaçãp
int Livro::getAnoPublicacao() { return anoPublistringcacao; }
void Livro::setAnoPublicacao(int ano) { anoPublistringcacao = ano; }

//Idioma Original
string Livro::getIdiomaOriginal() { return idiomaOriginal; }
void Livro::setIdiomaOriginal(string idi) { idiomaOriginal = idi; }

//Keywords
list<string> Livro::getKeywords() { return keywords; }
void Livro::setKeywords(list<string> key) { keywords = key; }