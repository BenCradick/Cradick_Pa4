/* Ben Cradick
 * cs2750 PA4
 * 11-12-2017
 */

#include <stdio.h>
#include <string.h>
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
    int totalWords = 0;
    int totalLines = 0;
    int totalCharacters = 0;

    for(i = 1; i < argc; i++){
        //setting FILE pointer to the first document and setting to "read" ("r")
        FILE* f = fopen(argv[i], "r");

        //Reallocating memory for the new string that is going to be the file holder for later.
        memset(fileStat[i].fileName, '\0', sizeof((char)argv[i]));
        strcpy(fileStat[i].fileName, argv[i]);

        //Assigning all the values allowed by the struct
        fileStat[i].wordCount = numWords(f);
        fileStat[i].lineCount = numLines(f);
        fileStat[i].charCount = numChar(f);

        totalWords += fileStat[i].wordCount;
        totalCharacters += fileStat[i].charCount;
        totalLines += fileStat[i].lineCount;


        //prints data on the read file to the console.
        printf("\n%-20s%-12s%-12s\n","File name", "=", fileStat[i].fileName);
        printf("%-20s%-12s%-12d\n","Characters in file" ,"=", fileStat[i].charCount);
        printf("%-20s%-12s%-12d\n","Words in file","=", fileStat[i].wordCount);
        printf("%-20s%-12s%-12d\n\n","Lines in the file", "=", fileStat[i].lineCount);
        int r = 0;
        for(r = 0; r < 80; r++){
            printf("=");
        }
        printf("\n\n");

    }
    printf("\n\nSummary of all files\n");
    printf("%-20s%-12s%-12d\n","Total characters", "=", totalCharacters);
    printf("%-20s%-12s%-12d\n","Total Words", "=", totalWords);
    printf("%-20s%-12s%-12d\n\n","Total Lines", "=", totalLines);

    return 0;
}
// Functions solely exist in this script to keep the code modular and easier to maintain.

/* numChar() counts the number of characters in any given file
 * Takes in a file
 * loops through every character in the file with fgetc(f)
 * if the character is End Of File it breaks loops and returns the total number of characters.
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
 * i = fgetc(f) sets i to the current character to be read
 * if character is the newline character '\n' we can assume that there is a new line
 * so we increment the line counter
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
 * reads characters in the same fashion
 * Takes in a file increments an integer initialized to zero if a space tab or newline are the current character in the file
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