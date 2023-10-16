// Minesweeper program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/errno.h>

// Declare Functions
void usage (char *);

char processElement(int wid, int hei, char[wid][hei], int, int);


int main(int argc, char *argv[]) {

  // File Initialization
  FILE *inputFile = NULL;

  if (argc != 2) usage (argv[0]);

  if (NULL == (inputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
    fprintf (stderr, "%s opened for reading.\n" , argv[1]);
  }

  int iteration = 1;
  while (true) {
    // Get input from file
    int width, height;
    fscanf (inputFile, "%d %d", &height, &width);
    if (width == 0 && height == 0) break;

    printf ("Field #%d:\n", iteration); 
    iteration++;

    const int border = 2;
    const int offsetH = 1;
    const int offsetW = 1;

    char input[height + border][width + border];

    // Initialize to '.'
    for (int i = 0; i < height + border; i++) {
      for (int j = 0; j < width + border; j++) {
        input[i][j] = '.';
      }
    }

    // Get input
    char temp[width][height];
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width + 1; j++) {
        char c = fgetc(inputFile);
        if (c != '\n') {
          input[i + 1][j] = c;
        }
      }
    }
    
    // Process elements of the array
    for (int i = 1; i < height + 1; i++) {
      for (int j = 1; j < width + 1; j++) {
        input[i][j] = processElement(height + border, width + border, input, i, j);
      }
    }

    // Print output
    for (int i = 1; i < height + 1; i++) {
      for (int j = 1; j < width + 1; j++) {
        printf ("%c", input[i][j]);
      }
      printf ("\n");
    }
    printf ("\n");
  
  }
  

  // Close input files
  fclose (inputFile);
  
  return 0;
}

// Define Functions
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

char processElement(int hei, int wid, char el[hei][wid], int h, int w) {
  if (el[h][w] == '*') {
    return '*';
  }
  else {
    
    int num = 0;
    if (el[h - 1][w -1] == '*') num++;
    if (el[h - 1][w] == '*') num++;
    if (el[h - 1][w + 1] == '*') num++;
    
    if (el[h][w - 1] == '*') num++;
    if (el[h][w + 1] == '*') num++;
    
    if (el[h + 1][w - 1] == '*') num++;
    if (el[h + 1][w] == '*') num++;
    if (el[h + 1][w + 1] == '*') num++;

    return num + '0';
  }
}