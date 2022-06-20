#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "nameaction.h"
int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int i;
	int c, err = 0; 
	int mflag = 0, rflag = 0;
	int repeat = 5;
	char *action;
	char *sname, *fname;
	static char usage[] = "usage: %s -m \"action\" [-r \"value\"] name [name ..]\n";

	while ((c = getopt(argc, argv, "m:r:")) != -1)
		switch (c) {
		case 'm':
			mflag = 1;
			action = optarg;
			break;
		case 'r':
			rflag = 1;
			repeat = atoi(optarg);
			if(repeat > 10 || repeat < 1){
				printf("Repeat value must be between 1 and 10\n");
				exit(0);
			}
			break;
            case '?':
			err = 1;
			break;
		}
		if(optind < argc){
		fname = argv[optind];
		sname = argv[optind+1];
		for(i = 0; i < repeat; i++){
		printf("%s\n", nameacted(action, fname, sname));
		}
		}else{
			printf("the program needs a first name and a last name as arguments\n");
		}
	if (mflag == 0) {	/* -m was mandatory */
		fprintf(stderr, "%s: missing -m option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if ((optind+1) > argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */

		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	exit(0);
}
