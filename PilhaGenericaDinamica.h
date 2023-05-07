#include <iostream>

using namespace std;

template<typename T, int MAX>

struct PilhaEstaticaGenerica
{
    int cardinalidade;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(PilhaEstaticaGenerica<T, MAX> &pilha)
{
    pilha.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia (PilhaEstaticaGenerica<T, MAX> pilha)
{
    return pilha.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (PilhaEstaticaGenerica<T, MAX> pilha)
{
    return pilha.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroDeElementos (PilhaEstaticaGenerica<T, MAX> pilha)
{
    return pilha.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (PilhaEstaticaGenerica<T, MAX> pilha, T elemento)
{
    for (int i = 0; i < pilha.cardinalidade; i++)
        if (pilha.elementos[i] == elemento)
            return true;
            return false;
}

template<typename T, int MAX>
int existePosicao (PilhaEstaticaGenerica<T, MAX> pilha, int posicao)
{
    return (posicao >= 1) && (posicao <= pilha.cardinalidade);
}

template<typename T, int MAX>
T umElemento (PilhaEstaticaGenerica<T, MAX> pilha, int posicao)
{
    if(posicao < 1 || posicao > pilha.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    return pilha.elementos[pilha.cardinalidade - posicao];
}

template<typename T, int MAX>
int posicao (PilhaEstaticaGenerica<T, MAX> pilha, T elemento)
{
    if (!existeElemento(pilha, elemento))
    {
        throw "ELEMENTO NAO ESTA NA pilha";
    }
    for (int i = 0; i < pilha.cardinalidade; i++)
        if (pilha.elementos[i] == elemento)
            return pilha.cardinalidade - i;
}

template<typename T, int MAX>
T topo (PilhaEstaticaGenerica<T, MAX> pilha)
{
    return pilha.elementos[pilha.cardinalidade - 1];
}

template<typename T, int MAX>
void insere (PilhaEstaticaGenerica<T, MAX> &pilha, T elemento)
{
    if(pilha.cardinalidade == MAX)
    {
        throw "OVERFLOW";
    }
    pilha.elementos[pilha.cardinalidade] = elemento;
    pilha.cardinalidade++;
}

template<typename T, int MAX>
void retira (PilhaEstaticaGenerica<T, MAX> &pilha)
{
    if(pilha.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    pilha.cardinalidade--;
}

template<typename T, int MAX>
void mostra (PilhaEstaticaGenerica<T, MAX> pilha)
{
  for (int i = 0; i < pilha.cardinalidade; i++)
    cout << pilha.elementos[i] << " ";
  cout << endl;
}