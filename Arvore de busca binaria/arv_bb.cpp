/* arv_bb_func.cpp: Implementa��o das fun��es da �rvore Bin�ria de Busca.
 Na �rvore bin�ria de busca, tem-se a propriedade fundamental de que para
 qq. n� da �rvore, os valores dos n�s � sua esquerda s�o menores ou iguais que
 o valor armazenado no n� e os valores dos n�s � sua direita s�o maiores.
 
 Nesta implementa��o, usa-se uma classe gabarito auxiliar (classe no), � qual os programas
 que usam a classe n�o t�m acesso. A classe arv_bb � definida como um ponteiro para o
 n� raiz. Todas as fun��es da classe arv_bin s�o implementadas por meio de chamadas
 aos m�todos da classe no.
 */

#include <iostream>
#include "arv_bb.h"

using namespace std;

/* Declara��o da classe no */
class no{
    int val;       /* Valor armazenado */
    no *esq, *dir; /* Ponteiros para sub-�rvores */
    
public:
    no(int valor);  /* Cria um n� com o valor fornecido e esq=dir=NULL */
    ~no(void);      /* Destruidor: apaga todos os n�s � equerda e � direita */
    
    no *insere_no(const int& valor);
    /* Insere um n� como "descendente", contendo o valor fornecido.
     Retorna um ponteiro para o n� inserido.
     */
    
    no *pert(const int& valor);
    /* Informa se h� um n� com o valor "val" como "descendente".
     Caso haja, retorna um ponteiro para esse n�. Caso contr�rio,
     retorna NULL. */
    
    bool remove_no(const int& valor,no * &ref_no);
    /* Remove o n� com o valor "val" da "�rvore" a
     partir do n� para o qual est� sendo chamada a fun��o.
     Obs: "ref_no" � o ponteiro que referencia o n� para o qual est� sendo
     chamada a fun��o, o qual pode ter que ser modificado.
			  Retorna NULL se o valor n�o pertencer � "�rvore".
		   */
    void mostra(void) const; /* Mostra o conte�do da �rvore a partir do n�,
                              em ordem sim�trica */
};


/* Cria um n� com o valor fornecido e esq=dir=NULL */
no::no(int valor){
    val = valor;
    esq = dir = NULL;
}

/* Destruidor: apaga todos os n�s � equerda e � direita */
no::~no(void){
    delete esq;
    delete dir;
}

/* Informa se h� um n� com o valor "val" como "descendente".
 Caso haja, retorna um ponteiro para esse n�. Caso contr�rio,
 retorna NULL. */
no *no::pert(const int& valor){
    
    if (valor == val) /* Se � igual, pertence e o n� � a raiz. */
        return this;
    if ((valor > val) && (dir != NULL)) /* Se � maior e tem sub-�rvore � direita,
                                         faz chamada recursiva. */
        return dir->pert(valor);
    if ((valor < val) && (esq != NULL)) /* Se n�o � maior e n�o tem sub-�rvore � direita,
                                         faz chamada recursiva. */
        return esq->pert(valor);
    return NULL;  /* Caso n�o perten�a, retorna NULL */
}

/* Insere um n� como "descendente", contendo o valor fornecido.
 Retorna um ponteiro para o n� inserido.
 Obs: insere duplicatas.
 */
no * no::insere_no(const int& valor){
    if (valor>val)  /* Se maior, insere � direita */
        if (dir == NULL)  /* Se chegou a uma folha, faz a inser��o */
            return dir = new no(valor);
        else  /* Se n�o chegou a uma folha, faz chamada recursiva */
            return dir->insere_no(valor);
        else /* Se n�o � maior, insere � esquerda */
            if (esq == NULL) /* Se chegou a uma folha, faz a inser��o */
                return esq = new no(valor);
            else  /* Se n�o chegou a uma folha, faz chamada recursiva */
                return esq->insere_no(valor);
}

/* Remove o n� com o valor "val" da "�rvore" a partir do n� para o qual est� sendo
 chamada a fun��o.  Obs: "ref_no" � o ponteiro que referencia o n� para o qual
 est� sendo chamada a fun��o, o qual pode ter que ser modificado.
 Retorna false se o valor n�o pertencer � "�rvore".
 */
