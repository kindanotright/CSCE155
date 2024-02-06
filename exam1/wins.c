/* Based off of points scored this program calulates how many wins and losses a team has and the average win rate.
 * Author: Megan Bogatz; kindanotright
 * 2023-09-22
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 
 
int main(int argc, char **argv){
 
  if(argc != 3) {
    printf("ERROR: provide all the inputs >:O\n");
    exit(1);
  }
  int homeTeam = atoi(argv[1]);
  int awayTeam = atoi(argv[2]);
 
  if (homeTeam <= 0 || awayTeam <= 0) {
    printf("ERROR: Please enter correcr input\n");
    exit(1);
  }
 
  double scoreAverage = pow(homeTeam, 2.37) / (pow(homeTeam, 2.37) + pow(awayTeam, 2.37));
  double winPercent = scoreAverage * 100;
  double winTotal = 12 * scoreAverage;
  double lossTotal = 12 - winTotal;
  winTotal = round(winTotal * 100) / 100;
  lossTotal = round(lossTotal * 100) / 100;
 
  printf("Win percentage: %.2lf%% \n", winPercent);
  printf("Win/Loss: %.lf/%.lf\n", winTotal, lossTotal);
 
  return 0;
}
