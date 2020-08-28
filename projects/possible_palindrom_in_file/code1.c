#include <stdlib.h> // to use NULL
#include <stdio.h>  // to use printf
#include <string.h> // to use String
#include <stdbool.h> // to define bool

char*** output;
int totalCombinations = 0;

void swap(char **x, char **y) { 
    char* temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

bool isPalRec(char word[], int start, int end){
    if (start == end)
        return true;

    if (word[start] != word[end])
        return false;

    if (start < end + 1)
        return isPalRec(word, start + 1, end - 1);

    return true;
}

bool isPalindrom(char word[]) {
    int length = strlen(word);
    if(length == 0) return true;
    return isPalRec(word, 0, length - 1);
}

void checkPalindrom(char* data[], int palLength, int count){
	char combn[60];
	int comb_index = 0;
    for (int j=0; j<palLength; j++){
    	for(int m = 0; m < strlen(data[j]); m++)
    		combn[comb_index++] = data[j][m];
    }
    combn[comb_index] = '\0';
	bool isPermutationPalindrom = isPalindrom(combn);
    if(isPermutationPalindrom){
        output[totalCombinations] = (char**)malloc(palLength*sizeof(char**));
    	for(int i = 0; i < palLength; i++){
            output[totalCombinations][i] = (char*)malloc(strlen(data[i])*sizeof(char) + 1);
    		strcpy(output[totalCombinations][i], data[i]); // xx
        }
    	totalCombinations++;
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


void bubbleSort(int palLength){ 
    char** temp;
    int k = 0;
    for (int i = 0; i < totalCombinations - 1; ++i){
        for(int j = 0; j < totalCombinations-i-1; ++j){
            k = 0;
            while(strcmp(output[j][k], output[j+1][k]) == 0 && k < palLength)
                k++;
            if(strcmp(output[j][k], output[j+1][k]) > 0){
                temp = output[j];
                output[j] = output[j+1];
                output[j+1] = temp;
            }
        }
    }
}

void printInLexioGrahicOrder(int palLength){
    bubbleSort(palLength);
    for(int i = 0; i < totalCombinations; i++){
        for(int j = 0; j < palLength; j++)
            printf("%s ", output[i][j]);
        printf("\n");
    }
}

void getCombinations(char arr[][100], int n, int r) { 
    char* data[r]; 
    combinationUtil(arr, n, r, 0, data, 0); 
}

int main(int argc, char const *argv[]){
	char arr[100][100];
    output = (char***)malloc(100*sizeof(char**));

    int lineNumber = 0;
    if(argc < 3){
    	printf("You should enter 2 arguements i.e., filename followed by palLength\n");
    	return 0;
    }
	FILE *file = fopen (argv[1], "r" );
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

    int palLength = atoi(argv[2]);

	getCombinations(arr, lineNumber, palLength);
    printInLexioGrahicOrder(palLength);

	return 0;
}