/*
 * =====================================================================================
 *
 *       Filename:  treesLevel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/13 11:49:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#define _GNU_SOURCE
#define MAX_ERROR_MSG 0x1000
#include "amplitud.h"
#include <errno.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  procesarLinea
 *  Description:  
 * =====================================================================================
 */
/* Compile the regular expression described by "regex_text" into
   "r". */

static int compile_regex (regex_t * r, const char * regex_text)
{
    int status = regcomp (r, regex_text, REG_EXTENDED|REG_NEWLINE);
    if (status != 0) {
	char error_message[MAX_ERROR_MSG];
	regerror (status, r, error_message, MAX_ERROR_MSG);
        printf ("Regex error compiling '%s': %s\n",
                 regex_text, error_message);
        return 1;
    }
    return 0;
}

/*
  Match the string in "to_match" against the compiled regular
  expression in "r".
 */

static int match_regex (regex_t * r, const char * to_match, Arbol a)
{
    /* "P" is a pointer into the string which points to the end of the
       previous match. */
    const char * p = to_match;
    /* "N_matches" is the maximum number of matches allowed. */
    const int n_matches = 258;
    /* "M" contains the matches found. */
    regmatch_t m[n_matches];

    while (1) {
        int i = 0;
        int nomatch = regexec (r, p, n_matches, m, 0);
				char *elem;
				char *camino;
        if (nomatch) {
            return nomatch;
        }
        for (i = 0; i < n_matches; i++) {
            int start;
            int finish;
            if (m[i].rm_so == -1) {
                break;
            }
            start = m[i].rm_so + (p - to_match);
            finish = m[i].rm_eo + (p - to_match);

						switch (i) {
							case 1:	
								asprintf(&elem, "%.*s", (finish - start), to_match + start );
								break;

							case 2:	
								asprintf(&camino, "%.*s", (finish - start), to_match + start );
								break;

							default:	
								break;
						}				/* -----  end switch  ----- */
        }
								Insertar(a,atoi(elem),camino); 
        p += m[0].rm_eo;
    }
    return 0;
}

void procesarLinea(char *line)
{
    regex_t r;
    const char * regex_text;
    const char * find_text;
		Arbol a = nuevoArbol();
		regex_text = "\\(([[:digit:]]*),([[:upper:]]*)\\)";
    compile_regex(& r, regex_text);
    match_regex(& r, line,a);
		int ver = verificar(a);
		if (ver==1) {
			printf("Incompleto\n");
		}
		else {
			amplitud(a);
		}
    regfree (& r);
		free(a);
}

static int match_regex2 (regex_t * r, const char * to_match)
{
    const char * p = to_match;
    const int n_matches = 10;
    regmatch_t m[n_matches];
		int nomatch = regexec (r, p, n_matches, m, 0);
		return nomatch;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  concatenar
 *  Description:  
 * =====================================================================================
 */
char *
concatenar ( char * dest, char * fuent )
{
	char *c = malloc(strlen(dest) + strlen(fuent) + 1);
	strcpy(c, dest);
	strcat(c, fuent);
//	puts(c);
//	free(c);
//	*strArbol=c;
	return c;
}		/* -----  end of function concatenar  ----- */

	

int main(int argc, char *argv[]) {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char * strArbol="";

	regex_t r;
	compile_regex(& r, "\\(\\)");

	if (argc != 2) {
		puts("Se debe pasar exactamente un argumento.");
		exit(EX_USAGE);
	}
	fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("El archivo no existe; fopen");
    exit(EX_USAGE);
  }
//	printf ("%s",concatenar("hola,","chao"));
	while ((read = getline(&line, &len, fp)) != -1) {
//			printf("dos: %s\n",line);
		strArbol = (char *)concatenar(strArbol,line);
		if (match_regex2(&r,line)==0){
//			printf("%s",strArbol);
//			printf("uno: %s\n",strArbol);
			procesarLinea(strArbol);
			strArbol="";
		}
	}

	if (line)
	 	 free(line);
	exit(EXIT_SUCCESS);
}

