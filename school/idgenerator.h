#ifndef IDGENERATOR_H
#define IDGENERATOR_H
#include <memory>

class IDGenerator
{    
public:
      static IDGenerator* instance();
      unsigned next();
   private:
      IDGenerator();
      static std::unique_ptr<IDGenerator> only_copy;
      unsigned id;
};
#endif // IDGENERATOR_H
