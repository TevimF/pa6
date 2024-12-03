#include "../include/heap.hpp"
#include <iostream> 

// esse é um min heap, ou seja, o pai é sempre menor que os filhos
Heap::Heap(int maxsize){ tamanho = 0;data = new int[maxsize]; }

Heap::~Heap() { delete[] data; }

void Heap::Inserir(int x) {
  if (tamanho == 0) {
    data[0] = x;
  } else {
    data[tamanho] = x;
    // adiciona o elemento na ultima posicao e faz o heapify para cima
    HeapifyPorCima(tamanho);
  }
  tamanho++;
}

int Heap::Remover() {
  int aux = data[0];
  data[0] = data[tamanho - 1];
  tamanho--;
  // remove o primeiro elemento e faz o heapify para baixo
  HeapifyPorBaixo(0);
  return aux;
}

bool Heap::Vazio() { return tamanho == 0; }

// [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// 0 é a raiz, 1 e 2 são os filhos de 0, 3 e 4 são os filhos de 1, 5 e 6 são os filhos de 2

int Heap::GetAncestral(int posicao) { return (posicao - 1) / 2; }

int Heap::GetSucessorEsq(int posicao) { return 2 * posicao + 1; }

int Heap::GetSucessorDir(int posicao) { return 2 * posicao + 2; }

void Heap::HeapifyPorBaixo(int posicao) {
  int esq = GetSucessorEsq(posicao);
  int dir = GetSucessorDir(posicao);
  int menor = posicao;

  // se o filho da esquerda for menor que o pai, menor recebe o filho da esquerda
  if (esq < tamanho && data[esq] < data[menor]) {
    menor = esq;
  }
  // se o filho da direita for menor que o pai, menor recebe o filho da direita
  if (dir < tamanho && data[dir] < data[menor]) {
    menor = dir;
  }

  if (menor != posicao) {
    std::swap(data[posicao], data[menor]);
    HeapifyPorBaixo(menor);
  }
}

void Heap::HeapifyPorCima(int posicao) {
  int ancestral = GetAncestral(posicao);

  // se o pai for maior que o filho, troca os valores
  if (ancestral >= 0 && data[posicao] < data[ancestral]) {
    std::swap(data[posicao], data[ancestral]);
    HeapifyPorCima(ancestral);
  }
}
