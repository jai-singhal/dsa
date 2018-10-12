

#include <stdlib.h> // to use NULL
#include <stdio.h>  // to use printf
#include <string.h> // to use String
#include <stdbool.h> // to define bool

char output[100][10][20]; // [total][line][word]
int total = 0;

void swap(char **x, char **y) {
    char* temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

bool isPalRec(char word[], int start, int end){

    // If there is only one character in string
    // then it is palindrome
    if (start == end)
        return true;

    // If first and last
    // characters do not match
    // then it is not palindrome

    if (word[start] != word[end])
        return false;

    // If there are more than
    // two characters, check if
    // middle substring is also
    // palindrome or not.
    if (start < end + 1)
        return isPalRec(word, start + 1, end - 1);

    return true;
}

bool isPalindrom(char word[]) {

    int length = strlen(word);

    // An empty string is
    // considered as palindrome

    if(length == 0) return true;
    return isPalRec(word, 0, length - 1);
}



void checkPalindrom(char* data[], int s, int count){

    char combn[50];
    int comb_index = 0;
    for (int j=0; j<s; j++){
        for(int m = 0; m < strlen(data[j]); m++)
            combn[comb_index++] = data[j][m];
    }
    combn[comb_index] = '\0';

    // for(int i = 0; i < s; i++)
    // 	printf("%s ", data[i]);
    // printf("\n");
    // printf("%d\n", count);
    bool isPermutationPalindrom = isPalindrom(combn);
    if(isPermutationPalindrom){
        for(int i = 0; i < s; i++)
            strcpy(output[total][i], data[i]);
        total++;
    }
}

void permute(char* data[], int l, int r, int n) {
    static int count = 0;
    int i;
    if (l == r) {
        count++;
        checkPalindrom(data, n, count);
    }
    else{
        for (i = l; i <= r; i++){
            swap((data+l), (data+i));
            permute(data, l+1, r, n);
            swap((data+l), (data+i));
        }
    }
}

void combinationUtil(char arr[][100], int n, int r, int index, char* data[], int i) {
    if (index == r) {
        char* tempData[r];
        char* text;
        for(int x = 0; x < r; x++){
            text = (char*)malloc(100);
            strcpy(text,data[x]);
            tempData[x] = text;
        }
        permute(tempData, 0, r-1, r);
        return;
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
    combinationUtil(arr, n, r, index, data, i+1);
}





void printCombination(char arr[][100], int n, int r) {
    char* data[r];
    combinationUtil(arr, n, r, 0, data, 0);
}

int main(int argc, char const *argv[]){
    char arr[100][100];
    int lineNumber = 0;
    if(argc < 3){
        printf("You should enter 2 arguments i.e., filename followed by palLength\n");
        return 0;
    }
    int r = atoi(argv[2]);
    char filename[100];
    strcpy(filename, argv[1]);
    FILE *file = fopen (filename, "r" );
    if ( file != NULL ){
        char line [100];
        while ( fgets ( line, sizeof(line), file ) != NULL ) {
            line[strlen(line)-1] = '\0';
            strcpy(arr[lineNumber++], line);
        }
        fclose ( file );
    }

    if(lineNumber == 0){
        printf("Input file should have some data\n");
    }

    printCombination(arr, lineNumber, r);


    for(int i = 0; i < total; i++){
        for(int j = 0; j < r; j++){
            printf("%s ", output[i][j]);
        }
        printf("\n");
    }


    return 0;
}