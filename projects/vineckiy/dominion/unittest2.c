#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"

int testHandCard();

int main() {
    printf("Testing handCard\n");
    int fails = 0;

    fails += testHandCard();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testHandCard() {
    int fails = 0;
    struct gameState *state = newGame();
    state->whoseTurn = 1;
    state->hand[0][0] = council_room;
    state->hand[1][0] = adventurer;
    state->hand[1][1] = smithy;

    fails += -1 + shouldEqual(adventurer, handCard(0, state), "expected adventurer");
    fails += -1 + shouldEqual(smithy, handCard(1, state), "expected smithy");

    free(state);
    return -1 * fails;
}
