//#include "eletronico.h"
#include "classes.h"

//Construtor e destrutor
Eletronico::Eletronico(const vector<string>& esc, const string& t, const vector<string>& cap, const int& ano,
                    const string& idi, const vector<string>& key, string url, string format):
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

//Sobrecarga operador
ostream& operator<<(ostream& out, const Eletronico& ele){

    out << static_cast<Livro>(ele);

    out << " | ";

    //Imprimir o formato do arquivo
    if(ele.formatoArquivo.size() > 10) for(int i = 0; i < 10; i++) 
        out << ele.formatoArquivo[i];
    else out << ele.formatoArquivo;

    return out;
}