// zrob_sie_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string linia;
    fstream odczyt("stop.txt");
    
    if (odczyt.is_open())
    {
        getline(odczyt, linia);
        cout << "Magiczny numer: " << linia << endl;
        getline(odczyt, linia);
        cout << "Kolumny / wiersze: " << linia << endl;
        getline(odczyt, linia);
        cout << "Max wartosc kolorow: " << linia << endl;
        //wczytujemy wymiary 
        int w, k;
        cout << "Liczba kolumn: ";
        cin >> k;
        cout << "Liczba wierszy: ";
        cin >> w;
              // tworzymy tablice 2D DYNAMICZNA, deklarujemy tablice a potem rezerwujemy miejsce w pamieci, typ taki sam jak wskaznik(tworzymy tablice wskaznikow na wskazniki
        int** tab2 = new int* [w]; //alokacja pamieci
        for (int i = 0; i < w; ++i)
        {
            tab2[i] = new int[k]; //alokacja pamieci - przydzielenie dla kazdego wiersza po k komorek
            for (int j = 0; j < k; ++j) //wpisanie wartosci do tablicy
            {
                char znak;
                odczyt >> znak;
                tab2[i][j] = znak;
            }
        }

        long int histogram[256];
        for (int s = 0; s < 256; ++s)
        {
            histogram[s] = 0;
        }
        
        for (int x = 0; x < w; ++x)
        {
            for (int y = 0; y < k; ++y)
            {
                int indeks = tab2[x][y];
                histogram[tab2[x][y]] ++;

                
            }
        }
        
        for (int q = 0; q < 256; ++q)
        {
            cout << " " << histogram[q] << " ";

        }

        
        // wypisz tab2[w][k]
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < k; ++j)
                cout << tab2[i][j] << '\t';
    
        //kasujemy tab2
        for (int i(0); i < w; ++i)
            delete[] tab2[i]; // uwolnienie pamieci 
        delete[] tab2;
        tab2 = NULL;
        system("PAUSE");
        
    }
    else
        cout << "Nie uda³o siê otworzyæ pliku";

    cin.get();
    
    
    


    return 0;
         
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
