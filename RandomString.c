#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// length of array
#define LEN 6

// Helper function that sorts an array
void bucket_sort(unsigned char* array);

// Helper function that returns a random integer in the specified range [min, max]
int random(int min, int max);

// Returns a random ascii character code
unsigned char get_random_char(void);

// A recursive function that cycles through the elements of an array starting
// at the beginning and prints each element as a char.
void rec_print_array(unsigned char* array, int index);

// Sets up the character array and prints it to console
int main() {
  // seed random calls
  srand(time(NULL));
  // create an array and initialize its elements
  unsigned char rand_ar[LEN];
  for (int i = 0; i < LEN; i++) {
    rand_ar[i] = get_random_char();
  }
  // sort the array
  bucket_sort(rand_ar);
  // print characters in the array
  rec_print_array(rand_ar, 0);
  return EXIT_SUCCESS;
}

void bucket_sort(unsigned char* array) {
  // Initializes temp to an array with its size as the largest unsigned char value + 1
  unsigned char* temp = (unsigned char*) calloc(UCHAR_MAX + 1, sizeof(unsigned char));
  if (temp == NULL) {
    return;
  }
  // Each index in temp is increased the number of times that index appears
  // as an element in array
  for (int i = 0; i < LEN; i++) {
    temp[array[i]]++;
  }
  // Copies each element, now in sorted order, to array
  int curr_index = 0;
  for (int i = 0; i < UCHAR_MAX + 1; i++) {
    for (int j = 0; j < temp[i]; j++) {
      array[curr_index] = i;
      curr_index++;
    }
  }
  free(temp);
}

int random(int min, int max) {
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

unsigned char get_random_char() {
  // set character equal to a random integer between 0 and 25
  int character = random(0, 25);
  return (unsigned char) character + 97;  // return the ascii code of a lowercase letter
}

void rec_print_array(unsigned char* array, int index) {
  if (index >= LEN) {
    printf("\n");
    return;
  } else {
    printf("%c", array[index]);
    rec_print_array(array, index + 1);
  }
}
