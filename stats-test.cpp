#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <stdlib.h>
#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    computedStats lcomputedStats;
    lcomputedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    REQUIRE(abs(lcomputedStats.average - 4.525) < epsilon);
    REQUIRE(abs(lcomputedStats.max - 8.9) < epsilon);
    REQUIRE(abs(lcomputedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    
    computedStats lcomputedStats;
    lcomputedStats = compute_statistics(0, 0);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    REQUIRE(lcomputedStats.average == 1);
    REQUIRE(lcomputedStats.max == 1);
    REQUIRE(lcomputedStats.min == 1);
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
}

TEST_CASE("raises alerts when max is greater than threshold") {
    // create additional .c and .h files
    // containing the emailAlerter, ledAlerter functions
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    computedStats lcomputedStats;
    lcomputedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, lcomputedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}

