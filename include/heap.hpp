#ifndef HEAP_HPP
#define HEAP_HPP

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Alteracoes no arquivo so podem ser feitas quando explicitadas
 */

class Heap{

    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(int x);
        int Remover();

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        int* data;

        /* Funções necessárias para implementar o Heapify recursivo
         * Você pode apagar elas caso decida implementar o Heapify iterativo
         */
        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
};


#endif