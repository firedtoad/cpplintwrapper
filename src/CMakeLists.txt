file(GLOB_RECURSE CPPLINT src *.cpp *.h *.hpp *.cc )
add_executable(cpplint ${CPPLINT})