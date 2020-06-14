// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;



int main()
{
  
    int row = 0, col = 0, numrows = 0, numcols = 0, skala = 0;
    ifstream plik("mona_binary.pgm");
    stringstream ss;
    //string inputLinia = "";
    string linia1, linia2;
    fstream modyfikacja("modyfikacja.txt", ios::out | ios::app);


    // Linia pierwsza - magic number
    getline(plik, linia1);
    if (linia1.compare("P2") != 0) cerr << " Niewlasciwy numer magiczny " << endl;
    else cout << "Numer magiczny : " << linia1 << endl;

    // Linia druga - komentarz
    getline(plik, linia2);
    cout << "Komentarz : " << linia2 << endl;

    // Kontynuacja z stringstream - strumien napisowy  
    ss << plik.rdbuf();
    // Trzecia linia - rozmiar
    ss >> numcols >> numrows;
    cout << numcols << " kolumn oraz " << numrows << " wierszy" << endl;

    //Czwarta linia - skala
    ss >> skala;
    cout << "Skala : " << skala << endl;
    

    int w = numrows;
    int k = numcols;
    int** tab2 = new int* [w];
    for (int i = 0; i < w; i++)
    {
        tab2[i] = new int[k];

        for (int j = 0; j < k; j++)
        {
            ss >> tab2[i][j];        
        }

    }

    plik.close();

    cout << endl << "Wypisujemy tablice: " << endl;
    // wypisz tab2[w][k]
/*
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < k; ++j)
        {
            cout << tab2[i][j] << " ";
        }
*/
    long int histogram[256];
    for (int s = 0; s < 256; ++s)
    {
        histogram[s] = 0;
    }

    for (int x = 0; x < w; ++x)
    {
        for (int y = 0; y < k; ++y)
        {
            histogram[tab2[x][y]] ++;

        }
    }

    //Wyswietlanie histogramu
    cout << "Histogram: " << endl;
    for (int q = 0; q < 256; ++q)
        cout << " " << histogram[q] << " ";
   
    // max histogramu
    int max = histogram[0];
    for (int i = 1; i < 256; i++)
        if (max < histogram[i])
            max = histogram[i];

    //normalizacja histogramu
    for (int i = 0; i < 255; i++)
        histogram[i] = (histogram[i] / max) * w;

    //Wyswietlanie histogramu znormalizowanego
    cout << endl << "Histogram znormalizowany: " << endl;
    for (int i = 0; i < 256; ++i)
        cout << " " << histogram[i] << " ";
    cout << endl;

    // zamiana kolorow
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            if (tab2[i][j] < 60)
            {
                tab2[i][j] = 0;
            }
            else
            {
                tab2[i][j] = tab2[i][j];
            }
    

    //wyswietlanie zmiany kolorow
    /*
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            cout << endl << tab2[i][j] << '\t';
    */

    // zapis do pliku modyfiakcja.txt
    
    modyfikacja << linia1 << endl;
    modyfikacja << linia2 << endl;
    modyfikacja << numcols << " " << numrows << endl;
    modyfikacja << skala << endl;


    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
        {
            modyfikacja << " " << tab2[i][j];
        }

    modyfikacja.close(); 
        

    //kasujemy tab2
    for (int i(0); i < w; ++i)
        delete[] tab2[i]; // uwolnienie pamieci 
    delete[] tab2;
    tab2 = NULL;
    system("PAUSE");
       

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
