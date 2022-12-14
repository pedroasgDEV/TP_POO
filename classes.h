#ifndef CLASSES_H
#define CLASSES_H

//Bibliotecas
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

//Super Classe
class Livro{
    //Atributos
    vector<string> escritores, capitulos, keywords;
    string titulo, idiomaOriginal;
    int anoPubvectorringcacao;
public:

    //Construtores e destrutores
    Livro(vector<string> esc, string t, vector<string> cap, int ano, string idi, vector<string> key);
    virtual ~Livro();

    //Escritores
    vector<string> getEscritores();
    void setEscritores(vector<string> esc);

    //Titulo
    string getTitulo();
    void setTitulo(string t);
    //Capitulos
    vector<string> getCapitulos();
    void setCapitulos(vector<string> cap);
    //Ano de publicaçãp
    int getAnoPublicacao();
    void setAnoPublicacao(int ano);

    //Idioma Original
    string getIdiomaOriginal();
    void setIdiomaOriginal(string idi);
    //Keywords
    vector<string> getKeywords();
    void setKeywords(vector<string> key);

    //Sobrecarga
    friend ostream& operator<<(ostream&, const Livro&);
};

//Subclasse
class Impresso: public Livro{
    vector<string> livrarias;
    int colunas;

public:

    //Construtores e Destrutores
    Impresso(const vector<string>& esc, const string& t, const vector<string>& cap, const int& ano,
             const string& idi, const vector<string>& key, vector<string> livs, int cols);
    ~Impresso();

    //Livrarias
    vector<string> getLivrarias();
    void setLivrarias(vector<string> livs);

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
    Eletronico(const vector<string>& esc, const string& t, const vector<string>& cap, const int& ano,
             const string& idi, const vector<string>& key, string url, string format);
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
    Audiobook(const vector<string>& esc, const string& t, const vector<string>& cap, const int& ano,
             const string& idi, const vector<string>& key, float dur, string format);
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

//D
vector<Impresso*> livrariasFilter(vector<Livro*> livros, int qnt); //Retorna um vetor de livros impressos com mais ou o msm numer de livrarias do que o especificado

//E
bool escritorBusca(vector<Livro*> livros, string escritor); //Verifica se há algum audiobook de algum escritor, retorna true caso haja e falso caso contrario

//F
vector<Livro*> bookTitleSearch(vector<Livro*> livros, string bookTitle); //Pesquisa livros pelo titulo e exibe informações sobre o mesmo no main.

//G
set<string> allKeyword(vector<Livro*> livros); //Retorna um vector com todos os keywords sem repetição

//H
vector<Livro*> capFilter(vector<Livro*> livros, int qnt); //Retorna um vetor ordenado com o nome do primeiro autor com no minimo a quantidade especificada de capitulos

//I 
vector<Livro*> tituloBusca(vector<Livro*> livros, string titulo); //Retorna interadores com os tipos de livros com o titulo especificado

//J
void imprimeVector(vector<Livro*> livros, int); //Imprime no terminal ou em um arquivo todos os livros de uma coleção

//K
int keywordAmount(vector<Livro*> livros, string keyword); //Pesquisa livros por keywords e retorna a quantidade de livros encontrados.

//L
vector<Livro*> altIdioma(vector<Livro*> livros); //Função que altera o formato dos idiomas

#endif