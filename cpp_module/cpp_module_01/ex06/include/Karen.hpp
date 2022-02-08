#ifndef KAREN_HPP
#define KAREN_HPP

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

#include <string>

class Karen {
   private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

   public:
    Karen();
    ~Karen();

    void complain(std::string level);
};

#endif