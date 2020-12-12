#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
using namespace std;
bool IsOrNot(char* FileName)
{
    FILE* f;
    if ((f = fopen(FileName, "r")) == NULL)
    {
        cerr << "Помилка при відкритті файлу.\n";
        exit(1);
    }

    const int LEN = 80;
    char s[LEN];
    size_t l = 0;
    while (!feof(f))
    {
        fgets(s, LEN - 1, f);
        for (size_t i = 0; i<strlen(s)-2; i++)
            if (s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*')
                return true;
    }
    return false;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char FileName[] = "t.txt";
    if (IsOrNot(FileName))
        cout << "*** is found." << endl;
    else
        cout << "*** is not found." << endl;
}