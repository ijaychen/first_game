#ifndef BASE_GLOBAL_H
#define BASE_GLOBAL_H

#ifndef __GNUC__
#error "only support gcc"
#endif


#ifdef HAS_CXX11
    #include <cstdint>
    #define DISABLE_COPY(Class) \
    Class(const Class&) = delete; \
    Class & operator=(const Class&) = delete;
#else
    #include <stdint.h>
    #define nullptr NULL
    #define DISABLE_COPY(Class) \
    Class(const Class&); \
    Class & operator=(const Class&);
#endif

#include <cstddef>
//#include <boost/concept_check.hpp>

#define SAFE_DELETE(ptr) do { if (ptr != nullptr) { delete ptr; ptr = nullptr; } } while(0)

#endif

