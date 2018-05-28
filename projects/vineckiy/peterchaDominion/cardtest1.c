#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testSmithyEffectGainCards();
int testSmithyEffectDiscard();

int main() {
    printf("Testing smithy card effect\n");
    int fails = 0;

    fails += testSmithyEffectGainCards();
    fails += testSmithyEffectDiscard();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}


int testSmithyEffectGainCards() {
    int fails = 0;
    struct gameState *state = newGame();
    state->whoseTurn = 0;
    state->deck[0][0] = treasure_map;
    state->deck[0][1] = ambassador;
    state->deck[0][2] = tribute;
    state->deckCount[0] = 3;

    state->hand[0][0] = village;
    state->hand[0][1] = smithy;
    state->handCount[0] = 2;

    state->discardCount[0] = 0;

    int result = cardEffect(smithy, 0, 0, 0, state, 0, (int*)NULL);
    fails += -1 * shouldEqual(0, result, "effect should succeeded");
    fails += -1 * shouldEqual(4, state->handCount[0], "should have gained 3 cards");

    free(state);
    return -1 * fails;
}

int testSmithyEffectDiscard() {
    int fails = 0;
    struct gameState *state = newGame();
    state->whoseTurn = 0;
    state->deck[0][0] = treasure_map;
    state->deck[0][1] = ambassador;
    state->deck[0][2] = tribute;
    state->deckCount[0] = 3;

    state->hand[0][0] = village;
    state->hand[0][1] = smithy;
    state->handCount[0] = 2;

    state->playedCards[0] = 0;
    state->playedCardCount = 0;

    int result = cardEffect(smithy, 0, 0, 0, state, 1, (int*)NULL);
    fails += -1 * shouldEqual(0, result, "effect should succeeded");
    fails += -1 * shouldEqual(1, state->playedCardCount, "should have played card");
    fails += -1 * shouldEqual(smithy, state->playedCards[0], "discarded is not smithy");

    free(state);
    return -1 * fails;
}