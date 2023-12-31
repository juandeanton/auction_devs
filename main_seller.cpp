#include <cadmium/core/logger/csv.hpp>
#include <cadmium/core/simulation/root_coordinator.hpp>
#include <iostream>
#include <limits>
#include "seller.hpp"

using namespace cadmium::example::auction;

int main() { //int argc, char *argv[]) {
    // model-related configuration parameters
    // double RPr = 100.0;
	//double PPrStep = 5.0;
	//double InitialPPr = 10.0;
    
    // We create the model and forward it to the root coordinator
    // NOTE THAT WE NEED A POINTER TO THE MODEL!
    auto model = std::make_shared<seller>("seller","1" , 10.0, 5.0, 25.0, "input.txt"); 

    // Next, we create the coordinator and the logger
    // We can add a logger to the root coordinator
    // In this example, we use a CSV logger that uses ; to separate columns.
    // Simulation results will be stored in the log_gpt.csv file.
    auto rootCoordinator = cadmium::RootCoordinator(model);
    auto logger = std::make_shared<cadmium::CSVLogger>("log_seller.csv", ";");
    rootCoordinator.setLogger(logger);

    // To start the simulation we 1) start, 2) simulate 3) stop.
    rootCoordinator.start();
    // in simulate method, we can select a maximum simulation time (in this case, infinity)
    rootCoordinator.simulate(std::numeric_limits<double>::infinity());
    rootCoordinator.stop();

    return 0;
}
