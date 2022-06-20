#include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #define  SIZE 255 
    /************************************************/

    /*                                              */

    /*  C program for printing lines of source      */

    /*  Miguel santana
    *   5732399                                      */

    /*************************************************/
    int main() 
    { 
        FILE *fptr; 
        FILE *outfile;
        int count = 1;
        char choice = 'N';
        char filename[100] = "listsource.c", c; 
        char outfilename[100] = "output.txt";
        printf("Do you wish to enter a file name? (type Y/y for a yes answer)");
        scanf("%c", &choice);
        if(choice == 'Y' || choice == 'y'){
        printf("Enter the filename to open \n"); 
        scanf("%s", filename);
        }   
        printf("Enter the output file \n");
        scanf("%s", outfilename); 
       
        fptr = fopen(filename, "r"); 
        outfile = fopen(outfilename, "w");
        if (fptr == NULL) 
        { 
            printf("Cannot open file \n"); 
            exit(0); 
        } 
  

        c = fgetc(fptr); 
        fprintf(outfile, "\r%d/", count);
        while (c != EOF) 
        {
        	fprintf(outfile, "%c", c);
            if(c == '\n'){
            fprintf(outfile, "\r%d/", count + 1);
            printf ("\r%d/",count);
            count++; 
        }
            
            printf ("%c", c);
            c = fgetc(fptr); 
    
        } 
        fclose(fptr); 
        return 0; 
    }
