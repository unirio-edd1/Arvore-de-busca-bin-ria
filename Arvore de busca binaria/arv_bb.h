/* arv_bb.h: Declara��o Classe �rvore Bin�ria de Busca.
 
 Na �rvore bin�ria de busca tem-se a propriedade fundamental de que para
 qq. n� da �rvore, os valores dos n�s � sua esquerda s�o menores que
 valor armazenado no n� e os valores dos n�s � sua direita s�o maiores.
 
 Nesta implementa��o, usa-se uma classe auxiliar (classe no),
 � qual os programas que usam a classe n�o t�m acesso. A classe arv �
 definida como um ponteiro para o n� raiz. Todas as fun��es da classe
 arv_bin s�o implementadas por meio de chamadas aos m�todos da classe no.
 
 */

class no;

class arv_bb {
    
    no *raiz;
    
public:
    arv_bb(void);   /* Cria��o de uma �rvore sem nenhum n� */
    
    ~arv_bb(void);  /* destruidor */
    
    void ins(const int& valor);  /* Insere n� na �rvore */
    
    bool busca(const int& valor) const; /* Verifica se n� pertence � �rvore.
                                         Se pertencer, retorna true, sen�o false.
                                         */
    bool rem(const int& valor);
    /* Remove valor da �rvore, mantendo a propriedade fundamental.
     Se houver remo��o (i.e. o valor pertencer � �rvore),
     retorna true, sen�o false.
     */
    
    void mostra(void) const;
    /* Apresenta o conte�do da �rvore em ordem sim�trica  */
    
};
