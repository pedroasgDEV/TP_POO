#ifndef LIVRO_H
#define LIVR0_H

//Bibliotecas
#include <iostream>
#include <list>
using namespace std;

//Classe Abstrata
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
    ~Livro(){escritores.clear(); capitulos.clear(); keywords.clear();}

    //Escritores
    list<string> getEscritores(){ return escritores; };
    void setEscritores(list<string> esc){ escritores = esc; }

    //Titulo
    string getTitulo(){ return titulo; }
    void setTitulo(string t){ titulo = t;}

    //Capitulos
    list<string> getCapitulos(){ return capitulos; }
    void setCapitulos(list<string> cap){ capitulos = cap; }

    //Ano de publicaçãp
    int getAnoPublicacao() { return anoPublistringcacao; }
    void setAnoPublicacao(int ano) { anoPublistringcacao = ano; }

    //Idioma Original
    string getIdiomaOriginal(){ return idiomaOriginal; }
    void setIdiomaOriginal(string idi) { idiomaOriginal = idi; }

    //Keywords
    list<string> getKeywords(){ return keywords; }
    void setKeywords(list<string> key){ keywords = key; }

    //Sobrecarga
    friend ostream& operator<<(ostream&, const Livro&);
};

//Classe Concreta
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

//Classe Concreta
class Eletronico: public Livro{
    string url;
    string formatoArquivo;

public:

    //Construtores e Destrutores
    Eletronico(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
             const string& idi, const list<string>& key, string url, string format);
    ~Eletronico();

    //Url
    string getUrl();
    void setUrl(string url);

    //Formato Arquivo
    string getformatoArquivo();
    void setformatoArquivo(string format);

    //Sobrecargas
    friend ostream& operator<<(ostream&, Eletronico&);
};

//Classe Concreta
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