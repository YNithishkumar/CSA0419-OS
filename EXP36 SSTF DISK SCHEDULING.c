#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int abs(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int findClosestTrack(int tracks[], int n, int head) {
    int minDist = INT_MAX;
    int closestTrack = -1;

    for (int i = 0; i < n; i++) {
        if (abs(tracks[i], head) < minDist) {
            minDist = abs(tracks[i], head);
            closestTrack = i;
        }
    }

    return closestTrack;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50;
    int totalHeadMovement = 0;

    printf("Track Positions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    printf("Initial Head Position: %d\n", head);

    for (int i = 0; i < n; i++) {
        int closestTrack = findClosestTrack(tracks, n, head);
        int distance = abs(tracks[closestTrack], head);
        totalHeadMovement += distance;
        head = tracks[closestTrack];
        tracks[closestTrack] = INT_MAX; // Mark the track as visited
        printf("Move head to track %d. Head movement: %d\n", head, distance);
    }

    printf("Total head movement: %d\n", totalHeadMovement);
    printf("Average head movement: %.2f\n", (float)totalHeadMovement / n);

    return 0;
}

