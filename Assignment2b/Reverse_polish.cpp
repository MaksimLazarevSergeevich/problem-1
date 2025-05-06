/*Maksim Lazarev st128707@student.spbu.ru
second tusk b*/

#include <iostream>
#include <string>
#include <sstream>
/* Определение, это в том числе объявление, поэтому в одном файле иметь дополнительное
 * объявление не нужно */
double calculate(double a, double b, std::string opers);

double calculate(double a, double b, std::string opers) {
  if (opers == "*") {
    return a * b;
  }else if(opers == "/") {
    return a / b;
  }else if(opers == "+") {
    return a + b;
  }else {
    // Минус бывает еще унарным
    return a - b;
  }
}


int main() {
  std::cout << "Enter the expression as reverse polish notation, separated by spaces:" << '\n';

  std::string input;
  std::string input_unstream;
  getline(std::cin, input_unstream);
  std::stringstream ss(input_unstream);
  /* А Если будет большк 50 значений? */
  double* arr = new double [50];
  double* q = &arr[0] - 1;
  /* Хочется стек отдельным классом */
  while (getline(ss, input, ' ')) {
    if (input == "+" || input == "-" || input == "*" || input == "/") {
      double result = calculate(*(q - 1), *q, input);
      q -= 1;
      *q = result;
    }else {
      q += 1;
      *q = std::stod(input);
    }
  }
  std::cout << "Answer: " << *q << '\n';
  delete [] arr;
}
