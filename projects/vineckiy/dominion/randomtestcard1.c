#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testRandomSmithyCard();

int main() {
    printf("Testing random smithy card effect\n");
    srand(time(NULL));
    int i;
    int fails = 0;

    for (i = 0; i < 20; i++) {
        fails += testRandomSmithyCard();
    }

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}


int testRandomSmithyCard() {
    int i;
    int fails = 0;
    struct gameState *state = newGame();
    state->whoseTurn = 0;

    // Leave room for played card
    int playedCardCount = rand() % (MAX_DECK - 2);
    state->playedCardCount = playedCardCount;

    state->deckCount[0] = rand() % MAX_DECK;
    for (i = 0; i < state->deckCount[0]; i++) {
        state->deck[0][i] = rand() % treasure_map; /* Last Card */
    }

    // Do not need a large range to test player hand
    int handCount = rand() % 20 + 1;
    state->handCount[0] = handCount;

    int handPos = rand() % handCount;
    state->hand[0][handPos] = smithy;

    for (i = 0; i < handCount; i++) {
        if (i == handPos) continue;
        state->hand[0][i] = rand() % treasure_map; /* Last Card */
    }

    int result = cardEffect(smithy, 0, 0, 0, state, handPos, (int*)NULL);
    fails += -1 * shouldEqual(0, result, "effect should succeeded");
    fails += -1 * shouldEqual(handCount + 3, state->handCount[0], "should have gained 3 cards");
    fails += -1 * shouldEqual(playedCardCount + 1, state->playedCardCount, "should have played card");
    fails += -1 * shouldEqual(smithy, state->playedCards[playedCardCount], "discarded is not smithy");

    free(state);
    return -1 * fails;
}