#include "MPC.h"

int main() {
    MPC* mpc = MPC::Instance();
    mpc->Boot();
}