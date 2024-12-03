#include <iostream>
#include "../include/heap.hpp"

using namespace std;

int main() {
  int tamanho;
  cin >> tamanho;
  Heap heap(tamanho);
  for (int i = 0; i < tamanho; i++) {
    int x;
    cin >> x;
    heap.Inserir(x);
  }

  while (!heap.Vazio()) {
    cout << heap.Remover() << " ";
  }

  return 0;
}
