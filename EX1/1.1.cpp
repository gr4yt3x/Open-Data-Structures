#include <fstream>
#include<iostream>
#include<string>
#include <stack>
using namespace std;

int main (){
    std::stack<string> lista; 
    std::ifstream ifs;

    ifs.open("./file.txt", std::ifstream::in);

    string linha;
    
    // Open file and save each line at <stack>lista; 
    if (ifs.is_open()) {
      while (getline(ifs, linha)){
        lista.push(linha);
      }

      ifs.close();
    }

    //return the value of the <stack>lista
    while(!lista.empty()) {
      cout << lista.top() << endl; 
      lista.pop();
    }

    return 0;
}
