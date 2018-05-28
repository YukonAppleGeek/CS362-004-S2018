#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testRandomStewardCard();

int main() {
    printf("Testing random steward card effect\n");
    srand(time(NULL));
    int i;
    int fails = 0;

    for (i = 0; i < 20; i++) {
        fails += testRandomStewardCard();
    }

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}


int testRandomStewardCard() {
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

    // Use sensible starting amount
    int startingCoins = rand() % 1000;
    state->coins = startingCoins;

    // Do not need a large range to test player hand
    int handCount = rand() % 20 + 1;
    state->handCount[0] = handCount;

    int handPos = rand() % handCount;
    state->hand[0][handPos] = steward;

    for (i = 0; i < state->handCount[0]; i++) {
        if (i == handPos) continue;
        state->hand[0][i] = rand() % treasure_map; /* Last Card */
    }

    // Only 3 options for card
    int choice = rand() % 3;

    int discard1 = rand() % handCount;
    int discard2 = rand() % handCount;

    int result = cardEffect(steward, choice, discard1, discard2, state, handPos, (int*)NULL);
    fails += -1 * shouldEqual(0, result, "effect should succeeded");
    if (choice == 1) {
        fails += -1 * shouldEqual(handCount + 2, state->handCount[0], "should have gained 2 cards");
    } else if (choice == 2) {
        fails += -1 * shouldEqual(startingCoins + 2, state->coins, "should have gained two coins");
    }

    fails += -1 * shouldEqual(playedCardCount + 1, state->playedCardCount, "should have one played card");
    fails += -1 * shouldEqual(steward, state->playedCards[playedCardCount], "discarded is not steward");

    free(state);
    return -1 * fails;
}