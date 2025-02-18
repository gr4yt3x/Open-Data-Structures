/* 
* Meus colegas fazem viagens a trabalho para outro país. Devemos achar o número de dias que nossa companhia é representada em um país. Todo dia em que um ou mais colegas estão presentes no país é um dia em que a companhia é representada. Um dia particular não pode contar como mais de um dia.
*
* Escreva uma função que recebe uma lista de pares e retorna o número de dias em que a companhia esteve representada no outro país. O primeiro número do par é o dia de chegada e o segundo número do par é o dia de partida de alguém que viajou. Por exemplo, 1 de janeiro é o número 1 e 31 de dezembro é 365.
* Exemplo:
*
* days_represented([(10, 17), (200, 207)])
*
* Retorna 16 porque há duas viagens de 8 dias, que somando dá 16.
*/

#include <iostream>
#include <vector>

int days_represented (std::vector<std::pair<int,int>> x) {
  int sum = 0;

  for (auto i: x) {
    sum += (i.second - i.first) + 1;
  }

  return sum;
}

int main () {
  int days = days_represented({{10,17}, {200, 207}}); // 16

  std::cout << days;
}
