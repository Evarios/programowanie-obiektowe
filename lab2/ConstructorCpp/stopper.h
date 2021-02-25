#ifndef STOPPER
#define STOPPER
#include <ctime>

class Stopper{
    private:
        time_t start_t, stop_t;
        int sumTime=0;
    public:
        void start();
        void stop();
        void currTime();
        void reset();
};
#endif