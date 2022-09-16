//bibliotecas
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

//Modulos
#include "classes.h"

//Prototipo das funções
Livro* newClass(string arqName);
void split(const string&, vector<string>&, char);

//Funções
//Leitura do aquivo e criação dos objs
Livro* newClass(string arqName){
    //Variaveis
    int type, ano, cols; 
    string titulo, idioma, aux, url, formatEle, FormatAud; 
    vector<string> escritores, capitulos, keywords, livrarias;
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

//Separa de strings com ;
void split(const string& str, vector<string>& cont, char delim){
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) cont.push_back(token);
}

int main(){
    //Variaveis
    vector<Livro*> livros;

    //Lendo os arqulivroivos
    for(char i = 1; i<=16; i++) livros.push_back(newClass("txts/" + to_string(i) + ".txt"));

    cout << "\n\nQuestão B\n";
    for (auto item : idiomaBusca(livros, "Espanhol")) cout << item->getTitulo() << endl;
    
    cout << "\n\nQuestão C\n";
    for(auto item : yearSort(livros, "EPUB")) cout << static_cast<Livro>(*item) << endl;

    cout << "\n\nQuestão D\n";
    vector<Impresso*> temp_imp = livrariasFilter(livros, 1);
    if(temp_imp.size() == 0) cout << "Não encontrado\n";
    else for(auto item : temp_imp) cout << item->getTitulo() << " "<< item->getLivrarias().size() << endl;
            
    cout << "\n\nQuestão E\n";
    if(escritorBusca(livros, "John Ronald Reuel Tolkien")) cout << "Há um audio book com esse autor\n";
    else cout << "Não há um audio book com esse autor\n";

    cout << "\n\nQuestão F\n";
    imprimeVector(bookTitleSearch(livros, "O Senhor dos Aneis"), 0);

    cout << "\n\nQuestão G\n";
    for(auto item : allKeyword(livros)) cout << item << endl;

    cout << "\n\nQuestão H\n";
    imprimeVector(capFilter(livros, 3), 0);

    cout << "\n\nQuestão I\n";
    vector<Livro*> temp = tituloBusca(livros, "O Senhor dos Aneis");
    if(temp.empty()) cout << "Não foi encontrado\n";
    else imprimeVector(temp, 0);

    cout << "\n\nQuestão J\n";
    imprimeVector(livros, 1);

    cout << "\n\nQuestão H\n";
    cout << keywordAmount(livros, "narrativa") << endl;

    cout << "\n\nQuestão L\n";
    for(auto item : altIdioma(livros)) cout << *item << endl;

    cout << "\n\n";
    //Liberar vetor de ponteiros
    for(auto item : livros) delete item;
    livros.clear();

    return 0;
}


