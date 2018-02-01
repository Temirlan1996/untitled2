#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


  const char * const all[] = {"--ch","--kill","--sv"};
  const int const size = sizeof(all)/sizeof(all[0]);

void name() {
    printf("%s\n", "HELP");
  return;
}


void validateFlags(const char * const flags[], const int const arr) {

  bool flagExist = false;
  int incorrect = -1;

  for (int i = 1; i < arr; i++) {
    flagExist = false;

    for (int j = 0; j < size; j++) {
      if (strcmp(flags[i],all[j]) == 0) {
        flagExist = true;
        incorrect = -1;

        printf("%s\n", "[+] Allowed Flags");
        printf("Flags: %s == Arg: %s\n", flags[i], all[j]);
      }
      else{
        incorrect = i;
      }
    }
      if (!flagExist) {
        printf("%s\n Incorrect: %s\n", "Error: Not allowed flags!!! ",flags[incorrect]);
        exit(EXIT_FAILURE);
      }
  }
  return;
}

int main(int argc, char const *argv[]) {

  if(argc > 1) {
    validateFlags(argv,argc);
  }else{
     printf("%s\n", "I Don`t argument!!!");
  }

 return EXIT_SUCCESS;
}
