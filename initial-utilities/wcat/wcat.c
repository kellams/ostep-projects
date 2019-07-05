/*
  Takes in a list of files as arguments
  Prints contents of files to stdout
  If a file cannot be opened, returns with status 1 and prints "wcat: cannot open file"
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++){
        FILE *file = fopen(argv[i], "r");
        if (file == NULL){
            printf("wcat: cannot open file\n");
            return 1;
        } else{
            char *s = malloc( 255 * sizeof(char) );
            char *c;
            do {
                c = fgets(s, sizeof(s), file);
                if (c != NULL)
                  printf("%s", s);
            } while(c != NULL);
            free(s);
            fclose(file);
        }
    }

    return 0;
}
