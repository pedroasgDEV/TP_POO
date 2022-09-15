//bibliotecas
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

//Modulos
#include "classes.h"

//Prototipo das funções
Livro* newClass(string arqName);
void split(const string&, list<string>&, char);

//Função

Livro* newClass(string arqName){
    //Variaveis
    int type, ano, cols; 
    string titulo, idioma, aux, url, formatEle, FormatAud; 
    list<string> escritores, capitulos, keywords, livrarias;
    float dur;
    Livro* livro;

    //Abre o arquivo
    ifstream arq(arqName, ios :: in);

    //Lê o tipo
    arq >> type;

    //Lê o titulo
    getline(arq, titulo);
    getline(arq, titulo);

    //Lê os escritores
    getline(arq, aux); 
    split(aux, escritores, ';');

    //Lê o ano
    arq >> ano;

    //Lê o idioma
    getline(arq, idioma);
    getline(arq, idioma);

    //Lê os keywords
    getline(arq, aux); 
    split(aux, keywords, ';');

    //Lê os capitulos
    getline(arq, aux); 
    split(aux, capitulos, ';');

    switch (type){
        //Se for impresso
        case 1:
            //Lê as Livrarias
            getline(arq, aux); 
            split(aux, livrarias, ';');

            //Lê o numero de colunas
            arq >> cols;

            //Cria o obj
            livro = new Impresso(escritores, titulo, capitulos, ano, idioma, keywords, livrarias, cols);
            break;
        
        //Se for eletronico
        case 2:
            //Lê o url
            getline(arq, url); 

            //Lê o formato do arquivo
            getline(arq, formatEle);

            //Cria o obj
            livro = new Eletronico(escritores, titulo, capitulos, ano, idioma, keywords, url, formatEle);
            
            break;
        
        //Se for audiobook
        case 3:
            //Lê o url
            arq >> dur;

            //Lê o formato do arquivo
            getline(arq, FormatAud);
            getline(arq, FormatAud);

            //Cria o obj
            livro = new Audiobook(escritores, titulo, capitulos, ano, idioma, keywords, dur, FormatAud);
            break;
    }
    arq.close();

    return livro;
}

void split(const string& str, list<string>& cont, char delim){
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) cont.push_back(token);
}

int main(){
    //Variaveis
    vector<Livro*> livros;

    //Lendo os arqulivroivos
    for(char i = 1; i<=16; i++) livros.push_back(newClass("txts/" + to_string(i) + ".txt"));

    cout << *(livros.front()) << endl;
    
    //Liberar vetor de ponteiros
    for(auto item : livros) delete item;
    livros.clear();

    return 0;
}


