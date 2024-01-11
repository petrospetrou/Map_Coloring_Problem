/*
 * Afto to programma epiliei to Map Coloring Problem
 * Einai ypefthino na anathesi se kathe hora apo ena hroma lamvanontas ipopsin
 * poies hores ta sinora tis kathe horas
 */

/* 
 * Project: Homework 4
 * File:   main.c
 * Author: Petros Petrou - christos Georgopoulos
 *
 * Created on November 29, 2021, 9:39 AM
 */

/* Dilwsi Vivliothikon */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


// Global variable gia xrisi stis sinartisis
int numberOfCountries = 0;

void printSolution(char countries[numberOfCountries][80], int color[]);

/* Sinartisi pou elegxei kata poso einai asfales na anathesi ena hroma
    se kapoia hora h ohi */
bool isSafe(bool graph[numberOfCountries][numberOfCountries], int color[])
{
    // Elegxos tis kathe akmis
    for (int i = 0; i < numberOfCountries; i++)
    {
        for (int j = i + 1; j < numberOfCountries; j++)
        {
            if (graph[i][j] && color[j] == color[i])
            {
                return false;
            }
        }
    }

    return true;
}

/* Afti i sinartisi einai i epilisi tou Map Coloring Problem
    Xrisimopoiei tin methodo ths anadromis
    Epistrefi False otan den boroun na anatethun ta 3 hromata
    Epistrefi True otan borun na anatethun ta 3 hromata*/

bool graphColoring(bool graph[numberOfCountries][numberOfCountries], int m, int i, int color[numberOfCountries])
{
    // an o pinakas ftasi sto telos
    if (i == numberOfCountries)
    {
        // Elegxos an ine asfales na anathesi hrwma
        if (isSafe(graph, color))
        {
            // Print the solution
            //printSolution(color);
            return true;
        }

        return false;
    }

    // Anatheti ena hrwma apo to 1 mehri to 3(max) - Me anadromi
    for (int j = 1; j <= m; j++)
    {
        color[i] = j;

        // Anathesi hromatos stis ipoloipes akmes - Me anadromi
        if (graphColoring(graph, m, i + 1, color))
            return true;

        color[i] = 0;
    }

    return false;
}

/* Sinartisi i opoia tha ektiposi tis hwres me to antistoiho hroma tous */
void printSolution(char countries[numberOfCountries][80], int color[])
{
    int i = 0;

    printf("Solution Exists: Following are the assigned colors \n\n");

    for (int i = 0; i < numberOfCountries; i++)
    {
        if(color[i]==1)
            printf("%s (Red)", countries[i]);
        else if(color[i]==2)
            printf("%s (Green)", countries[i]);
        else
            printf("%s (Blue)", countries[i]);

        printf("\n");
    }
}

// Kirio Programma 

int main()
{
    
    // Anoigma tou arhiou
    FILE *file;
    file = fopen("project.txt","r");
    if(!file)
    {
        printf("error");
        exit(-1);
    }

    // Diavasma tis protis grammis - Plithos hwrwn
    fscanf(file,"%d",&numberOfCountries);
    

    // Pinakas gia Eisagwgi twn Hwrwn
    char countries[numberOfCountries][80];

    // Dimiourgia - Anaparastasi grafou ws Disdiastatos Pinakas
    bool graph[numberOfCountries][numberOfCountries];

    // Arhikopoiisi tou pinaka
    for (int i = 0; i < numberOfCountries; i++){
        for (int j = 0; j < numberOfCountries; j++){
            graph[i][j] = 0;
        }
    }

    char line[256];
    int lineCount = 0;

    // Diavasma olou tou arhiou grammi-grammi
    while (fgets(line, sizeof(line), file)) {

        /* H fgets sto telos tis kathe grammis prostheti ton telesti \n o opoios
           dimiourga provlima metepeita stin dimiurgia tou pinaka geitniasis
            Etsi ginetai antallagi tou \n me to \0*/
        
        // Afairesi ton extra grammwn pou prostheti to fgets
        int len = strlen(line);
        if(line[len-1]=='\n')
           line[len-1]='\0';

      

        // Agnoisi tis anagnwsis tis protis grammis tou arhiou afou diavastike
        if (lineCount == 0){
                lineCount++;
            continue;
        }
        else if (lineCount == 1){ // i defteri grammi tou arhiou
              int countriesIndex = 0;

              // Diahorismos se grammes me to space
              char * pch = strtok (line," ");
              while (pch != NULL)
              {
               
                strcpy(countries[countriesIndex], pch); // copy value to the correct array index
                countriesIndex++;

                pch = strtok (NULL, " ");
              }
        }
        else { //Gia tis ipoloipes grammes, vres tin shesi ton sinoron kai dimiurga ton grafo

            int firstCountryIndex;
            int secondCountryIndex;
            int index = 1;

              char * pch;
              pch = strtok (line," ");
              while (pch != NULL)
              {
                // Vriskei tis hwres pou einai geitonikes 
                for (int i =0; i<numberOfCountries; i++){
                    char *s = strstr(countries[i], pch);
                    if (s != NULL)
                    {
                        //Arithmizi tis 2 geitonikes kai tis anatheti se 2 metavlites
                        if (index == 1){
                            firstCountryIndex = i;
                        }
                        else{
                            secondCountryIndex = i;
                        }

                        break;
                    }
                }

                index++;
                pch = strtok (NULL, " ");
              }

                // Kathorise tis geitonikes xwres ston disdiastato pinaka
                graph[firstCountryIndex][secondCountryIndex] = 1;
                graph[secondCountryIndex][firstCountryIndex] = 1;
        }

        lineCount++;
    }

    //Kleisimo toy arhiou
    fclose(file);

    //Dilwsi twn diathesimwn hromatwn
    int m = 3; 

    /* Arhikopoiisi twn timwn twn hromatwn gia na mporei na leitourgisei swsta 
       h isSafe*/
    
    int color[numberOfCountries];
    for (int i = 0; i < numberOfCountries; i++)
    {
        color[i] = 0;
    }
    
    //Efarmozetai se periptosi pou den iparhi lisi tou provlimatos
    
    if (!graphColoring(graph, m, 0, color))
    {
        printf("Solution does not exist.");
        return 0;
    }

    //Ektiposi apotelesmaton me thn sinartisi printSolution
    
    printSolution(countries, color);


    return 0;
}
