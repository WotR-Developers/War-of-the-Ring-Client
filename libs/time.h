#ifndef FOURTH_AGE_CLIENT_TIME
#define FOURTH_AGE_CLIENT_TIME

/* To get access to the GLFW high-precision timer */
#include <SDL2/SDL.h>

/* To get access to memory management functions */
#include <stdlib.h>

/* A structure containing the necessary information for a new Timer */
struct Timer {
    double  startTime;      // The starting time of the timer which is the application time at creating the timer
    int     isSleeping;     // 0 = is not sleeping 1 = is sleeping
};

/* A variable containing the amount of timers */
int     timerCount;

/* Contains a list of timers. */
struct  Timer*  timers;

/* Contains the deltaTime variable to be worked with. */
double  deltaTime;

/* The time since the application has been started. */
double  applicationTime;

/* The oldTime, only used to calculate the deltaTime. */
double  oldTime;

/* Returns the current delta time. */
double  TIM_getDeltaTime        ();

/* Updates the deltaTime. */
void    TIM_updateDeltaTime     ();

/* Returns the time since the application has been started. */
double  TIM_getApplicationTime  ();

/* Adds a new timer to the timers list and sets it to the current application time
 * and returns the ID of the timer.*/
int     TIM_addTimer            ();

/* Returns the time for a timer which is application time - timer start time. */
double  TIM_getTimer            (int    id);

/* Resets the timer with the given ID to the new application time. */
void    TIM_resetTimer          (int    id);

/* Lets the timer with the given ID sleep. */
void    TIM_sleepTimer          (int    id);

/* Lets the timer with the given ID awake */
void    TIM_awakeTimer          (int    id);

/* Updates application time and old time.
 * Adds the passed time to the sleeping timers. */
void    TIM_updateTimers        ();

/* Frees dynamic memory. */
void    TIM_free                ();

#endif
