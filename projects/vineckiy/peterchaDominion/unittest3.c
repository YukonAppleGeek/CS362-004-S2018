#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"

int testFullDeckCount();

int main() {
    printf("Testing fullDeckCount\n");
    int fails = 0;

    fails += testFullDeckCount();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testFullDeckCount() {
    int fails = 0;
    struct gameState *state = newGame();
    state->hand[0][0] = council_room;
    state->handCount[0] = 1;

    state->hand[1][0] = adventurer;
    state->hand[1][1] = smithy;
    state->handCount[1] = 2;

    state->deck[0][0] = smithy;
    state->deck[0][1] = ambassador;
    state->deck[0][2] = cutpurse;
    state->deckCount[0] = 3;

    state->deck[1][0] = feast;
    state->deck[1][1] = ambassador;
    state->deck[1][2] = smithy;
    state->deckCount[1] = 3;

    state->discard[0][0] = tribute;
    state->discard[0][1] = council_room;
    state->discardCount[0] = 2;

    state->discardCount[1] = 0;

    fails += -1 + shouldEqual(2, fullDeckCount(1, smithy, state), "smithy count for player 1");
    fails += -1 + shouldEqual(2, fullDeckCount(0, council_room, state), "council room for player 0 ");
    fails += -1 + shouldEqual(1, fullDeckCount(0, tribute, state), "tribute for player 0 ");
    fails += -1 + shouldEqual(0, fullDeckCount(0, feast, state), "feast for player 0 ");
    fails += -1 + shouldEqual(1, fullDeckCount(0, cutpurse, state), "custpurse for player 0 ");

    free(state);
    return -1 * fails;
}
