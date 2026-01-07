#ifndef USER_H
#define USER_H

#include <Arduino.h>

struct UserPreferences {
    int preferredLightLevel;
    bool prefersSilence;

    UserPreferences()
        : preferredLightLevel(40),
          prefersSilence(false) {}
};

class User {
public:
    String id;
    String name;
    bool present;
    String locationZone;
    UserPreferences preferences;

    User();
};

#endif