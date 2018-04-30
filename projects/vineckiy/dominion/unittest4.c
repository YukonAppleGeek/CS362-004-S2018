#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"

int testIsGameOverProvince();
int testIsGameOverSupply();

int main() {
    printf("Testing isGameOver\n");
    int fails = 0;

    fails += testIsGameOverProvince();
    fails += testIsGameOverSupply();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testIsGameOverProvince() {
    int fails = 0;
    struct gameState *state = newGame();

    int i = 0;
    for (i = 0; i < treasure_map; i++) {
        state->supplyCount[i] = 1;
    }
    state->supplyCount[province] = 0;

    fails += -1 + shouldEqual(1, isGameOver(state), "should game over, province count is 0");

    free(state);
    return -1 * fails;
}

int testIsGameOverSupply() {
    int fails = 0;
    struct gameState *state = newGame();

    int i = 0;
    for (i = 0; i < treasure_map; i++) {
        state->supplyCount[i] = 1;
    }
    state->supplyCount[salvager] = 0;
    state->supplyCount[sea_hag] = 0;
    state->supplyCount[treasure_map] = 0;

    fails += -1 + shouldEqual(1, isGameOver(state), "should game over, three supplies are zero");

    free(state);
    return -1 * fails;
}
