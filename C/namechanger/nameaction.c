        #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>

	char *nameacted(char *action, char *first, char *last){
		char *name = malloc(sizeof(*name) * strlen(first) + strlen(last) + 1);
		int i;
		int j;
		strcat(name, first);
		strcat(name, " ");
		strcat(name, last);
		if(*action == 'l'){
			for(i = 0;i < strlen(name); i++){
				name[i] = tolower(name[i]);
			}
			return name;
		}
		else if(*action == 'u'){
		for(i = 0;i < strlen(name); i++){
			name[i] = toupper(name[i]);
		}
		return name;
		}
		else if(*action == 'r'){
		char temp;
		int j = 0;
		i = 0;
		j = strlen(name) - 1;
		while (i < j){
			temp = name[j];
			name[j] = name[i];
			name[i] = temp;
			i++;
			j--;
		}
		return name;
		}
		else if(*action == 's'){
		char *namewithspace = malloc(sizeof(*namewithspace) * strlen(name) * 2);
		j = 0;
		for(i = 0; i< strlen(name); i++){
			namewithspace[j] = name[i];
			j++;
			namewithspace[j] = ' ';
			j++;
		}
		namewithspace[j] = '\0';
		return namewithspace;
	}else
	return "Sorry, but that is not an option for -m";
	}
