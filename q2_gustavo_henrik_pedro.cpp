#include <iostream>
#include <string>
#include <cstdlib> // atoi, atof
#include <cctype>  // isdigit
#include "Pilha.h"

using namespace std;

float pegaValor(string comando){
    int posIni = 0, posFim = 0;
    string numStr = "";
    bool validada;
    unsigned int i, ponto;

    posIni = comando.find("(");
    posFim = comando.find(")");
    numStr = comando.substr(posIni+1, posFim-posIni-1);
    validada = true;
    ponto = 0;
    int lenght=numStr.length();
    if (numStr == "") // se for string vazia
        validada = false;
    else
        for (i = 0; i < numStr.length(); i++) // “varre” posicao a posicao
            if (!isdigit(numStr.at(i)))
            { // se não for digito
                if (isdigit(numStr.at(i)) && numStr.at(i+1) == '.' && ponto == 0)
                    // verifica se eh ponto com um digito antes
                    ponto++; // permite um ponto apenas
                else
                    validada = false;
            }
    if (!validada)
        return -1;
    else
        return stoi(numStr);
}

int main(){
    string comando = "";
    float valor;
    bool erroDeSintaxe = false, inicio = false;

    Pilha<float> expressao;

    cout << "Editor de expressao aritmetica" << endl;
    cout << "digite 'HELP' para visualizar a lista de comandos disponiveis"<<endl;
    do{
        comando = "";
        cout <<endl<< "# ";
        getline(cin,comando);
        if(comando == "FIM" || comando == "fim"){
            cout << "Tem certeza que deseja sair do editor? [S/N]" << endl;
            char c = cin.get();
            if(c == 'S' || c == 's')
                comando = "FIM";
            else
                comando = "";
        }else if(comando == "HELP" || comando == "help"){
            cout << "INICIO:.............inicializa o programa" << endl;
            cout << "ZERA:...............reinicializa a expressao aritmetica" << endl;
            cout << "SOMA(valor):........soma (valor) com o valor da expressao aritmetica" << endl;
            cout << "SUBTRAI(valor):.....subtrai (valor) com o valor da expressao aritmetica" << endl;
            cout << "MULTIPLICA(valor):..multiplica (valor) com o valor da expressao aritmetica" << endl;
            cout << "DIVIDE(valor):......divide (valor) com o valor da expressao aritmetica" << endl;
            cout << "PARCELAS:...........exibe os valores de cada parcela da expressao aritmetica" <<endl;
            cout << "IGUAL:..............exibe o resultado da avaliacao da expressao aritmetica "<<endl;
            cout << "FIM:................finaliza o programa"<<endl;
        }else if (comando == "INICIO" || comando == "inicio"){
            if(!inicio){
                cria(expressao);
                inicio = true;
                cout << "Programa iniciado";
            }
            else
                cout << "Programa ja foi iniciada";
        }else if (comando == "ZERA" || comando == "zera"){
            if(inicio){
            cout << "Tem certeza que deseja zerar a expressao? [S/N]" << endl;
            char c = cin.get();
            if(c == 'S' || c == 's')
                destroi(expressao);
                insere(expressao,0.0f);
                cin.ignore();
            } else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando.find("SOMA") != string::npos || comando.find("soma") != string::npos){
            if(inicio){
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos ){
                    valor = pegaValor(comando);
                    if(valor == -1)
                        erroDeSintaxe = true;
                    else{
                        ehVazia(expressao) ? insere(expressao, valor) : insere(expressao, valor+topo(expressao));
                    }
                }else
                    erroDeSintaxe = true;
            }else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando.find("SUBTRAI") != string::npos || comando.find("subtrai") != string::npos){
            if(inicio){
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos ){
                    valor = pegaValor(comando);
                    if(valor == -1)
                        erroDeSintaxe = true;
                    else{
                        ehVazia(expressao) ? insere(expressao, valor*-1) : insere(expressao, topo(expressao)-valor);
                    }
                }else
                    erroDeSintaxe = true;
            }else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando.find("MULTIPLICA") != string::npos || comando.find("multiplica") != string::npos){
            if(inicio){
            if (comando.find("(") != string::npos && comando.find(")")!= string::npos ){
                valor = pegaValor(comando);
                if(valor == -1)
                    erroDeSintaxe = true;
                else{
                    ehVazia(expressao) ? insere(expressao, 0.0f) : insere(expressao, valor*topo(expressao));
                }
            }else
                erroDeSintaxe = true;
            }else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando.find("DIVIDE") != string::npos || comando.find("divide") != string::npos){
            if(inicio){
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos ){
                    valor = pegaValor(comando);
                    if(valor == -1 || valor == 0)
                        erroDeSintaxe = true;
                    else{
                        ehVazia(expressao) ? insere(expressao, 0.0f) : insere(expressao, topo(expressao)/valor);
                    }
                }else
                    erroDeSintaxe = true;
            }else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando == "PARCELAS" || comando == "parcelas"){
            if(inicio){
                if(ehVazia(expressao))
                    cout << "Expressao vazia"<<endl;
                else
                    mostra(expressao);
            }else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else if (comando == "IGUAL" || comando == "igual"){
            if(inicio)
                if(ehVazia(expressao))
                    cout << "Expressao vazia"<<endl;
                else
                    cout << "= " << topo(expressao) <<endl;
            else
                cout << "Programa ainda nao foi iniciado"<<endl;
        }else{
            cout << "COMANDO INVÁLIDO" <<endl;
        }

        if(erroDeSintaxe){
            cout << "ERRO DE SINTAXE, SIGA O FOMATO 'COMANDO(valor)' com valor float sem sinal." << endl << "Digite 'help' para mais informacoes"<<endl;
            erroDeSintaxe = false;
        }


    }while(comando != "FIM");

    return 0;
}
