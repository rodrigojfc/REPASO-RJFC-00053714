//entrada y salida en consola
#include <iostream>
using namespace std;

void printArray(char *array, int sizeArray);
bool hasLetter(char letter, char *array1, char *array2, int sizeArray);
bool compareArrays(char *array1, char *array2, int sizeArray);

int main(void)
{
    int size = 0;
    char *word;
    char *aux;
    char saveLetter;

    cout << "Tamaño de la palabra " << endl;
    cin >> size;
    word = new char[size];
    aux = new char[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese la palabra: ";
        cin >> saveLetter;
        word[i] = saveLetter;

    }

    cout << "Tu palabra contiene   '" << size << "'   letras" << endl;

    for (int i = 0; i < size; i++)
    {
        aux[i] = '_';
    }

    char letter;
    int a = size + 3;

    do
    {
        cout << "Turnos restantes  '" << a << "'  Digite una letra: ";
        cin >> letter;
        if (hasLetter(letter, word, aux, size) == true)
        {
            cout << "La palabra si contiene la letra " << letter << endl;
        }
        else
        {
            a--;
            cout << "La palabra no contiene la letra " << letter << endl;
        }
        printArray(aux, size);

        if (compareArrays(word, aux, size) == true)
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

void printArray(char *array, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

bool hasLetter(char letter, char *array1, char *array2, int sizeArray)
{
    bool flag = false;
    for (int i = 0; i < sizeArray; i++)
    {
        if (array1[i] == letter)
        {
            flag = true;
            array2[i] = letter;
        }
    }
    return flag;
}

bool compareArrays(char *array1, char *array2, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}