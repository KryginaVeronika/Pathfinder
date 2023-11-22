#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x < 0)
        return 0;
    double guess = x / 2.0;
    double prev_guess = 0.0;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    }
    int guess_nat = guess;
    if(guess == guess_nat)
        return guess;
    else
        return 0;
}

