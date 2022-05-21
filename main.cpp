#include <SDL.h>
#include <iostream>

#include <theeyeConfig.h>

#ifdef USE_Application
    #include <Application.h>
#endif

#ifdef USE_TesterModule
    #include <TesterModule.h>
#endif

int main(int arc, char ** argv) {
    Application* app  = new Application();
    SetState<TestState>(app);
    while(app -> Run());
    delete app;
    return 0;
}
