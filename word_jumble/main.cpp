#include <clocale>
#include <codecvt>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main(int, char **) {
  setlocale(LC_ALL, "Russian");
  //Скрытое использование свойств enum WORD = 0, HINT = 1, NUM_FIELDS
  //Запутывает код...
  enum fields { WORD, HINT, NUM_FIELDS };
  const int NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][NUM_FIELDS] = {
      {"стена", "Ты чувствуешь, что уперся головой во что-то?"},
      {"очки", "Это может помочь разглядеть ответ."},
      {"трудный", "Загадки Горлума были именно такие, но Бильбо справился."},
      {"постоянный", "Всё течёт, всё изменяется, кроме этого."},
      {"перемешать", "О чем это игра"}};

  srand(static_cast<unsigned int>(time(0)));
  int choice = rand() % NUM_WORDS;
  string theWord = WORDS[choice][WORD];
  string theHint = WORDS[choice][HINT];

  wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  wstring jumble = converter.from_bytes(theWord);
  for (int i = 0; i < jumble.size(); ++i) {
    int index1 = rand() % jumble.size();
    int index2 = rand() % jumble.size();
    wchar_t temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  cout << converter.to_bytes(jumble) << endl;
  return 0;
}