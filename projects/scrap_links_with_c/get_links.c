#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_sub_strings(char text_line[], const char sub_string[]){
    char *cursor = NULL;
    int sub_count = 0;
    int sub_length = strlen(sub_string);

    cursor = strstr(text_line, sub_string);
    while (cursor != NULL) {
        sub_count++;
        cursor = cursor + sub_length;
        cursor = strstr(cursor, sub_string);
    }
    return sub_count;
}
// the memory allocation should happen here before the next function runs.
// the alocation of the memory should also use free() to free up the alocated memory after it have been used.

char **get_sub_strings(char text_line[], const char sub_start[], const char sub_end, char** sub_strings, int sub_count) {
    int sub_index = 0;
    char *cursor = NULL; 
    char *end = NULL;

    //memory alocation is happening within this part of the code which is wrong and instead the memory should be alocated before this function.
    if (sub_count > 0) {
        cursor = strstr(text_line, sub_start);
        while (cursor != NULL) {
            end = strchr(cursor, sub_end) + 1;
            int sub_length = (end - cursor);
            sub_strings[sub_index]  = (char *) malloc(sub_length + 1);
            for (int i = 0; i < sub_length; ++i) {
                sub_strings[sub_index][i] = cursor[i];
                if (sub_strings[sub_index][i] == sub_end) {
                    sub_strings[sub_index][i+1] = '\0';
                }
            }    
            cursor = strstr(end + 1, sub_start);
            sub_index++;
        }
    } 

    return sub_strings;
}



int main(){
//the code is using a costant buffer size of 100 this have to be changed
// i need to use malloc to alocate the memory for the character array named buff 
    const int BUFF_SIZE = 100;
    char buff[BUFF_SIZE];
    char **links = NULL;
    char **sub_strings;
    int sub_count;

    int link_count = 0;
    // it should search only stuff inside "" for example "www.google.com" and not "<a www.google.com" <a/>
    // so the best solution to do this would be to get substrings after href= and between the quotes "" 
    const char START[] = "<a";
    const char END = '>';
 
    while (fgets(buff, sizeof(buff), stdin) != NULL ) {
        int length = strlen(buff);
        if (buff[length - 1] == '\n') {
            link_count = count_sub_strings(buff, START);
            
            if (link_count > 0) {
                sub_count = count_sub_strings(buff, START);
                sub_strings = malloc(sizeof(char*) * (sub_count) );
                links = get_sub_strings(buff, START, END, sub_strings, sub_count);

                for (int i = 0; i < link_count; ++i) {
                    printf("%s\n", links[i]);
                    free(links[i]);
                }
                free(sub_strings);                
            }
        }
    }

  return 0;
}