bool no::remove_no(const int& valor, no * &ref_no){
    no	 *subst, /* Candidato a substituto do n� a remover */
    *ant;   /* Pai do candidato a substituto do n� a remover */
    
    if (valor == val)  /* Se valor � igual, achou o n� a remover. */
    {  /*
        Bloco que faz a remo��o. 2 casos previstos:
        - N� a remover n�o tem n�s � direita: basta substituir o
        n� pelo seu n� � esquerda.
        - N� a remover possui n�s � direita: descobrir o menor n�
        � direita, para que ele seja o substituto.
        */
        if (dir == NULL) /* Remo��o qdo. n�o h� nada � direita */
            ref_no = esq;
        else
        {   /* Remo��o qdo. h� n�s � direita. Inicialmente faz a busca do menor n� �
             direita. A vari�vel "ant" � inicializada com NULL. Se o seu valor n�o
             for modificado, o substituto � o filho � direita do n� a remover. */
            ant = NULL;
            subst = dir;
            while(subst->esq!=NULL){
                ant = subst;
                subst = subst->esq;
            }
            if (ant != NULL) /* Qdo. elem. imediatamente � direita n�o � o substituto,
                              � necess�rio fazer com que o seu pai aponte para o seu filho
                              � direita e que o seu novo filho � direita passe a ser o filho
                              � direita do n� removido.
                              */
            {
                ant->esq = subst->dir;
                subst->dir = dir;
            }
            ref_no = subst;  /* Coloca��o do n� substituto no local do removido. */
            subst->esq = esq; /* Atualiza��o do filho � esquerda. */
        }
        esq = NULL;  /* Antes de apagar o n�, � necess�rio definir os ponteiros esq=dir=NULL,
                      para que os n�s que eram apontados n�o sejam tamb�m removidos. */
        dir = NULL;
        delete this;
        return true;
    }
    if ((valor>val) && (dir!=NULL))  /* Chamada recursiva, caso o n� a remover possa estar � direita. */
        return dir->remove_no(valor,dir);
    if ((valor<val) && (esq!=NULL))  /* Chamada recursiva, caso o n� a remover possa estar � esquerda. */
        return esq->remove_no(valor,esq);
    return false;
}

/* Mostra o conte�do da �rvore a partir do n�, em ordem sim�trica*/
void no::mostra() const{
    cout << "[";
    if (esq != NULL)
        esq->mostra();
    cout << "|" << val << "|";
    if (dir != NULL)
        dir->mostra();
    cout << "]";
}

/**********************************************/
/* Implementa��o dos m�todos da classe arv_bb */
/**********************************************/

/* Construtor: �rvore inicialmente vazia (raiz==NULL) */
arv_bb::arv_bb(void) {
    raiz = NULL;
}

/* Destruidor: Apaga o n� raiz, o que leva � remo��o de todos os outros. */
arv_bb::~arv_bb(void){ delete raiz; }

/* Insere um valor a partir do n� raiz. */
void arv_bb::ins(const int& valor){
    if (raiz == NULL)
        raiz = new no(valor);
    else
        raiz->insere_no(valor);
}

/* Busca um valor a partir do n� raiz.
 Se a �rvore est� vazia,m retorna false.
 */
bool arv_bb::busca(const int& valor) const {
    if (raiz == NULL) return false;
    return (raiz->pert(valor)!=NULL);
}

/* Busca um valor a partir do n� raiz.
 Se a �rvore est� vazia, retorna false.
 */
bool arv_bb::rem(const int& valor){
    if (raiz == NULL) return false;
    return raiz->remove_no(valor,raiz);
}

/* Imprime o cont�udo da �rvore, em ordem sim�trica, a partir da raiz.
 Se a �rvore estiver vazia, comunica esse fato.
 */
void arv_bb::mostra(void) const{
    if (raiz == NULL) 
        cout << "Arvore vazia ";
    else
        raiz->mostra();
    cout << endl;
}

