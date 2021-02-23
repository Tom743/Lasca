#include <string>
#include "App.h"
#include "Codes.h"

std::string argc = ""; // TODO command line args

int main()
{
    // ExitCode of our program
    int exitCode = Codes::StatusNoError;

    // Initialize the outer layer of the engine
    App* app = new App();

    // Process command line arguments
    app->ProcessArguments(argc);

    // Run the game loop
    exitCode = app->Run();

    // Cleanup
    delete app;
    app=NULL;

    // Return with our exit code
    return exitCode;    
}
