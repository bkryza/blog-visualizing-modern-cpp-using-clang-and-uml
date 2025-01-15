
add_library(simple_app)
set_target_properties(simple_app PROPERTIES CXX_SCAN_FOR_MODULES
        ON)

target_sources(simple_app
        PUBLIC
        simple_app.cpp
        PUBLIC FILE_SET CXX_MODULES FILES
        src/simple_app_mod.cppm
        src/frontend_lib.cppm
        src/webview.cppm
        src/desktop.cppm
        src/backend_lib.cppm)
