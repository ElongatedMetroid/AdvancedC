#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void handleAlarm(int signum){
   printf("\nYou have waited longer than 5 seconds to put an answer\n");
   raise(SIGINT);
}

void handleQuit(int signum){
   printf("\nFinal Score ... %d\n", score);
   exit(EXIT_SUCCESS);
}

int main() {

   srand (time(0));
   
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[5];

      alarm(5);
      signal(SIGALRM, handleAlarm);
      signal(SIGINT, handleQuit);

      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 5, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
   }

   return 0;
} 