#include <iostream>
#include "set.h"

int main() 
{
    Set<int> s1;
    Set<std::string> s2;
    int* intArray = nullptr;
    std::string* stringArray = nullptr;

    // Add some sample integers to the set
    s1.add(10);
    s1.add(20);
    s1.add(15);
    s1.add(20);
    intArray = s1.getArray();
    std::cout << "Set one has " << s1.getSize() << " items. Here they are:" << std::endl;
    for (int i = 0; i < s1.getSize(); i++) {
        std::cout << intArray[i] << std::endl;
    }
    if (intArray != nullptr) {
        delete[] intArray;
    }

    // Add some sample strings to the set
    s2.add("butter");
    s2.add("hamburgers");
    s2.add("pizza");
    s2.add("hotdogs");
    s2.add("pizza");
    stringArray = s2.getArray();
    std::cout << "Set two has " << s2.getSize() << " items. Here they are:" << std::endl;
    for (int i = 0; i < s2.getSize(); i++) {
        std::cout << stringArray[i] << std::endl;
    }
    if (stringArray != nullptr) {
        delete[] stringArray;
    }

    return 0;
}
