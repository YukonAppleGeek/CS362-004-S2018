#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testAdventureCardDrawTreasure();

int main() {
    printf("Testing adventure card effect\n");
    int fails = 0;

    fails += testAdventureCardDrawTreasure();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testAdventureCardDrawTreasure() {
    int fails = 0;
    struct gameState *state = newGame();
    state->hand[0][0] = cutpurse;
    state->handCount[0] = 1;

    state->deck[0][0] = copper;
    state->deck[0][1] = council_room;
    state->deck[0][2] = silver;
    state->deckCount[0] = 3;

    int result = cardEffect(adventurer, 0, 0, 0, state, 0, (int*)NULL);
    fails += -1 + shouldEqual(0, result, "effect should succeed");
    fails += -1 + shouldEqual(3, state->handCount[0], "should have gained two cards");
    fails += -1 + shouldEqual(silver, state->hand[0][1], "should have silver");
    fails += -1 + shouldEqual(copper, state->hand[0][2], "should have copper");

    free(state);
    return -1 * fails;
}