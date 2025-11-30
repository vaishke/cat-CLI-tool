#include <stdio.h>

void cat(char *filename);

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Usage: cat filename\n");
        printf("Displays the contents of the file.\n");
        return 1;
    }

    char *filename = argv[1];

    printf("file: \t%s\n", filename);
    cat(filename);
    printf("\n");

    return 0;
}

void cat(char *filename) {
    FILE *fp = fopen(filename, "r");
    int c;

    if(fp == NULL) {
        printf("Error: Cannot find file %s\n", filename);
        return;
    }

    while((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
}

