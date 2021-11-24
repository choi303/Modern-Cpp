# CMakeList.txt : CMake project for ModernCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (ModernCpp "ModernCpp.cpp"   "OOP/Car.hpp" "OOP/Car.cpp" "OOP/Integer.hpp" "OOP/Integer.cpp" "OOP/Account.hpp" "OOP/Account.cpp" "OOP/Savings.hpp" "OOP/Savings.cpp" "OOP/Checking.hpp" "OOP/Checking.cpp" "OOP/Transaction.hpp" "OOP/Transaction.cpp")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# TODO: Add tests and install targets if needed.
