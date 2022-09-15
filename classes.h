#ifndef LIVRO_H
#define LIVR0_H

//Bibliotecas
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Super Classe
class Livro{
    //Atributos
    list<string> escritores, capitulos, keywords;
    string titulo, idiomaOriginal;
    int anoPublistringcacao;
public:

    //Construtores e destrutores
    Livro(list<string> esc, string t, list<string> cap, int ano, string idi, list<string> key);
    virtual ~Livro();

    //Escritores
    list<string> getEscritores();
    void setEscritores(list<string> esc);

    //Titulo
    string getTitulo();
    void setTitulo(string t);
    //Capitulos
    list<string> getCapitulos();
    void setCapitulos(list<string> cap);
    //Ano de publicaçãp
    int getAnoPublicacao();
    void setAnoPublicacao(int ano);

    //Idioma Original
    string getIdiomaOriginal();
    void setIdiomaOriginal(string idi);
    //Keywords
    list<string> getKeywords();
    void setKeywords(list<string> key);

    //Sobrecarga
    friend ostream& operator<<(ostream&, const Livro&);
};

//Subclasse
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
    friend ostream& operator<<(ostream&, const Impresso&);

};

//Subclasse
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
    friend ostream& operator<<(ostream&, const Eletronico&);
};

//Subclasse
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
    friend ostream& operator<<(ostream&, const Audiobook&);
};

//Funções da atividade
//B
vector<Livro*> idiomaBusca(vector<Livro*> livros, string idioma); //Retorna um vetor com livros no edioma especificado

//C
vector<Eletronico*> yearSort(vector<Livro*> livros, string format); //Retorna um vetor de livros eletronicos em formato especificado ordenado pelo ano de publicaçaõ

//J
void imprimeVector(vector<Livro*> livros, int); //Imprime no terminal ou em um arquivo todos os livros de uma coleção







#endif