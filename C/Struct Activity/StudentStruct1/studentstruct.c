
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DOB(int month, int day, int year);

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int iflag = 0, mflag = 0, dflag = 0, yflag = 0, cflag = 0, gflag= 0;
	char *Firstname = "", *Lastname = "";
	char *ID = "0";
	int day = 0, month = 0, year = 0, class = 1;
	float gpa = 3.00;
	static char usage[] = "usage: %s -i StudentID -m month -d day -y year -c class -g gpa Firstname Lastname \n";

	while ((c = getopt(argc, argv, "i:m:d:y:c:g:")) != -1)
		switch (c) {
		case 'i':
			iflag = 1;
			ID = optarg;
			if(strlen(ID) != 7){
 			printf("Invalid ID\n");
			exit(1);
			}
			break;
		case 'm':
			mflag = 1;
			month = atoi(optarg);
			break;
		case 'd':
			dflag = 1;
         	day = atoi(optarg);
			break;
		case 'y':
			yflag = 1;
			year = atoi(optarg);
			break;
		case 'c':
			cflag = 1;
			class = atoi(optarg);
			break;
		case 'g':
			gflag = 1;
			gpa = atof(optarg);
			break;
		case '?':
			err = 1;
			break;
		}
	if (iflag == 0) {
		fprintf(stderr, "%s: missing -i option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if ((optind) > argc) {	
		fprintf(stderr, "%s: missing ID\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (mflag == 0) {
		fprintf(stderr, "%s: missing -m option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
    }  else if ((optind) > argc) {	
		fprintf(stderr, "%s: missing month\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (dflag == 0) {
		fprintf(stderr, "%s: missing -d option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
    } else if ((optind) > argc) {	
		fprintf(stderr, "%s: missing day\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}  else if (yflag == 0) {
		fprintf(stderr, "%s: missing -y option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
    }  else if ((optind) > argc) {	
		fprintf(stderr, "%s: missing year\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}

	if (optind < argc)	/* these are the arguments after the command-line options */
		for (; optind <= argc - 2; optind++){
			Firstname = argv[optind];
			optind++;
			Lastname = argv[optind];
}	
	printf("Name: %s %s\n", Firstname, Lastname);
	printf("Student ID: %s\n", ID);
        DOB(month, day, year);
	switch(class){
		case 1:
		printf("Standing: Freshman\n");
		break;
		case 2:
		printf("Standing: Sophomore\n");
		break;
		case 3:
		printf("Standing: Junior\n");
		break;
		case 4:
		printf("Standing Senior\n");
		break;
		default:
		printf("Invalid class\n");		
}
	printf("GPA: %.2f\n", gpa);
	exit(0);
}

void DOB(int month, int day, int year){
        if(year <= 999 || year >= 9999){
		printf("Wrong year input\n");
		exit(1); 
	}
	if(day <= 0 || day >= 32){
		printf("Wrong day input\n");
		exit(1);
	}
	switch(month){
		case 1:
		printf("Jan/%d/%d\n", day, year);
		break;
		case 2:
		printf("Feb/%d/%d\n", day, year);
		break;
		case 3:
		printf("Mar/%d/%d\n", day, year);
		break;
		case 4:
		printf("Apr/%d/%d\n", day, year);
		break;
		case 5:
		printf("May/%d/%d\n", day, year);
		break;
		case 6:
		printf("Jun/%d/%d\n", day, year);
		break;
		case 7:
		printf("Jul/%d/%d\n", day, year);
		break;
		case 8:
		printf("Aug/%d/%d\n", day, year);
		break;
		case 9:
		printf("Sep/%d/%d\n", day, year);
		break;
		case 10:
		printf("Oct/%d/%d\n", day, year);
		break;
		case 11:
		printf("Nov/%d/%d\n", day, year);
		break;
		case 12:
		printf("Dec/%d/%d\n", day, year);
		break;
		default:
		printf("Wrong month input\n");
		exit(1);
	}

}
