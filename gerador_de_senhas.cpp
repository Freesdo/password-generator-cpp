#include <ctime>
#include <iostream>
#include <locale.h>
#include <map>
#include <string>
using std::cin;
using std::cout;

// eu poderia listar os caracteres a partir da tabela ascii (como por exemplo o
// 33 que equivale ao '!', mas utilizarei string pois fica bem mais rápido e
// prático)
void gerar_senha(const bool &especial, const bool &baixa, const bool &alta,
                 const bool &numerico);
int main() {
  setlocale(LC_ALL, "");

  std::srand(std::time(nullptr));
  std::map<bool, std::string> map_especial, map_baixa, map_alta, map_numericos;
  map_especial[true] = "desativar";
  map_especial[false] = "habilitar";
  map_baixa[true] = "desativar";
  map_baixa[false] = "habilitar";
  map_alta[true] = "desativar";
  map_alta[false] = "habilitar";
  map_numericos[true] = "desativar";
  map_numericos[false] = "habilitar";

  bool especial, baixa, alta, numerico;
  especial = false;

  baixa = true;
  alta = false;
  numerico = false;

  std::size_t menu;
  cout << "--GERADOR DE SENHAS--\n\n"
       << "por padrão já ativado os caracteres em caixa baixa.\n";
  while (true) {
    cout << "Digite:\n\n"
         << "0 para encerrar o programa\n"
         << "1 para gerar a senha\n"
         << "2 para " << map_especial[especial] << " os caracteres especiais\n"
         << "3 para " << map_baixa[baixa] << " os caracteres em caixa baixa\n"
         << "4 para " << map_alta[alta] << " os caracteres em caixa alta\n"
         << "5 para " << map_numericos[numerico]
         << " os caracteres numéricos\n";
    cin >> menu;
    switch (menu) {
    case 0:
      return 0;
      break;
    case 1:
      gerar_senha(especial, baixa, alta, numerico);
      return 0;
      break;
    case 2:
      if (!especial)
        especial = true;
      else
        especial = false;
      break;
    case 3:
      if (!baixa)
        baixa = true;
      else
        baixa = false;
      break;
    case 4:
      if (!alta)
        alta = true;
      else
        alta = false;
      break;
    case 5:
      if (!numerico)
        numerico = true;
      else
        numerico = false;
      break;

    default:
      break;
    }
  }
  return 0;
}

void gerar_senha(const bool &especial, const bool &baixa, const bool &alta,
                 const bool &numerico) {
  setlocale(LC_ALL, "");

  std::size_t indice{0};
  std::map<std::size_t, const std::string *> mapa_senha;
  std::string caracteres_especiais{"!@#$%&*+=?"};
  std::string caracteres_caixa_baixa{"abcdefghijklmnopqrstuvwxyz"};
  std::string caracteres_caixa_alta{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string caracteres_numericos{"1234567890"};

  if (especial) {

    mapa_senha[indice] = &caracteres_especiais;
    indice++;
  }
  if (baixa) {

    mapa_senha[indice] = &caracteres_caixa_baixa;
    indice++;
  }
  if (alta) {

    mapa_senha[indice] = &caracteres_caixa_alta;
    indice++;
  }
  if (numerico) {

    mapa_senha[indice] = &caracteres_numericos;
    indice++;
  }

  std::string senha;
  cout << "\npara finalizar, quantos caracteres você quer que tenha?\n";
  std::size_t qntd_caracteres;
  cin >> qntd_caracteres;
  while (qntd_caracteres <= 0) {
    cout << "valor invalido. insira novamente:\n";
    cin >> qntd_caracteres;
  }

  for (std::size_t i{}; i < qntd_caracteres; ++i) {
    std::size_t random_index = std::rand() % indice;
    const std::string *password_chars = mapa_senha[random_index];
    std::size_t char_index = std::rand() % password_chars->size();
    senha.push_back(
        password_chars->at(char_index)); // inicialmente eu fiz
                                         // mapa_senha[std::rand%indice]->at(mapa_senha[std::rand%indice]->size())
                                         // mas o implementado é mais legível
  }
  cout << "sua senha é " << senha << '\n';
  return;
}
