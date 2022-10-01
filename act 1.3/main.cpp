/*
Ingrid González A01641116
Esteban Madrigal A01641409
Jorge Wolburg A01640826

Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void swap(vector<vector<string>> &vec, int i, int j) { // Funcion para intercambiar elementos dentro de un vector
  vector<string> tmp;
  tmp = vec[i];
  vec[i] = vec[j];
  vec[j] = tmp;
}

string numMonth(vector<string> v0) { // Jerarquia de valores con respecto a los meses para hacer comparaciones
  if (v0[0] == "Jan") {
    return "01"; // Notese el 0 para mantener siempre la misma longitud del
                 // string
  } else if (v0[0] == "Feb") {
    return "02";
  } else if (v0[0] == "Mar") {
    return "03";
  } else if (v0[0] == "Apr") {
    return "04";
  } else if (v0[0] == "May") {
    return "05";
  } else if (v0[0] == "Jun") {
    return "06";
  } else if (v0[0] == "Jul") {
    return "07";
  } else if (v0[0] == "Aug") {
    return "08";
  } else if (v0[0] == "Sep") {
    return "09";
  } else if (v0[0] == "Oct") {
    return "10";
  } else if (v0[0] == "Nov") {
    return "11";
  } else {
    return "12";
  }
}
string numMonth2(string date) { // Jerarquia de valores con respecto a los meses para hacer comparaciones
  if (date == "Jan") {
    return "01"; // Notese el 0 para mantener siempre la misma longitud del string
  } else if (date == "Feb") {
    return "02";
  } else if (date == "Mar") {
    return "03";
  } else if (date == "Apr") {
    return "04";
  } else if (date == "May") {
    return "05";
  } else if (date == "Jun") {
    return "06";
  } else if (date == "Jul") {
    return "07";
  } else if (date == "Aug") {
    return "08";
  } else if (date == "Sep") {
    return "09";
  } else if (date == "Oct") {
    return "10";
  } else if (date == "Nov") {
    return "11";
  } else {
    return "12";
  }
}

string strHour(vector<string> v0) { // Se eliminan los puntos para tener un string comparable
  return v0[2].substr(0, 2) + v0[2].substr(3, 2) + v0[2].substr(6, 2);
}

string cDay2(string day) { // Se agrega un "0" a los elementos que solo tienen un caracter y tener siempre el mismo tamano de string
  if (day.size() > 1) {
    return day;
  } else {
    return "0" + day;
  }
}

string cDay(vector<string> v0) { // Se agrega un "0" a los elementos que solo tienen un caracter y tener siempre el mismo tamano de string
  if (v0[1].size() > 1) {
    return v0[1];
  } else {
    return "0" + v0[1];
  }
}

int wholeDate(vector<string> v0) { // Se juntan el mes, dia y hora en un solo string. Posteriormente se convierte en un entero comparable
  string month, day, hour;
  month = numMonth(v0);
  day = cDay(v0);
  hour = strHour(v0);

  string conc = month + day + hour;
  int fecha = stoi(conc); // String 2 integer

  return fecha;
}

int wholeDate2(vector<string> v0) { // Se juntan el mes, dia y hora en un solo string. Posteriormente se convierte en un entero comparable
  string month, day;
  month = numMonth(v0);
  day = cDay(v0);

  string conc = month + day;
  int fecha = stoi(conc); // String 2 integer

  return fecha;
}

int partir(vector<vector<string>> &v, int first, int last) { // Particiona el vector
  long long pivot =
      wholeDate(v[first]); // Se utiliza el entero formado como dato
  int x = first + 1;

  for (int i = x; i <= last; i++) { // Recorre y si la fecha es menor al pivote se intercambia con x + 1
    long long date = wholeDate(v[i]);
    if (date < pivot) {
      swap(v, x++, i);
    }
  }
  swap(v, first, x - 1); // El pivote regresa a su posicion final
  return x - 1; // La funcion regresa la posicion del pivote para usar recursividad
}

void quickSort(vector<vector<string>> &v, int first, int last) {
  if (first < last) {
    int pos = partir(v, first, last);
    quickSort(v, first, pos - 1);
    quickSort(v, pos + 1, last);
  }
}

void quickSort(vector<vector<string>> &v) { // La complejidad de este algoritmo es de O(n^2)
  quickSort(v, 0, v.size() - 1);
}

string regString(vector<string> v0) { // Se agrega la linea de la razon de la falla al resto de la linea, completando la linea del registro
  string complete;
  for (int i = 0; i < v0.size() - 1; i++) {
    complete += v0[i] + " ";
  }
  complete = complete + v0[4];
  return complete;
}

int secSearch(vector<vector<string>> v, int date) { // La complejidad de este algoritmo es de O(n)
  for (int i = 0; i < v.size(); i++) {
    if (wholeDate2(v[i]) == date) {
      return i;
    }
  }
  return -1;
}

int cSearchDate(string x, string y) { // Funcion para convertir los datos del usuario a un entero comparable
  string month, day;
  month = numMonth2(y);
  day = cDay2(x);

  string conc = month + day;
  int fecha = stoi(conc); // String 2 integer

  return fecha;
}

int main() {
  vector<vector<string>> v;
  vector<string> v0;
  string line, month, day, hour, ip, reas;
  ifstream file("bitacora.txt");
  int size, n;
  bool cycle = 1;

  if (file.is_open()) {
    while (getline(file, line)) {
      v0.clear();

      stringstream st(line);
      getline(st, month, ' ');
      v0.push_back(month);
      getline(st, day, ' ');
      v0.push_back(day);
      getline(st, hour, ' ');
      v0.push_back(hour);
      getline(st, ip, ' ');
      v0.push_back(ip);
      getline(st, reas, '\n');
      v0.push_back(reas);
      v[size];
      v.push_back(v0);
      size++;
    }
    file.close();
    quickSort(v); // Se llama a la funcion de ordenamiento

    ofstream salida("bitacoraOrdenada1.3-eq2.txt");
    if (salida.is_open()) {
      for (int i = 0; i < v.size(); i++) {
        salida << regString(v[i]) << "\n"; // Se imprime la linea con todos los elementos y se hace un salto de linea
      }
      salida.close();
      cout << "La bitacora ordenada ha sido guardada en el archivo \"bitacoraOrdenada1.3-eq2.txt\"" << endl;
    } else {
      cout << "Error abriendo el archivo" << endl;
    }
  } else {
    cout << "El archivo no fue encontrado" << endl;
  }
  while (cycle == 1) {
    cout << "\n-----Busqueda de Logs------" << endl;
    cout << " " << endl;
    cout << "Ingresa una fecha que se usara como el inicio para la busqueda en el siguiente formato: MMM ##" << endl;

    string iDay, iMonth;
    cout << "Ingresar fecha de inicio: " << endl;
    cin >> iMonth >> iDay;
    int cIDate = cSearchDate(iDay, iMonth);

    cout << "\nIngresa una fecha que se usara como el final para la busqueda en el siguiente formato: MMM ##" << endl;

    string iDay2, iMonth2;
    cout << "Ingresar fecha final: " << endl;
    cin >> iMonth2 >> iDay2;
    int cIDate2 = cSearchDate(iDay2, iMonth2);
    cIDate2++;

    int sStart = secSearch(v, cIDate);
    cout << sStart << endl;
    int sFin = secSearch(v, cIDate2);
    cout << sFin << endl;

    cout << "\nSe encontraron los siguientes logs dentro de los limites establecidos: " << endl;

    for (int i = sStart; i < sFin; i++) {
      cout << regString(v[i]) << endl;
    }
    cout << "\nPara realizar otra busqueda teclee 1, para detener la busqueda presione 0" << endl;
    cin >> cycle;
  }
  cout << "\nVuelva pronto!" << endl;
}