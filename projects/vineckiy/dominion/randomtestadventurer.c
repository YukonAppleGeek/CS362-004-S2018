#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testRandomAdventureCard();

int main() {
    printf("Testing random adventure card effect\n");
    srand(time(NULL));
    int i;
    int fails = 0;

    for (i = 0; i < 20; i++) {
        fails += testRandomAdventureCard();
    }

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testRandomAdventureCard() {
    int i;
    int fails = 0;
    struct gameState *state = newGame();
    /* Current card irrelevant, just initialize */
    state->hand[0][0] = cutpurse;
    state->handCount[0] = 1;

    // Leave room for two cards
    state->discardCount[0] = rand() % (MAX_DECK - 2);
    for (i = 0; i < state->discardCount[0]; i++) {
        state->discard[0][i] = rand() % treasure_map; /* Last Card */
    }

    state->deckCount[0] = rand() % MAX_DECK;
    for (i = 0; i < state->deckCount[0]; i++) {
        state->deck[0][i] = rand() % treasure_map; /* Last Card */
    }

    int result = cardEffect(adventurer, 0, 0, 0, state, 0, (int*)NULL);
    fails += -1 + shouldEqual(0, result, "effect should succeed");
    fails += -1 + shouldEqual(3, state->handCount[0], "should have gained two cards");
    if (!(state->hand[0][1] >= copper && state->hand[0][1] <= gold)) {
        fails += -1 + shouldEqual(1, 0, "should have first treasure in hand");
    }
    if (!(state->hand[0][1] >= copper && state->hand[0][1] <= gold)) {
        fails += -1 + shouldEqual(1, 0, "should have second treasure in hand");
    }

    free(state);
    return -1 * fails;
}