#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testVillageEffect();

int main() {
    printf("Testing village card effect\n");
    int fails = 0;

    fails += testVillageEffect();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testVillageEffect() {
    int fails = 0;
    struct gameState *state = newGame();
    state->deck[0][0] = treasure_map;
    state->deck[0][1] = ambassador;
    state->deck[0][2] = tribute;
    state->deckCount[0] = 3;

    state->hand[0][0] = village;
    state->hand[0][1] = ambassador;
    state->handCount[0] = 2;

    state->playedCardCount = 0;

    state->numActions = 1;

    int result = cardEffect(village, 0, 0, 0, state, 0, (int*)NULL);
    fails += -1 + shouldEqual(0, result, "effect should succeed");
    fails += -1 + shouldEqual(2, state->handCount[0], "should have gained a card");
    fails += -1 + shouldEqual(3, state->numActions, "should have gained two actions");
    fails += -1 + shouldEqual(1, state->playedCardCount, "should have discarded");

    free(state);
    return -1 * fails;
}