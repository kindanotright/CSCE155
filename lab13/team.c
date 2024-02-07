#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <monetary.h>

#include "team.h"

const int NUM_TEAMS = 16;

void initTeam(Team *t, char *name, int wins, int loss, char *city, char *state,
                 double payroll, double aveSalary) {
  t->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(t->name, name);
  t->wins = wins;
  t->loss = loss;
  t->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
  strcpy(t->city, city);
  t->state = (char *)malloc(sizeof(char) * (strlen(state) + 1));
  strcpy(t->state, state);
  t->payroll = payroll;
  t->averageSalary = aveSalary;

}


void printTeam(const Team *t) {
  if (t == NULL) {
    printf("null\n");
    return;
  }
  double winPerc = 100.0 * t->wins / (double)(t->wins + t->loss);
  printf("%-10s %3d  %3d (%5.2f) %-15s %2s $%12.2f $%9.2f\n", t->name, t->wins,
         t->loss, winPerc, t->city, t->state, t->payroll, t->averageSalary);
}


void printAllTeams(Team *teams, int size) {
  int i;
  printf("%-9s %-4s %-4s (%-4s) %-12s %-2s %-13s %-11s\n", "Name", "Wins",
           "Loss", "Win %", "City", "State", "Payroll", "Avg Salary");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  for (i = 0; i < size; i++) {
    printTeam(&teams[i]);
  }
  printf("\n\n");
}


Team *readCsvFile(const char *fileName) {
  Team *teams = (Team *)malloc(sizeof(Team) * NUM_TEAMS);

  FILE *instream = fopen(fileName, "r");
  if (instream == NULL) {
    return NULL;
  }

  // read the file, line by line
  int i = 0;
  int size = 1000;
  char *tempBuffer = (char *)malloc(sizeof(char) * size);

  // discard first line (headers)
  fgets(tempBuffer, size, instream);
  while (fgets(tempBuffer, size, instream) != NULL && i < NUM_TEAMS) {
    char name[100];
    int wins, loss;
    char *city, *state;
    double payroll, averageSalary;
    // remove the endline character from the line
    tempBuffer[strlen(tempBuffer) - 1] = '\0';
    char *teamToken = strtok(tempBuffer, ",");
    strcpy(name, teamToken);
    wins = atoi(strtok(NULL, ","));
    loss = atoi(strtok(NULL, ","));
    city = strtok(NULL, ",");
    state = strtok(NULL, ",");
    payroll = atof(strtok(NULL, ","));
    averageSalary = atof(strtok(NULL, ","));
    initTeam(&teams[i], name, wins, loss, city, state, payroll, averageSalary);
    i++;
  }
  fclose(instream);

  free(tempBuffer);

  return teams;
}


void bubbleSortTeams(Team *teams, int size,
                     int (*compar)(const void *, const void *)) {
  Team temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      // compare adjacent teams by asking the compar function passed in:
      if (compar(&teams[j], &teams[j + 1]) > 0) {
        // swap them...
        temp = teams[j];
        teams[j] = teams[j + 1];
        teams[j + 1] = temp;
      }
    }
  }
}

//TODO : this thing below
void selectionSortTeamsByPayroll(Team *teams, int size) {
  if(teams == NULL) {
    return;
  }
  Team temp;
  for (int i = 0; i < size - 1; i++) {
    // Find index of smallest remaining element
    int indexSmallest = i;
    for (int j = i + 1; j < size; j++) {
      if (teams[j].payroll < teams[indexSmallest].payroll) {
        indexSmallest = j;
      }
    }
    // Swap numbers[i] and numbers[indexSmallest]
    temp = teams[i];
    teams[i] = teams[indexSmallest];
    teams[indexSmallest] = temp;
  }
}


void selectionSortTeams(Team *teams, int size,
                        int (*compar)(const void *, const void *)) {
  // TODO: implement this function
  if(teams == NULL) {
    return;
  }
  Team temp;
  for (int i = 0; i < size - 1; i++) {
    // Find index of smallest remaining element
    int indexSmallest = i;
    for (int j = i + 1; j < size; j++) {
      if (teams[j].payroll < teams[indexSmallest].payroll) {
        indexSmallest = j;
      }
    }
    // Swap numbers[i] and numbers[indexSmallest]
    temp = teams[i];
    teams[i] = teams[indexSmallest];
    teams[indexSmallest] = temp;
  }
}


int teamComparisonByName(const void *s1, const void *s2) {
  const Team *t1 = (const Team *)s1;
  const Team *t2 = (const Team *)s2;
  int result = strcmp(t1->name, t2->name);
  return result;
}


int teamComparisonByState(const void *s1, const void *s2) {
  const Team *t1 = (const Team *)s1;
  const Team *t2 = (const Team *)s2;
  return strcmp(t1->state, t2->state);
}


int teamComparisonByStateCity(const void *s1, const void *s2) {
  const Team *t1 = (const Team *)s1;
  const Team *t2 = (const Team *)s2;
  if (strcmp(t1->state, t2->state) == 0) {
    return strcmp(t1->city, t2->city);
  } else {
    return strcmp(t1->state, t2->state);
  }
}


int teamComparisonByWinPercentage(const void *s1, const void *s2) {
  const Team *t1 = (const Team *)s1;
  const Team *t2 = (const Team *)s2;
  double t1_winPer = t1->wins / (double)(t1->wins + t1->loss);
  double t2_winPer = t2->wins / (double)(t2->wins + t2->loss);

  if (t1_winPer < t2_winPer) {
    return 1;
  } else if (t1_winPer == t2_winPer) {
    return 0;
  } else {
    return -1;
  }
}


// TODO: implement your own comprator function to order
//      Teams by payroll in descending order (and any others as
//      directed); be sure to add your function prototype to
//      the team.h header file!
int cmp(const void *a, const void *b){
  if(a < b) {
    return -1;
  }
  if(a == b) {
    return 0;
  }
  if (a > b) {
    return 1;
  }
}


/**void qsort(void *base, size_t nmemb, size_t size,
    int(*compar)(const void *, const void *)){

    }


int Partition(int numbers[], int i, int k) {
   int l;
   int h;
   int midpoint;
   int pivot;
   int temp;
   bool done;

    //Pick middle element as pivot
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];

   done = false;
   l = i;
   h = k;

   while (!done) {

      //Increment l while numbers[l] < pivot
      while (numbers[l] < pivot) {
         ++l;
      }

      //Decrement h while pivot < numbers[h]
      while (pivot < numbers[h]) {
         --h;
      }

      //If there are zero or one elements remaining, all numbers are partitioned. Return h
      if (l >= h) {
         done = true;
      }
      else {
         // Swap numbers[l] and numbers[h], update l and h
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;

         ++l;
         --h;
      }
   }

   return h;
}


void Quicksort(int numbers[], int i, int k) {
   int j;

   // Base case: If there are 1 or zero elements to sort, partition is already sorted
   if (i >= k) {
      return;
   }

   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = Partition(numbers, i, k);

   //Recursively sort low partition (i to j) and high partition (j + 1 to k)
   Quicksort(numbers, i, j);
   Quicksort(numbers, j + 1, k);
}
**/
