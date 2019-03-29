#include "idgenerator.h"
std::unique_ptr<IDGenerator> IDGenerator::only_copy(nullptr);

IDGenerator::IDGenerator() : id(0) {

}

unsigned IDGenerator::next() {
    return ++id;
}

IDGenerator* IDGenerator::instance() {
   if (!only_copy) {
      only_copy.reset(new IDGenerator());
   }
   return only_copy.get();
}
