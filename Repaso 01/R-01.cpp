//entrada y salida en consola
#include <iostream>
using namespace std;

void printArray(char array[9]);
bool hasLetter(char letter, char array1[9], char array2[9]);
bool compareArrays(char array1[9], char array2[2]);

int main(void)
{
    char word[9] = {'c', 'o', 'd', 'i', 'f', 'i', 'c', 'a', 'r'};
    char aux[9];
    char letter;
    int a = 13;

    for (int i = 0; i < 9; i++)
    {
        aux[i] = '_';
    }

    cout << "La palabra contiene 9 letras" << endl;

    do
    {
        cout << "Turnos restantes  '" << a << "'  Digite una letra: ";
        cin >> letter;
        if (hasLetter(letter, word, aux) == true)
        {
            cout << "La palabra si contiene la letra " << letter << endl;
        }
        else
        {
            a--;
            cout << "La palabra no contiene la letra " << letter << endl;
        }
        printArray(aux);

        if (compareArrays(word, aux) == true)
        {
            cout << "Has adivinado la palabra" << endl;
            return 0;
        }

    } while (a > 0);
    // se acaban los intentos
    cout << endl
         << endl;
    cout << "Lo siento, has perdido!" << endl;
    return 0;
}

void printArray(char array[9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl
         << endl;
}

bool hasLetter(char letter, char array1[9], char array2[9])
{
    bool flag = false;

    for (int i = 0; i < 9; i++)
    {
        if (array1[i] == letter)
        {
            flag = true;
            array2[i] = letter;
        }
    }
    return flag;
}

bool compareArrays(char array1[9], char array2[2])
{
    for (int i = 0; i < 9; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}