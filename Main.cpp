#include <any>
#include "Printer.h"
#include "Reader.h"
#include "PrinterConfig.h"

#ifdef USE_LIB
#include "addition.h"
#endif

int main() {
    int first = 12;
    int second = 13;
    
    int result;
    
#ifdef USE_LIB
    result = add(first, second); // 25
#else
    result = first + second + 1; // 26
#endif
    
    Printer::println("The result is " + std::to_string(result));
    //    std::any value = 13;
    //    std::string name = Reader::read();
    //
    //
    //
    //    Printer::print("Hello ");
    //    Printer::println(name);
}
