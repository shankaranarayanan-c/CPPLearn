#include <iostream>

int main(){
    std::cout<<"Set up Debugging in VS Code: \n";
    std::cout<<"1. Check if launch.json file exists within .vscode \n";
    std::cout<<"2. If not create one by selecting Add configuration within the Run Menu \n";
    std::cout<<"3. Now once again select Add configuration and it opens a menu within the lauch.json file \n";
    std::cout<<"4. Select the C/C++ gdb launch configuration from the menu \n";
    std::cout<<"5. add the executable along with the absolute path within the program \n";
    std::cout<<"6. you can also set the stop at entry to true if you want to break the executation at the beginning or toggle a breakpoint \n";
    std::cout<<"7. start debugging you should see the execution breaking in the starting or at the break point"
    return 0;
}