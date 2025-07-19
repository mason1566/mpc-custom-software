#include "MPCController.h"

int main() {
    MPCController* mpc = MPCController::Instance();
    mpc->Boot();
}