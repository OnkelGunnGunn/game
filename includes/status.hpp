#ifndef STATUS_HPP
#define STATUS_HPP

#include <string>

class Monster; 

enum class StatusType {
    NONE,
    POISON,
    STRENGTH_SAP,
};

class Status {
private:
    StatusType type;
    int duration;

public:
    Status(StatusType type, int duration);

    void apply(Monster& target);

    bool is_expired() const;
    void decrease_duration();
};

#endif
