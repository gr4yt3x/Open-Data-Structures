#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    std::queue<string> lista;
    std::ifstream ifs;

    ifs.open("./bigfile150lines.txt", std::ifstream::in);

    string linha;
    int contadorlinhas = 0;

    if (ifs.is_open()) {
            while (getline(ifs, linha)) {
		if (contadorlinhas >= 43) {
		  lista.pop();

		  if(linha.length() == 0) {
		    cout << lista.front();
		  }
		}

	        lista.push(linha);
		++contadorlinhas;
            }

	    ifs.close();
    }

    return 0;
}
