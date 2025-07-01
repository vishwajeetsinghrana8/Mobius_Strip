#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define NUM_U 100
#define NUM_V 20

int main() {
    FILE *fp = fopen("mobius_strip.obj", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    double R = 1.0;        // Radius of the central circle
    double width = 0.3;    // Half-width of the strip

    // Generate vertices
    for (int i = 0; i < NUM_U; i++) {
        double u = (double)i / (NUM_U - 1) * 2 * PI;
        for (int j = 0; j < NUM_V; j++) {
            double v = ((double)j / (NUM_V - 1) - 0.5) * 2 * width;

            // Möbius parametric equations
            double x = (R + v * cos(u / 2)) * cos(u);
            double y = (R + v * cos(u / 2)) * sin(u);
            double z = v * sin(u / 2);

            fprintf(fp, "v %lf %lf %lf\n", x, y, z);
        }
    }

    // Generate faces (quads as two triangles)
    for (int i = 0; i < NUM_U - 1; i++) {
        for (int j = 0; j < NUM_V - 1; j++) {
            int idx1 = i * NUM_V + j + 1;
            int idx2 = (i + 1) * NUM_V + j + 1;
            int idx3 = (i + 1) * NUM_V + (j + 1) + 1;
            int idx4 = i * NUM_V + (j + 1) + 1;

            fprintf(fp, "f %d %d %d\n", idx1, idx2, idx3);
            fprintf(fp, "f %d %d %d\n", idx1, idx3, idx4);
        }
    }

    fclose(fp);
    printf("Möbius strip model saved to 'mobius_strip.obj'\n");

    return 0;
}
