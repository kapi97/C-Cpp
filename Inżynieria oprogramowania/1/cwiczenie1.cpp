// cwiczenie1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
//#include "stdafx.h"
#include "limitarr.h"
#include "ArrayDb.h";
const int arrlen = 4;

int main()
{
    std::cout << "Hello World!\n"; 
	LimitArr lim1(arrlen, 20, 10);
	cout << lim1;
	for (int i = 20; i < 24; i++)
		lim1[i] = i + 100;
	cout << lim1;
	cout << lim1[22] << "\n";
	ArrayDb & ra = lim1;
	ArrayDb * pa = &lim1;
	ra[22] = 88.87;
	(*pa)[21] = 66;
	cout << lim1;
	system("pause");
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
