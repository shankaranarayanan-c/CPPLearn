#include <iostream>

int main(){

    std::cout<<"Generate Core dump [pass kill signal] / use if the file is automatically generated out of segfault \n";
    std::cout<<"check the limit of size set for the core dump generation \n";
    std::cout<<"$ulimit -c displayes the current size \n";
    std::cout<<"$ulimit -c unlimited to set the size unlimited\n";
    std::cout<<"$sysctl kernel.core_pattern displays the location where the dump are created \n";
    std::cout<<"$sudo sysctl -w kernel.core_pattern=\"/tmp/%e_core_dump.%p\" redirect the dump to temp directory which creates with binaryname_core_dump.pid \n";
    std::cout<<"Use GDB debugger to analyze the core dump file \n";
    std::cout<<"gdb binary -c core dumpfile \n";
    std::cout<<"gdb ~/workspace/learnCPP/02_basics/main -c mainexe_core_dump.51033 \n";
    std::cout<<"bt - back trace up / down - navigate call stack info local - variables info registers - value of cpu registers \n";
    return 0;
}