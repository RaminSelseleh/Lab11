#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadDictionary(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open dictionary");
	    exit(1);
	}
	
	// TODO
    int cap = 10;
    int other = 0; 

	// Allocate memory for an array of strings (arr).
    char **arr = malloc(cap * sizeof(char*));

	// Read the dictionary line by line.
    char line[255];
    while(fgets(line, 255, in) != NULL) {

        char *nl = strchr(line, '\n');
        if (nl != NULL) *nl = '\0';

	// Expand array if necessary (realloc).
        if (other >= cap) {
            cap += 10;
            arr = realloc(arr, cap * sizeof(char*));
        }

	// Allocate memory for the string (str).
        char * str = malloc((strlen(line) + 1) * sizeof(char));

	// Copy each line into the string (use strcpy).
        strcpy(str, line);

	// Attach the string to the large array (assignment =).
        arr[other] = str;
        other++;
    } 

	// The size should be the number of entries in the array.
	*size = other;

	// Return pointer to the array of strings.
	return arr;
}

// Search the dictionary for the target string
// Return the found string or NULL if not found.
char * searchDictionary(char *target, char **dictionary, int size)
{
    if (dictionary == NULL) return NULL;
    
	for (int i = 0; i < size; i++)
	{
	    if (strcmp(target, dictionary[i]) == 0)
	    {
	        return dictionary[i];
	    }
	}
	return NULL;
}
