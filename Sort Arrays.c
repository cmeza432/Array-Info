#include <stdio.h>

double array_mean(double arr[], int num_items)
{
  int n = 0;
  double result = 0.0;
  for(n; n <= num_items; n++)
  {
	  result += arr[n];										/*loops through each value while adding it to result*/
  }
  return (result/num_items);								/*returns value sum by number of items in array to find median*/
}

double array_median(double arr[], int num_items)
{
  int mid;
  double result;
  if(num_items % 2 == 0)									/*Checks if number is even or odd with modulo*/
  {
	  mid = (num_items/2) - 1;							/*Gets halfway point of array*/
	  result = (arr[mid + 1] + arr[mid]) / 2;			/*Gets median value by finding halfway point of both middle numbers*/
  }
  else
  {
	  mid = (num_items/2) + .5;							/*Finds middle position by dividng in half*/
	  result = arr[mid];										
  }
  return result;
}

void sort_array(double arr[], double sorted[], int num_items)
{
  int i =0;
  int x = 0;
  int y;
  sorted[i] = arr[i];
  while(i < num_items)										/*Loops and copies each value of original array*/
  {
	  i++;
	  sorted[i] = arr[i];
  }
  for(x; x < num_items;x++)								/*nested loops  to check each value number of times according to its length*/
  {
	  y = 0;
	  for(y; y < (num_items - 1); y++)
	  {
		  if(sorted[y] > sorted[y+1])						/*Checks to see if value to the left is greater than value to its right*/
		  {
			  double temp = sorted[y+1];					/*Makes temp value and swaps values in array from left to right if bigger*/
			  sorted[y+1] = sorted[y];
			  sorted[y] = temp;
		  }
	  }
  }
}

int main(void)
{
  int i = 0;
  double a[3][5] = {{3.2, 1.5, 7.9, 12.1, -1.0},
                  {-1.0, 5.0, 4.9, 3.3, 12.23},
                  {0.0, 1.2, 12.9, 45.1, 2.0}};
                  
  int cols = sizeof(a[0])/sizeof(double);
  
  for (i = 0; i < 3; i++)
  {
    double mean, median;
    double sorted[5] = {0.0};
    sort_array(a[i], sorted, cols);
    mean = array_mean(a[i], cols);
    median = array_median(sorted, cols);
    
    printf("Row %d\nMean: %.2f\nMedian: %.2f\n\n", i, mean, median);
  }
  
  return 0;
}
