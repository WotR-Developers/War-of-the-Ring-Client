#include "time.h"

double  TIM_getDeltaTime            () {
    return deltaTime;
}

void    TIM_updateDeltaTime         () {
    deltaTime = applicationTime - oldTime;
    oldTime = applicationTime;
}

double  TIM_getApplicationTime      () {
    return applicationTime;
}

double  TIM_getFPS                  () {
    return (1 / TIM_getDeltaTime() * 1000);
}

int     TIM_addTimer                () {
    // Add 1 to the timer count.
    timerCount += 1;
    // Change the size of the timers list and set the appropriate values-
    timers = realloc(timers, timerCount * sizeof(struct Timer));
    timers[timerCount - 1].startTime = applicationTime;
    timers[timerCount - 1].isSleeping = 0;
    // Return the correct index as the ID.
    return timerCount - 1;
}

double  TIM_getTimer                (int id) {
    // Subtract the start time of the requested timer from the current time
    return applicationTime - timers[id].startTime;
}

void    TIM_resetTimer              (int id) {
    // Resets the timer with the given ID by setting its value to the current application time
    timers[id].startTime = applicationTime;
}

void    TIM_sleepTimer              (int id) {
    timers[id].isSleeping = 1;
}

void    TIM_awakeTimer              (int id) {
    timers[id].isSleeping = 0;
}

void    TIM_updateTimers            () {
    // Update the application time.
    applicationTime = SDL_GetTicks();
    // If a timer is sleeping, add the passed time to its start time.
    for     (int i = 0; i < timerCount; ++i) {
        if      (timers[i].isSleeping == 1) {
            timers[i].startTime += applicationTime - oldTime;
        }
    }
}

void    TIM_free                    () {
    free(timers);
}
