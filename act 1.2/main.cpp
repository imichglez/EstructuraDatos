#include <iostream>
#include <vector>
using namespace std;

/*
Ingrid González A01641116
Aplicación en donde dado n números de entrada que son almacenados en un
vector<int> realice funciones de ordenamiento.
*/

int compara; // variable de almacenamiento de comparaciones

void swap(int i, int j, vector<int> &v1) { // para realizar intercambios
  int aux = v1[i];
  v1[i] = v1[j];
  v1[j] = aux;
}

void disp(vector<int> &v1) { // imprime los métodos a comprobar
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << ",";
  }
  cout << endl;
}

int ordenaInsercion(vector<int> &v1) { // El ordenamiento Insercion tiene una complejidad O(n^2)
  int comparaIns = 0;
  for (int i = 1; i < v1.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      comparaIns++;
      if (v1[j + 1] < v1[j]) {
        comparaIns++;
        swap(j, j + 1, v1);
      } else {
        comparaIns++;
        break;
      }
      comparaIns++;
    }
  }
  comparaIns++;
  return comparaIns;
}

int ordenaBurbuja(vector<int> &v2) { // El ordenamiento Burbuja tiene una complejidad O(n^2)
  int comparaBurb = 0;
  bool ord = false;
  for (int i = 0; i < v2.size()-1 && !ord; i++) {
    ord = true;
    for (int j = 0; j < v2.size()-1-i; j++) {
      comparaBurb++;
      if (v2[j] > v2[j + 1]) {
        swap(j, j + 1, v2);
        ord = false;
      }
    }
  }
  return comparaBurb;
}

/*
FUENTE CONSULTADA:
de la Cueva , V. M., González, L. H., & Salinas, E. G. (2020). Estructuras de
datos y algoritmos fundamentales (Primera). Editorial Digital Tecnológico de
Monterrey. Pág.105. Merge Sort.
*/

void mezcla(vector<int> &v3, int inicio, int fin, int &compara) { // Se realiza una mezcla de los datos ingresados
  int pm = (inicio + fin) / 2;
  int j = inicio, k = pm + 1, size = fin - inicio + 1;
  int dTmp[size];

  for (int i = 0; i < size; i++) {
    if (j <= pm && k <= fin) {
      compara++;
      if (v3[j] < v3[k]) {
        dTmp[i] = v3[j++];
      } else {
        dTmp[i] = v3[k++];
      }
    } else if (j <= pm) {
      dTmp[i] = v3[j++];
    } else {
      dTmp[i] = v3[k++];
    }
  }

  for (int m = 0; m < size; m++) {
    v3[inicio + m] = dTmp[m];
  }
}

void ordenaMerge(vector<int> &v3, int ini, int fin, int &compara) {
  if (ini < fin) {
    int pm = (ini + fin) / 2; // se calcula el punto medio (centro)
    ordenaMerge(v3, ini, pm, compara);
    ordenaMerge(v3, pm + 1, fin, compara);
    mezcla(v3, ini, fin, compara);
  }
}

int ordenaMerge(
    vector<int> &v3) { // El ordena Merge tiene una complejidad O(n log2(n))
  int compara = 0;
  ordenaMerge(v3, 0, v3.size() - 1, compara);
  return compara;
}

int busqBinaria(
    vector<int> &v1, int dato,
    int &cantBB) { // La busqueda Binaria tiene una complejidad O(log_2(n))
  int prom;
  int min = 0;
  int max = v1.size() - 1;
  while (min <= max) {
    prom = (min + max) / 2;
    if (dato == v1[prom]) {
      cantBB++;
      return prom;
    } else if (dato < v1[prom]) {
      cantBB++;
      max = prom - 1;
    } else {
      cantBB++;
      min = prom + 1;
    }
  }
  return -1;
}

int busqSecuencial(
    vector<int> &v1, int valor,
    int &cantBS) { // La busqueda Secuencial tienen una complejidad O(n)
  for (int i = 0; i < v1.size(); i++) {
    cantBS++;
    if (v1[i] == valor) {
      return i;
    }
  }
  return -1;
}

int main() {
  vector<int> v1, v2, v3;
  int n, dato;
  cin >> n; // datos de entrada al vector
  for (int i = 0; i < n; i++) {
    cin >> dato;
    v1.push_back(dato);
    v2.push_back(dato);
    v3.push_back(dato);
  }
  cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " "
       << ordenaMerge(v3) << endl;
  int q, pos;
  int cantBS, cantBB;
  cin >> q; // cantidad de números a buscar
  for (int i = 0; i < q; i++) {
    cantBS = 0;
    cantBB = 0;
    cin >> dato;
    pos = busqSecuencial(v1, dato, cantBS);
    pos = busqBinaria(v1, dato, cantBB);
    cout << pos << " " << cantBS << " " << cantBB << endl;
  }
}
