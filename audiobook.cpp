//#include "audiobook.h"
#include "classes.h"

Audiobook::Audiobook(const list<string>& esc, const string& t, const list<string>& cap, const int& ano,
                    const string& idi, const list<string>& key, float dur, string format):
                    Livro(esc, t, cap, ano, idi, key){ setDuracao(dur); setformatoAudio(format); }
Audiobook::~Audiobook(){}

//Duraçaõ
float Audiobook::getDuracao(){
    return duracao;
}

void Audiobook::setDuracao(float dur){
    duracao = dur;
}

//Formato do audio
string Audiobook::getformatoAudio(){
    return formatoAudio;
}

void Audiobook::setformatoAudio(string format){
    formatoAudio = format;
}
