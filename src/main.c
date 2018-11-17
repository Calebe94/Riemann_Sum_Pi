#include <stdio.h>
#include <math.h>

double circle_pi(int rectangles);

double recursion_rect_area(int rectangles, int index, double radius, double width, double height, double midpoint, double rect_area);

double calc_rect_area(int rectangles);

int main(void)
{
    printf("Approximations for pi\n");
    printf("-----------|LOOP|-------------\n");
    printf("Iterations      Circle Method \n");

    for (int index = 1; index <= 100000; index *= 10)
    {
        double pi_circle = circle_pi(index);

        printf("%10i%20.12f\n", index, pi_circle);
    }

    printf("\n");

    printf("Approximations for pi\n");
    printf("---------|RECURSION|----------\n");
    printf("Iterations      Circle Method \n");

    for (int index = 1; index <= 100000; index *= 10)
    {
        double pi_circle = calc_rect_area(index);
        printf("%10i%20.12f\n", index, pi_circle);
    }

    return 0; 
}

double circle_pi(int rectangles)
{
    double radius = 2.0;
    double width = radius / (double)rectangles;
    double rect_area = 0.0;
    double midpoint, height;

    midpoint = width / 2.0;

    for(int index = 1; index <= rectangles; index++)
    {
        height = sqrt((radius * radius) - (midpoint * midpoint));
        midpoint = midpoint + width;
        rect_area = rect_area + width * height;
    }
    return rect_area;
}

double calc_rect_area(int rectangles)
{
    double radius = 2.0;
    int index = 1;
    double width = radius / (double)rectangles;
    double rect_area = 0.0;
    double midpoint = 0.0;
    double height = 0.0;
    
    midpoint = width / 2.0;

    return recursion_rect_area(rectangles, index, radius, width, height, midpoint, rect_area);
}

double recursion_rect_area(int rectangles, int index, double radius, double width, double height, double midpoint, double rect_area)
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
    return recursion_rect_area(rectangles, index, radius,  width,  height,  midpoint,  rect_area);
}