// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    string linia1, linia2, linia3;    
    fstream modyfikacja("modyfikacja.txt", ios::out | ios::app);

    FILE* plik = fopen("stop.txt", "r");
    int wiersze;
    int kolumny;
    int skala;
    char s[5];
    if (plik == NULL)
    {
        printf("Otwarcie nieudane");
        exit(-1);
    }
    fscanf(plik, "%s %d %d %d", &s, &wiersze, &kolumny, &skala); //fscanf zwarca liczbe znakow ktora udalo sie odczytac z pliku
    printf("Wymiar: %s\n", s);
    printf("Wiersze/kolumny: %d %d\n", wiersze, kolumny);
    printf("Skala szarosci: %d\n", skala);

    //wczytywanie wymiarow
    int w, k;
    cout << "Podaj liczbe wierszy: " << endl;
    cin >> w;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> k;

    int** tab2 = new int* [w];
    for (int i = 0; i < w; i++)
    {
        tab2[i] = new int[k];
        for (int j = 0; j < k; j++)
        {
            /*//metoda I ale chyba sie nie nadaje do tego
            char znak;
            while ((znak = fgetc(plik)) != EOF)
            {
                tab2[i][j] = znak;
            }*/
            /*//metoda II
            cout << "Wyswietlam tablice: \n ";
            while (fscanf(plik, "%f", &tab2[i][j]) != EOF)
            {
                printf("%i\t", tab2[i][j]);

            }*/
            //metoda III
            fscanf(plik, "%f", &tab2[i][j]);
        }
    }
    fclose(plik);

    /*long int histogram[256];
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
    // max histogramu
    int max = histogram[0];
    for (int i = 1; i < 256; i++)
        if (max < histogram[i])
            max = histogram[i];

    //normalizacja histogramu
    for (int i = 0; i < 255; i++)
        histogram[i] = (histogram[i] / max) * w;*/

    
    cout << endl << "Wypisujemy tablice: " << endl;
    // wypisz tab2[w][k]
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < k; ++j)
            cout << tab2[i][j] << '\t';

    /*cout << "Histogram: " << endl;

    for (int q = 0; q < 256; ++q)
    {
        cout << " " << histogram[q] << " ";

    }*/
    /*// zamiana kolorow
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
            if (tab2[i][j] > 200)
                tab2[i][j] = 0;
    }

    //wyswietlanie zmiany kolorow
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            cout << tab2[i][j] << '\t';

    //zapisanie do pliku
     modyfikacja << linia1 << endl;
     modyfikacja << linia2 << endl;
     modyfikacja << linia3 << endl;


    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
        {
            modyfikacja << tab2[i][j];
        }

    modyfikacja.close();*/


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
