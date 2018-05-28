#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"

int testPhaseRequirement();
int testNumActionRequirement();
int testActionCardRequirement();

int main() {
    printf("Testing playCard\n");
    int fails = 0;

    fails += testPhaseRequirement();
    fails += testNumActionRequirement();
    fails += testActionCardRequirement();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testPhaseRequirement() {
    int fails = 0;
    struct gameState *state = newGame();
    state->numActions = 2;
    // Incorrect phase
    state->phase = 1;
    int resp = playCard(0, 0, 0, 0, state);
    fails += -1 + shouldEqual(-1, resp, "phase must be 0 to play card");
    fails += -1 + shouldEqual(2, state->numActions, "action preformed with incorrect state");

    free(state);
    return (-1) * fails;
}

int testNumActionRequirement() {
    int fails = 0;
    struct gameState *state = newGame();
    state->phase = 0;
    // No actions left
    state->numActions = 0;
    int resp = playCard(0, 0, 0, 0, state);
    fails += -1 + shouldEqual(-1, resp, "can not play card with no actions");
    fails += -1 + shouldEqual(0, state->numActions, "action preformed with no actions");

    free(state);
    return (-1) * fails;
}

int testActionCardRequirement() {
    int fails = 0;
    struct gameState *state = newGame();
    state->phase = 0;
    state->whoseTurn = 0;
    state->numActions = 1;
    // Action card
    state->hand[0][0] = estate;
    int resp = playCard(0, 0, 0, 0, state);
    fails += -1 + shouldEqual(-1, resp, "can not play action card");
    fails += -1 + shouldEqual(1, state->numActions, "action preformed with action card");

    free(state);
    return (-1) * fails;
}