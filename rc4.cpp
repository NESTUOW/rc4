#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
const unsigned int blockSize = 0x10000;
unsigned int i, j;
unsigned char S [0x100];
unsigned char output(void);

int main() {
  unsigned int buffer_size = 0x10000;
  int differente = 0;
  int pointer = 0;
  std::string key_string = "12345678";
  char key_length = 8;
  std::string input_stream;

  cin >> input_stream;
  // cout << input_stream;

  unsigned char *key = (unsigned char *)key_string.c_str();
  for (i = 0; i < 0x100; i++)
      S[i] = i;
  for (i = j = 0; i < 0x100; i++) {
      unsigned char temp;
      j = (j + key[i % key_length] + S[i]) & 0xFF;
      temp = S[i];
      S[i] = S[j];
      S[j] = temp;
  }
  i = j = 0;

  cout << output();
  return 0;
}


unsigned char output() {
    unsigned char temp;
    i = (i + 1) & 0xFF;
    j = (j + S[i]) & 0xFF;
    temp = S[i];
    S[i] = S[j];
    S[j] = temp;
    return S[(S[i] + S[j]) & 0xFF];
}
