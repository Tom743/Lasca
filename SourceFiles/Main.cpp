#include <string>
#include "App.h"

int main(int argc, char* argv[])
{
    // ExitCode of our program
    int exitCode;

    // Initialize the outer layer of the engine
    App* app = new App();

    // Process command line arguments
    app->ProcessArguments(argc, argv);

    // Start UI and run main loop
    exitCode = app->Run();

    // Cleanup
    delete app;
    app=NULL;

    // Return with our exit code
    return exitCode;    
}
