#include <iostream>
#include <iomanip>
#include <cstdint>

int main(){
    std::cout << std::left;

    // fixed size which would be platform independent 
    std::cout << std::setw(16) << "signed int8_t:" << sizeof(std::int8_t) << " bytes\n";                    // behaviour expected to similar of char
    std::cout << std::setw(16) << "signed int16_t:" << sizeof(std::int16_t) << " bytes\n";
    std::cout << std::setw(16) << "signed int32_t:" << sizeof(std::int32_t) << " bytes\n";
    std::cout << std::setw(16) << "signed int64_t:" << sizeof(std::int64_t) << " bytes\n";

    std::cout << std::setw(16) << "unsigned int8_t:" << sizeof(std::uint8_t) << " bytes\n";                 // behaviour expected to similar of char
    std::cout << std::setw(16) << "unsigned int16_t:" << sizeof(std::uint16_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned int32_t:" << sizeof(std::uint32_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned int64_t:" << sizeof(std::uint64_t) << " bytes\n";

    // least size which can be processed for the given type by the CPU
    std::cout << std::setw(16) << "signed least int8_t:" << sizeof(std::int_least8_t) << " bytes\n";
    std::cout << std::setw(16) << "signed least int16_t:" << sizeof(std::int_least16_t) << " bytes\n";
    std::cout << std::setw(16) << "signed least int32_t:" << sizeof(std::int_least32_t) << " bytes\n";
    std::cout << std::setw(16) << "signed least int64_t:" << sizeof(std::int_least64_t) << " bytes\n";

    std::cout << std::setw(16) << "unsigned least int8_t:" << sizeof(std::uint_least8_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned least int16_t:" << sizeof(std::uint_least16_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned least int32_t:" << sizeof(std::uint_least32_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned least int64_t:" << sizeof(std::uint_least64_t) << " bytes\n";

    // fastest size which can be processed by the CPU
    // In my system processing 64 bits are faster thats why the size of fast 16, 32 and 64 are 8 bytes or 64 bits
    // But this might have lots of unused memory and not recommended for memory critical application
    std::cout << std::setw(16) << "signed fast int8_t:" << sizeof(std::int_fast8_t) << " bytes\n";
    std::cout << std::setw(16) << "signed fast int16_t:" << sizeof(std::int_fast16_t) << " bytes\n";
    std::cout << std::setw(16) << "signed fast int32_t:" << sizeof(std::int_fast32_t) << " bytes\n";
    std::cout << std::setw(16) << "signed fast int64_t:" << sizeof(std::int_fast64_t) << " bytes\n";

    std::cout << std::setw(16) << "unsigned fast int8_t:" << sizeof(std::uint_fast8_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned fast int16_t:" << sizeof(std::uint_fast16_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned fast int32_t:" << sizeof(std::uint_fast32_t) << " bytes\n";
    std::cout << std::setw(16) << "unsigned fast int64_t:" << sizeof(std::uint_fast64_t) << " bytes\n";

    std::int8_t a{65};
    std::cout<<"value of int8_t: "<<a<<"\n";                                                                // the value is intepreted as char

    return 0;
}