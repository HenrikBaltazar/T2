#include <iostream>
#include <cstdlib> // atoi, atof
#include <string>  // string
#include <cctype>  // isdigit
#include "Pilha.h"

using namespace std;
int main()
{
    string info;
    float n;
    int x;
    unsigned int i, ponto;
    bool validada;

    // int
    do
    {
        validada = true; // p/ ver se tem erro, considera valida inicialmente
        cout << "Numero int: ";
        getline(cin, info);
        if (info == "") // se for string vazia
            validada = false;
        else if (!isdigit(info.at(0)) && info.at(0) != '-') // se não for digito/sinal
            validada = false;
        else
            for (i = 1; i < info.length(); i++) // “varre” posicao a posicao
                if (!isdigit(info.at(i)))       // se não for digito
                    validada = false;
        if (!validada)
            cout << "Numero invalido, digite novamente." << endl;
    } while (!validada);
    x = atoi(info.c_str());          // faz conversao pq entrada foi correta
    cout << "Inteiro:" << x << endl; // mostra valor

    //float
    do
    {
        validada = true;
        ponto = 0;
        cout << "Numero float: ";
        getline(cin, info);
        if (info == "") // se for string vazia
            validada = false;
        else if (!isdigit(info.at(0)) && info.at(0) != '-') // se não for digito/sinal
            validada = false;
        else
            for (i = 1; i < info.length(); i++) // “varre” posicao a posicao
                if (!isdigit(info.at(i)))
                { // se não for digito
                    if (isdigit(info.at(i - 1)) && info.at(i) == '.' && ponto == 0)
                        // verifica se eh ponto com um digito antes
                        ponto++; // permite um ponto apenas
                    else
                        validada = false;
                }
        if (!validada)
            cout << "Numero float invalido, digite novamente." << endl;
    } while (!validada);
    n = atof(info.c_str());
    cout << "Float: " << n << endl;
    return 1;
}