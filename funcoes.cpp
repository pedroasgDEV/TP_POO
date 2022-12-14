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

//C: Retorna um vetor de livros eletronicos em formato especificado ordenado pelo ano de publicação
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

//D: Retorna um vetor de livros impressos com mais ou o msm numer de livrarias do que o especificado
vector<Impresso*> livrariasFilter(vector<Livro*> livros, int qnt){
    vector<Impresso*> temp_vec; //cria uma variavel temporaria de livros
    for(auto  item : livros)
        if(typeid(*item) == typeid(class Impresso)){
            Impresso* temp = dynamic_cast<Impresso*>(item);
            if((int) temp->getLivrarias().size() >= qnt) temp_vec.push_back(temp);
        }
    
    return temp_vec;
}

//E: Verifica se há algum audiobook de algum escritor, retorna true caso haja e falso caso contrario
bool escritorBusca(vector<Livro*> livros, string escritor){
    //Lê todos os item do vetor
    for(auto item : livros)
        if(typeid(*item) == typeid(class Audiobook)) //Filtra os audiobook
            for(auto item2 : item->getEscritores()) if(item2 == escritor) return true; //Procura pelo escritor 

    return false;   
}

//F: Pesquisa livros pelo titulo e exibe informações sobre o mesmo no main.
vector<Livro*> bookTitleSearch(vector<Livro*> livros, string bookTitle){
    vector<Livro*> temp; //vector temporario.

    //pesquisa em cada livro utilizando o for.
    for(auto itr : livros){
        if(itr->getTitulo() == bookTitle) // verifica se o titulo eh igual ao titulo pesquisado.
            temp.push_back(itr); //adciona o livro a colecao de livros com o titulo pesquisado.
    }
    return temp;
}

//G: Retorna um set com todos os keywords sem repetição
set<string> allKeyword(vector<Livro*> livros){
    set<string> temp; //Cria um set temporario que não permite duplicadas
    for(auto item : livros) for(auto item_str : item->getKeywords()) temp.insert(item_str); //Insere todos as keywords
    return temp;
}

//H: //Retorna um vetor ordenado com o nome do primeiro autor com no minimo a quantidade especificada de capitulos
vector<Livro*> capFilter(vector<Livro*> livros, int qnt){
    vector<Livro*> temp; //Cria variavel temporaria
    for(auto item : livros) if((int) item->getCapitulos().size() >= qnt) temp.push_back(item); //Adiciona os livros com a qnt minima de cap especificados

    //Ordena vetor pelo nome do primeiro autor
    sort(temp.begin(), temp.end(), [](Livro* x, Livro* y){ return x->getEscritores().front() < y->getEscritores().front();});

    return temp;
}

//I: Retorna interadores com os tipos de livros com o titulo especificado
vector<Livro*> tituloBusca(vector<Livro*> livros, string titulo){
    vector<Livro*> temp; //Cria vetor temporario
    for(auto item : livros) if(item->getTitulo() == titulo) temp.push_back(item); //Busca os interadores dos 
    return temp;
}

//J: Imprime no terminal ou em um arquivo todos os livros de uma coleção
void imprimeVector(vector<Livro*> livros, int esc){
    //0 - se for para imprimir no terminal
    //1 - se for para imprimir no arquivo

    //Se for no terminal
    if(!esc)
        for(auto item : livros){ 
            if(typeid(*item) == typeid(class Impresso)) //Se for um livro impresso
                cout << *(dynamic_cast<Impresso*>(item)) << endl;

            else if(typeid(*item) == typeid(class Eletronico)) //Se for um livro eletronico
                cout << *(dynamic_cast<Eletronico*>(item)) << endl;
            else  //Se for um livro audiobook
                cout << *(dynamic_cast<Audiobook*>(item)) << endl;
        }
    //Se for o arquivo
    else{
        ofstream arq("saida.txt", ios::out);
        for(auto item : livros){
            if(typeid(*item) == typeid(class Impresso)) //Se for um livro impresso
                arq << *(dynamic_cast<Impresso*>(item)) << endl;

            else if(typeid(*item) == typeid(class Eletronico)) //Se for um livro eletronico
                arq << *(dynamic_cast<Eletronico*>(item)) << endl;
            else //Se for um livro audiobook
                arq << *(dynamic_cast<Audiobook*>(item)) << endl;
        }
    }
}

//K: pesquisa livros por keywords e retorna a quantidade de livros encontrados.
int keywordAmount(vector<Livro*> livros, string keyword){
    vector<Livro*> item; //vector de temporario livros.

    //pesquisa em cada livro.
    for(auto itr : livros){
        //pesquisa cada keyword.
        for(auto itr2 : itr->getKeywords()){
            if(itr2 == keyword)
                item.push_back(itr); //adciona o livro a colecao de livros.
        }
    }
    return item.size();
}

//L: Função que altera o formato dos idiomas
vector<Livro*> altIdioma(vector<Livro*> livros){
    //Vasculha os objs e altera o idioma
    for ( auto item : livros){
        if(item->getIdiomaOriginal() == "Ingles") item->setIdiomaOriginal("ENG");
        if(item->getIdiomaOriginal() == "Espanhol") item->setIdiomaOriginal("ESP");
        if(item->getIdiomaOriginal() == "Frances") item->setIdiomaOriginal("FRS");
        if(item->getIdiomaOriginal() == "Portugues") item->setIdiomaOriginal("POT");

    }

    return livros;
}