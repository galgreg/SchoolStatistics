#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IDGenerator
{    
public:
      static IDGenerator* instance();
      unsigned next();
      ~IDGenerator();
   private:
      IDGenerator();
      static IDGenerator *only_copy;
      unsigned id;
};
#endif // IDGENERATOR_H
