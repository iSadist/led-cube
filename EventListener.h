#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

class EventListener {
private:
    int previousChoice;
    int previousChoiceTime;
    bool readButton(int value);
public:
    EventListener(/* args */);
    ~EventListener();

    /**
     * Listens for events from the user.
     * 
     * @param None
     * @return The event that was triggered.
     */
    int listen();
};

#endif