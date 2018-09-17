#include <stdio.h> 
#include<stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <sys/types.h> 
#include <fcntl.h> 
#define lineWidth 32 
#define TRUE 1
#define FALSE 0
#define idLength 6


void binarySearch(char* fileName, char* idName) { 
	char arr[100];
	int f_write = open(fileName, O_RDONLY); 
	int charPointer = 0, linePointer = 0, arrayPos = 0;

    char id[6]; // character array for storing the id of line search
    // get the total bytes of file
    int totalChar = lseek(f_write, 1, SEEK_END)- lseek(f_write, 1, SEEK_SET);

    int r = (totalChar+2)/lineWidth, l = 0, mid = 0;
    int totalLines = r;

    lseek(f_write, 0, SEEK_SET);
    int key = atoi(idName), id1 = 0;
    int found = FALSE;

    // BINARY SEARCH
    int count = 0;
    while (l <= r){
    	count++;
    	if(found == 1)
    		break;
    	mid = l + (r-l)/2;
    	// Seek to middle line of file
    	lseek(f_write, mid*lineWidth, SEEK_SET);

    	while (read(f_write, arr, 1)){ 
    		if (charPointer < idLength) {
    			id[arrayPos++] = arr[0];
    			charPointer++;
    		}
    		else{
    			id[arrayPos] = '\0';
    			arrayPos = 0;
    			charPointer = 0;
    			id1 = atoi(id);
    			break;
    		} 
    	}

		if (id1 == key){
			lseek(f_write, mid*lineWidth, SEEK_SET);
			charPointer = 0;
			while (read(f_write, arr, 1)){ 
				if (charPointer < 32) {
					printf("%c", arr[0]);
					charPointer++;
				}
			}
			found = TRUE;
		}
		if (id1 > key) {
			r = mid - 1; 
		}
		else{
			l = mid + 1;
		}
    } 

    if(!found)
    	printf("No entries found\n");
    close(f_write); 

    printf("\n\nComplexity = %d from n = %d\n", count, totalLines);
} 

int main(int argc, char *argv[]) { 
	if(argc < 3){
		printf("You have entered too few  arguments.\n");
	}
	else if(argc > 3){
		printf("You have entered too many arguments.\n");
	}
	else{
		printf("You have entered the correct number of arguments.\n");
	}
	printf("The file name you chose is:\n");
	printf(argv[1]);
	printf("\nThe index you chose is:\n");
	printf(argv[2]);
	printf("\n");
	int i =0, count=0;
	while(argv[2][i]!='\0'){
		if(argv[2][i] >='0' || argv[2][i] <= '9'){
			count++;
			i++;
		}
		else{
			printf("Your index has a non-numeric character.\n");
		}
	}
	if(count > idLength){
		printf("Your index is greater than 6 characters.\n");
	}
	else if(count < idLength){
		printf("Your index is less than 6 characters.\n");
	}
	else{
		printf("Your index is 6 characters.\n");
	}

	binarySearch(argv[1], argv[2]); 
	return 0; 
} 