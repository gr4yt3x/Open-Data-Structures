// Existe um metodo melhor (in-place) utilizando "Juggling Algorithm"; rotacionando em três etapas; 
#include <iostream>
#include <vector>

template <typename T> // O type T permite que a classe seja dinamica, e possa utilizar mais de um tipo de dado; 
class MyClass {
public:
    std::vector<T> rotate(std::vector<T> a, int r) {
        std::vector<T> b(a.size());

        for (int i = 0; i < a.size(); ++i) {
            b[(i + r) % a.size()] = a[i];
        }

        return b;
    }
};

int main() {
    MyClass<char> myClass; // ao chamar a classe declara o tipo dela;

    //std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<char> a = {'a','b','c','d','e'}; 

    a = myClass.rotate(a, 3);

    // Print the rotated array
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}
