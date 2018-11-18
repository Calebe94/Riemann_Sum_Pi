//https://softwareengineering.stackexchange.com/questions/279004/general-way-to-convert-a-loop-while-for-to-recursion-or-from-a-recursion-to-a
//https://stackoverflow.com/questions/52693154/how-to-use-for-loop-to-calculate-midpoint-rule-riemann-sum-in-c
//http://blog.recursiveprocess.com/2013/03/14/calculate-pi-with-python/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_circle_pi(int rectangles);

double recursion_circle_pi(int rectangles, int index, double radius, double width, double height, double midpoint, double rect_area);

void show_usage();

int main(int arg, char *args[])
{
    if(arg < 2)
    {
        show_usage();
    }
    else
    {
        int iterations = atoi(args[1]);
        if( iterations > 500000 )
        {
            show_usage();
            return 1;
        }
        else
        {
            printf("\n");
            printf("Approximation for pi with %10i iterations:%20.12f\n", iterations, calc_circle_pi(iterations));
        }
    }
    return 0; 
}

void show_usage()
{
        printf("Riemann_Sum_Pi\n");
        printf("> This programm needs just one command line parameter,\n");
        printf("> and it's the number o cicles that will be used to find the approximation of pi value.\n");
        printf("> The execution time increases considerably with cicles greater than 800000, so the program limits the number of iterations at 500000\n");
        printf("> So the number of cicles should be less than 500000 (half million), Example: build/./riemann_sum 500\n");
        printf("> build/./riemann_sum 500\n");
}

double calc_circle_pi(int rectangles)
{
    double radius = 2.0;
    int index = 1;
    double width = radius / (double)rectangles;
    double rect_area = 0.0;
    double midpoint = 0.0;
    double height = 0.0;
    
    midpoint = width / 2.0;

    return recursion_circle_pi(rectangles, index, radius, width, height, midpoint, rect_area);
}

double recursion_circle_pi(int rectangles, int index, double radius, double width, double height, double midpoint, double rect_area)
{
    if(!(index <= rectangles))
    {
        return rect_area;
    }
    if(rectangles > 100000)
    {
        printf("%d - %20.12f\n",index, rect_area);
    }

    height = sqrt((radius * radius) - (midpoint * midpoint));
    midpoint = midpoint + width;
    rect_area = rect_area + width * height;
    index++;
    return recursion_circle_pi(rectangles, index, radius,  width,  height,  midpoint,  rect_area);
}