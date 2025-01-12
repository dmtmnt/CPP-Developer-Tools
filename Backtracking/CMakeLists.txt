# Add library for backtracking problems
add_library(BacktrackingLib STATIC 
    src/NQueenProblem.cpp
)

# Include directories for the library
target_include_directories(BacktrackingLib PUBLIC include)