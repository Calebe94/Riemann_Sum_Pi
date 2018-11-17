#include <stdio.h>
#include <math.h>

typedef struct {
    double radius;
    double width;
    double height;
    double midpoint;
    double rect_area;
}r_midpoint;

double circle_pi(int rectangles);  /* Calculates PI using a quarter circle */

double calc_rect_area(int rectangles, r_midpoint *aux);

double recursion_rect_area();

int main(void)
{
    int i; /* loop counter */

    printf("Approximations for pi\n");
    printf("Iterations      Circle Method \n");
    printf("-----------|LOOP|-------------\n");

    for (i = 1; i <= 1000000; i *= 10)
    {
        double pi_circle = circle_pi(i);

        printf("%10i%20.12f\n", i, pi_circle);
    }
    printf("\n");

    printf("Approximations for pi\n");
    printf("Iterations      Circle Method \n");
    printf("---------|RECURSION|----------\n");

    for (i = 1; i <= 1000000; i *= 10)
    {
        r_midpoint aux;
        aux.radius = 2.0;
        aux.width = aux.radius / (double)i;
        aux.midpoint = aux.width / 2.0;
        double pi_circle = calc_rect_area(i, &aux);
        printf("%10i%20.12f\n", i, pi_circle);
    }

  return 0; /* Return success to the OS */
}

double circle_pi(int rectangles)
{
    double radius = 2.0;
    int i;
    double width = radius / (double)rectangles;
    double rect_area = 0.0;
    double midpoint, height;
    // set startvalue of mipoint
    midpoint = width / 2.0;

    for(i = 1; i <= rectangles; i++)
    {
        height = sqrt((radius * radius) - (midpoint * midpoint));
        midpoint = midpoint + width;
        rect_area = rect_area + width * height;
    }
    return rect_area;
}

double calc_rect_area(int rectangles, r_midpoint *aux)
{
    static int i = 0;

    if(i < rectangles)
    {
        aux->height = sqrt((aux->radius * aux->radius) - (aux->midpoint * aux->midpoint));
        aux->midpoint = aux->midpoint + aux->width;
        aux->rect_area = aux->rect_area + (aux->width * aux->height);
        i++;
        return calc_rect_area(rectangles, aux);
    }
    else
    {
        return aux->rect_area;
    }
}