/* Ben Cradick
 * cs2750 PA4
 * 11-12-2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int numChar(FILE*);
int numLines(FILE*);
int numWords(FILE*);

struct fileStats{
    int wordCount;
    int charCount;
    int lineCount;
    char fileName[];
};



int main(int argc, char *argv[]) {
    //Array of fileStats struct to keep an organized record of all values found for each argument
    struct fileStats fileStat[argc];

    //declared outside of loop to keep program backwards compatible to C90
    size_t i;
    for(i = 1; i < argc; i++){
        //setting FILE pointer to the first document and setting to "read"
        FILE* f = fopen(argv[i], "r");

        //Reallocating memory for the new string that is going to be the file holder for later.
        memset(fileStat[i].fileName, '\0', sizeof((char)argv[i]));
        strcpy(fileStat[i].fileName, argv[i]);

        //TODO remove this testing command

        //Assigning all the values allowed by the struct
        fileStat[i].wordCount = numWords(f);
        fileStat[i].lineCount = numLines(f);
        fileStat[i].charCount = numChar(f);







    }

    return 0;
}
// Functions solely exist in this script to keep the code modular and easier to maintain.

/* numChar() counts the number of characters in any given file
 * Takes in a file
 * loops through every character in the file with fgetc(f)
 * if the character is End Of File it breaks loops and returns the total number of characts.
 */
int numChar(FILE *f){
    int count = 0;
    int i;
    while((i = fgetc(f))) {
        if (i == EOF) {
            rewind(f);
            return count;
        }
        count++;
    }
return 0;

}
/*
 * numLines() gives the number of lines in any given file make changes
 * Takes in a file increments an integer initialized to zero if a space tab or newline are the current character in the file
 *
 */
int numLines(FILE *f){
    int count = 0;
    int i;
    while((i = fgetc(f))) {
        if (i == EOF) {
            count++;
            rewind(f);
            return count;
        }
        else if(i == '\n')
        {
            count++;
        }

    }
    return 0;
}
/*
 * numWords() gives the number of words in any given file
 * TODO: describe how function works
 */
int numWords(FILE *f){
    int count = 0;
    int i;
    while((i = fgetc(f))) {
        if (i == EOF) {
            count++;
            rewind(f);
            return count;
        }
        else if(i == '\n' || i == '\t' || i == ' ')
        {
            count++;
        }

    }
    return 0;
}