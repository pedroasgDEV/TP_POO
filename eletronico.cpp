//#include "eletronico.h"
#include "classes.h"

Eletronico::Eletronico(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
                    const string& idi, const list<string>& key, string url, string format):
                    Livro(esc, t, cap, ano, idi, key){ setUrl(url); setformatoArquivo(format); }
Eletronico::~Eletronico(){}

//URL
string Eletronico::getUrl(){
    return url;
}

void Eletronico::setUrl(string url){
    this->url = url;
}

//Formato do Arquivo
string Eletronico::getformatoArquivo(){
    return formatoArquivo;
}

void Eletronico::setformatoArquivo(string format){
    formatoArquivo = format;
}
