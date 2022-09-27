#include <iostream>
#include <string.h> // strcpy
#include "worker.h"

int main() {
    Worker worker;
    worker.setID(1000);
    std::cout << worker.getID() << std::endl;

    strcpy(worker.name, "John");
    std::cout << worker.name << std::endl;
    return 0;
}