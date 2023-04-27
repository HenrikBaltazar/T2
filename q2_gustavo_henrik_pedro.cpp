#include <iostream>
#include <string>

using namespace std;

int main(){

    string comando = " ";
    float valor;
    //Pilha expressao;
    //expressao.cria;

    cout << "Editor de expressao aritmetica" << endl;
    cout << "digite 'HELP' para visualizar a lista de comandos disponiveis"<<endl;
    do{
        cout <<endl<< "# ";
        cin >> comando;
        if(comando == "FIM" || comando == "fim"){
            cin.ignore();
            cout << "Tem certeza que deseja sair do editor? [S/N]" << endl;
            char c = cin.get();
            if(c == 'S' || c == 's')
                comando = "FIM";
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
            //consultar se a pilha expressao esta vazia
            //se sim inicia com zero
            //se nao da erro de pilha ja existe
        }else if (comando == "ZERA" || comando == "zera"){
            //pergunta se tem certeza
            //se sim remove todos os elementos da pilha e reinicia com zero
        }else if (comando == "SOMA" || comando == "soma"){
            cout << "(SOMA) # ";
            cin >> valor;
            //pega o topo da pilha, soma com valor e insere o resultado na pilha novamente
        }else if (comando == "SUBTRAI" || comando == "subtrai"){
            cout << "(SUBTRAI) # ";
            cin >> valor;
            //pega o topo da pilha, subtrai com valor e insere o resultado na pilha novamente
        }else if (comando == "MULTIPLICA" || comando == "multiplica"){
            cout << "(MULTIPLICA) # ";
            cin >> valor;
            //pega o topo da pilha, multiplica com valor e insere o resultado na pilha novamente
        }else if (comando == "DIVIDE" || comando == "divide"){
            cout << "(DIVIDE) # ";
            cin >> valor;
            //pega o topo da pilha, divide com valor e insere o resultado na pilha novamente
        }else if (comando == "PARCELAS" || comando == "parcelas"){
            //exibe toda a pilha
        }else if (comando == "IGUAL" || comando == "igual"){
            //exibe apenas o topo da pilha
        }
        
    }while(comando != "FIM");

    return 0;
}