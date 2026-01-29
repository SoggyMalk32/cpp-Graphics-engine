add_library(Engine STATIC
    Engine.cpp
)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(Engine PUBLIC cxx_std_20)

add_executable(proto_app main.cpp)
target_link_libraries(proto_app PRIVATE Engine)
