#include "idgenerator.h"
IDGenerator* IDGenerator::only_copy;

IDGenerator::IDGenerator() : id(0) {

}
IDGenerator::~IDGenerator() {
    if(only_copy) {
        delete only_copy;
    }
    only_copy = nullptr;
}
unsigned IDGenerator::next() {
    return ++id;
}

IDGenerator* IDGenerator::instance() {
   if (!only_copy) {
      only_copy = new IDGenerator();
   }
   return only_copy;
}
