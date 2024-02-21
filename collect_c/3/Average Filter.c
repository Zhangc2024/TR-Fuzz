#include <stdio.h>

int movingAvg(int *ptrArrNumbers, long *ptrSum, int pos, int len, int nextNum)
{
  //Subtract the oldest number from the prev sum, add the new number
  *ptrSum = *ptrSum - ptrArrNumbers[pos] + nextNum;
  //Assign the nextNum to the position in the array
  ptrArrNumbers[pos] = nextNum;
  //return the average
  return *ptrSum / len;
}

int main(int argc, char *argv[])
{
  // a sample array of numbers. The represent "readings" from a sensor over time
  int sample[] = {50, 10, 20, 18, 20, 100, 18, 10, 13, 500, 50, 40, 10};
  // the size of this array represents how many numbers will be used
  // to calculate the average
  int arrNumbers[5] = {0};
	int i = 0;
  int pos = 0;
  int newAvg = 0;
  long sum = 0;
  int len = sizeof(arrNumbers) / sizeof(int);
  int count = sizeof(sample) / sizeof(int);

  for(i = 0; i < count; i++){
    newAvg = movingAvg(arrNumbers, &sum, pos, len, sample[i]);
    printf("The new average is %d\n", newAvg);
    pos++;
    if (pos >= len){
      pos = 0;
    }
  }

  return 0;
}
