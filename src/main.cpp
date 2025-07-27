#include "MPC.h"

int main() {
    try {
        MPC* mpc = MPC::Instance();
        mpc->Boot();
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}