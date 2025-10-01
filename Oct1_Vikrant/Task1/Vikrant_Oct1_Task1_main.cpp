#include "Vikrant_Oct1_Task1_HybridVehicle.h"
#include <iostream>

int main() {
    // 1. Create vehicles
    HybridVehicle v1("Prius", 120.5F, 80.0F, 4.5F);
    HybridVehicle v2("Volt", 100.0F, 90.0F, 5.0F);

    // Assign some trips
    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    // 2. Display vehicles
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    // 3. Combine with +
    HybridVehicle v3 = v1 + v2;
    std::cout << "Combined: " << v3 << std::endl;

    // 4. Compare efficiency ==
    if (v1 == v2) {
        std::cout << "Vehicles have same efficiency.\n";
    } else {
        std::cout << "Vehicles differ in efficiency.\n";
    }

    // 5. ++ operator
    ++v1;
    std::cout << "After ++: " << v1 << std::endl;

    // 6. Access trip []
    std::cout << "v1[0] trip distance: " << v1[0] << std::endl;

    // 7. () operator
    std::cout << "Total distance v1: " << v1() << " km" << std::endl;

    // 8. float() conversion
    float efficiency = static_cast<float>(v1);
    std::cout << "Efficiency of v1: " << efficiency << " km/L" << std::endl;

    // 9. = operator (deep copy)
    HybridVehicle v4;
    v4 = v1;
    std::cout << "Copied v4: " << v4 << std::endl;

    return 0;
}
