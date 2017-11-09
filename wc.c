#include <stdio.h>
#include <ctype.h>
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

        FILE *f = fopen(argv[i], "r");
        printf("%s", argv[i] + '\n');
        printf("%s", "\n");
    }

    return 0;
}
// Functions solely exist in this script to keep the code modular and easier to maintain.

/* numChar() counts the number of characters in any given file
 *
 * TODO: describe how this function works.
 *
 */
int numChar(){

    return 0;

}
/*
 * numLines() gives the number of lines in any given file make changes
 *
 * TODO: describe how function works
 */
int numLines(){

    return 0;
}
/*
 * numWords() gives the number of words in any given file
 * TODO: describe how function works
 */
int numWords(){

    return 0;
}