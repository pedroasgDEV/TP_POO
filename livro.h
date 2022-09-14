# ifndef LIVRO_H
# define LIVR0_H

//Bibliotecas
#include <iostream>
#include <list>
using namespace std;

//Classe abstrata
class Livro{
    //Atributos
    list<string> escritores, capitulos, keywords;
    string titulo, idiomaOriginal;
    int anoPublistringcacao;
public:

    //Construtores e destrutores
    Livro(list<string> esc, string t, list<string> cap, int ano, string idi, list<string> key){
        setEscritores(esc); setTitulo(t); setCapitulos(cap); setAnoPublicacao(ano);
        setIdiomaOriginal(idi); setKeywords(key);
    }

    //Escritores
    list<string> getEscritores(){ return escritores; }
    void setEscritores(list<string> esc){ escritores = esc; }

    //Titulo
    string getTitulo(){ return titulo; }
    void setTitulo(string t){ titulo = t;}

    //Capitulos
    list<string> getCapitulos(){ return capitulos; }
    void setCapitulos(list<string> cap) { capitulos = cap; }

    //Ano de publicaçãp
    int getAnoPublicacao() { return anoPublistringcacao; }
    void setAnoPublicacao(int ano) { anoPublistringcacao = ano; }

    //Idioma Original
    string getIdiomaOriginal() { return idiomaOriginal; }
    void setIdiomaOriginal(string idi) { idiomaOriginal = idi; }

    //Keywords
    list<string> getKeywords() { return keywords; }
    void setKeywords(list<string> key) { keywords = key; }
};


#endif