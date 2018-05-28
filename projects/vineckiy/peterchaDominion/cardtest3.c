#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "testAssert.h"
#include "dominion_helpers.h"

int testCouncilRoomDraw();

int main() {
    printf("Testing council room card effect\n");
    int fails = 0;

    fails += testCouncilRoomDraw();

    printf("Total fails: %d\n", fails);
    if (fails == 0) printf("All tests passed!\n");
    return 0;
}

int testCouncilRoomDraw() {
    int fails = 0;
    struct gameState *state = newGame();
    state->deck[0][0] = treasure_map;
    state->deck[0][1] = ambassador;
    state->deck[0][2] = tribute;
    state->deck[0][3] = silver;
    state->deck[0][4] = feast;
    state->deck[0][4] = gold;
    state->deckCount[0] = 5;

    state->deck[1][0] = silver;
    state->deck[1][1] = smithy;
    state->deckCount[1] = 2;

    state->deck[2][0] = tribute;
    state->deck[2][1] = cutpurse;
    state->deckCount[2] = 2;

    state->hand[0][0] = council_room;
    state->hand[0][1] = smithy;
    state->handCount[0] = 2;

    state->hand[1][0] = curse;
    state->handCount[1] = 1;

    state->hand[2][0] = ambassador;
    state->handCount[2] = 1;

    state->playedCards[0] = 0;
    state->playedCardCount = 0;

    state->numPlayers = 3;

    int result = cardEffect(council_room, 0, 0, 0, state, 0, (int*)NULL);
    fails += -1 + shouldEqual(0, result, "effect should succeed");
    fails += -1 + shouldEqual(5, state->handCount[0], "should have gained four cards");
    fails += -1 + shouldEqual(2, state->handCount[1], "player 2 should have gained a card");
    fails += -1 + shouldEqual(2, state->handCount[2], "player 3 should have gained a card");
    fails += -1 + shouldEqual(1, state->playedCardCount, "should have a played card");

    free(state);
    return -1 * fails;
}