/*Maksim Lazarev st128707@student.spbu.ru
second tusk a*/

#include <iostream>
#include <fstream>
#include <filesystem>

 /* В main не должна находиться внутренняя логика программы, это нужно разбивать на функции и классы */
int main() {

  std::ifstream infile("input.txt", std::ios::binary);
  int fileSize = std::filesystem::file_size("input.txt");
  std::cout << "Размер файла: " << fileSize << "\n";
   /* Если у тебя будет много такого, то не сможешь уследить за всей выделенной памятью, поэтому
     * следует научиться пользоваться умными указателями или использовать здесь контейнер из 
     * стандартной библиотеки (например vector, у него есть метод data(), который вернет массив,
     * который можно передать в read) */
  char* buffer = new char[fileSize];
  infile.read(buffer, fileSize);
  // Поворот массива точно должен быть отдельной функцией
  for (int i = 0; i < fileSize / 2; i++) {
    std::swap(buffer[i], buffer[fileSize - i - 1]);
  }

  std::ofstream outfile("output.bin", std::ios::binary);
  outfile.write(buffer, fileSize);

  infile.close();
  outfile.close();

  delete[] buffer;
  return 0;
}
