#include <fstream>
#include<iostream>
#include<string>
#include <stack>
using namespace std;

int main (){
    std::stack<string> lista; 
    std::ifstream ifs;

    ifs.open("./bigfile.txt", std::ifstream::in);

    string linha;
    int contadorlinhas = 1;

    if (ifs.is_open()) {
      while(true){
        
	while (contadorlinhas <= 50 && getline(ifs,linha)){
	  lista.push(linha);
	  contadorlinhas++;
	}
        
	while (!lista.empty()) {
          cout << lista.top() << endl;
	  lista.pop();
	  contadorlinhas--; 
        }  
        
	//end of loop
        if(ifs.eof()){
	  break;
        }
      }
      ifs.close();
    }

    return 0;
}
