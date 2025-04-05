#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATIONS 1000
#define PRECISION 1e-9

double compute_time(double k, int n, int distances[], int speeds[]) {
    double total_time = 0;
    for (int i = 0; i < n; i++) {
        if (speeds[i] + k <= 0) {
            return INFINITY;
        }
        total_time += (double)distances[i] / (speeds[i] + k);
    }
    return total_time;
}

double find_k(int n, int distances[], int speeds[], double target_time) {
    double low = -1000, high = 1000, mid;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        mid = (low + high) / 2.0;
        double time_at_mid = compute_time(mid, n, distances, speeds);

        if (fabs(time_at_mid - target_time) < PRECISION) {
            return mid;
        }

        if (time_at_mid > target_time) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return mid;
}

int main() {
    int n, total_time;
    scanf("%d %d", &n, &total_time);

    int distances[n], speeds[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &distances[i], &speeds[i]);
    }

    double k = find_k(n, distances, speeds, total_time);

    printf("%.9lf\n", k);

    return 0;
}