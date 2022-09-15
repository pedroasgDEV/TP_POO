//Bibliotecas
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

//Modulos
#include "classes.h"

//B: Retorna um vetor com livros no edioma especificado
vector<Livro*> idiomaBusca(vector<Livro*> livros, string idioma){
    vector<Livro*> temp; //Cria um vetor temporario

    //Um for em todos os livros
    for(auto item : livros)
        if(item->getIdiomaOriginal() == idioma) temp.push_back(item); //Se o idioma for igual o especificado é adicionado ao vetor
    return temp;
}

//C: //Retorna um vetor de livros eletronicos em formato especificado ordenado pelo ano de publicação
vector<Eletronico*> yearSort(vector<Livro*> livros, string format){
    vector<Eletronico*> temp; 

    for(auto item : livros){
        //Faz o downcast do item do vetor
        Eletronico* item_temp = dynamic_cast<Eletronico*>(item);
        //Verifica se o downcast foi bem feito e adiciona ao vetor temporario se o formato for o especificado
        if((item_temp != nullptr) && (item_temp->getformatoArquivo() == format)) temp.push_back(item_temp);
    }

    //Ordena vetor pelo ano
    sort(temp.begin(), temp.end(), [](Eletronico* x, Eletronico* y){ return x->getAnoPublicacao() < y->getAnoPublicacao();});

    return temp;

}

//J: //Imprime no terminal ou em um arquivo todos os livros de uma coleção
void imprimeVector(vector<Livro*> livros, int esc){
    //0 - se for para imprimir no terminal
    //1 - se for para imprimir no arquivo

    if(!esc)
        for(auto item : livros){
            if(typeid(*item) == typeid(class Impresso))
                cout << *(dynamic_cast<Impresso*>(item)) << endl;

            else if(typeid(*item) == typeid(class Eletronico))
                cout << *(dynamic_cast<Eletronico*>(item)) << endl;
            else 
                cout << *(dynamic_cast<Audiobook*>(item)) << endl;
        }
    
    else{
        ofstream arq("saida.txt", ios::out);
        for(auto item : livros){
            if(typeid(*item) == typeid(class Impresso))
                arq << *(dynamic_cast<Impresso*>(item)) << endl;

            else if(typeid(*item) == typeid(class Eletronico))
                arq << *(dynamic_cast<Eletronico*>(item)) << endl;
            else 
                arq << *(dynamic_cast<Audiobook*>(item)) << endl;
        }
    }
}