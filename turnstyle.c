/*
This application represents a state machine that models a user going through a turnstyle
*/

// include the library for i/o and assertions.
#include <stdio.h>
#include <assert.h>

// Define a 'turnstyle' structure with a state field that can be either 'LOCKED' or 'UNLOCKED'.

typedef struct {
    enum {LOCKED, UNLOCKED} state;
} State;

/*
Define an 'Event' enum with the following events: 'COIN' and 'PUSH'
*/

typedef enum {
    COIN,
    PUSH
} Event;

/*
Create a 'handle_event' function that takes a 'turnstyle' and an 'Event' and updates the state of the turnstyle based on the current state of the event.
Details:
- If the turnstyle is in the 'LOCKED' state and the event is 'COIN', the turnstyle should transition to the 'UNLOCKED' state.
- If the turnstyle is in the 'UNLOCKED' state and the event is 'PUSH', the turnstyle should transition to the 'LOCKED' state.
- If the turnstyle is in the 'LOCKED' state and the event is 'PUSH', the turnstyle should remain in the 'LOCKED' state.
- If the turnstyle is in the 'UNLOCKED' state and the event is 'COIN', the turnstyle should remain in the 'UNLOCKED' state.
-Print a message to the condole to indicate the action taken
*/

void handle_event(State *state, Event event) {
    if (state->state == LOCKED && event == COIN) {
        state->state = UNLOCKED;
        printf("Turnstyle is now UNLOCKED\n");
    } else if (state->state == UNLOCKED && event == PUSH) {
        state->state = LOCKED;
        printf("Turnstyle is now LOCKED\n");
    } else if (state->state == LOCKED && event == PUSH) {
        printf("Turnstyle remains LOCKED\n");
    } else if (state->state == UNLOCKED && event == COIN) {
        printf("Turnstyle remains UNLOCKED\n");
    }
}

/*
Create a function 'turnstyle_test' that tests the 'handle_event function'
Details:
- Create a 'Turnstyle' and call 'handle_event' with a sequence of events.
- Assert that the state of the turnstyle is as expected after each event.
- if all assertions pass, print "all tests pass"
*/

void turnstyle_test() {
    State turnstyle = {LOCKED};
    handle_event(&turnstyle, COIN);
    assert(turnstyle.state == UNLOCKED);
    handle_event(&turnstyle, PUSH);
    assert(turnstyle.state == LOCKED);
    handle_event(&turnstyle, PUSH);
    assert(turnstyle.state == LOCKED);
    handle_event(&turnstyle, COIN);
    assert(turnstyle.state == LOCKED);
    printf("All tests pass\n");
}

int main() {
    turnstyle_test();
    return 0;
}