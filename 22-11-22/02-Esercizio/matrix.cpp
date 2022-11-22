#include <cstdlib>
#include <iostream>
#include <new>
#include <random>

void nomemory() {
  std::cerr << "Memoria esaurita: "
            << "impossibile allocare " << std::endl;
  exit(0);
}

int **alloc_matrix(int d1, int d2) {
  int i, j;
  int **res = new (std::nothrow) int *[d1];

  if (res == NULL)
    nomemory();

  for (i = 0; i < d1; i++) {
    res[i] = new int[d2];
    if (res[i] == NULL)
      nomemory();
  }
  return res;
}

void fill_matrix(int **a, int d1, int d2) {
  for (int i = 0; i < d1; i++)
    for (int j = 0; j < d2; j++)
      a[i][j] = std::rand();
}

void del_matrix(int **a, int d1) {
  for (int i = 0; i < d1; i++) {
    delete[] a[i];
  }
  delete[] a;
}

/**
 * @brif Creare una matrice e riprila di valori random
 * @desciption Creare una matrice dinamica di tipo int con dimensioni a piacere,
 *e assegnare ad ogni cella un valore che si puo ottenere dalla funzione rand()
 *la quale va prima inizalizatta con srand() e poi stampare tutta la matrice.
 **/
int main() {
  const int dim1 = 4;
  const int dim2 = 4;

  std::srand(1);

  int **A;

  A = alloc_matrix(dim1, dim2);
  fill_matrix(A, dim1, dim2);

  for (int i = 0; i < dim1; i++) {
    for (int j = 0; j < dim2; j++) {
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }

  del_matrix(A, dim1);
}
