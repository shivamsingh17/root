############################################################################
# CMakeLists.txt file for building ROOT misc/minicern package
############################################################################

ROOT_LINKER_LIBRARY(minicern *.c *.f TYPE STATIC NOINSTALL)
set_property(TARGET minicern PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(minicern ${CMAKE_Fortran_IMPLICIT_LINK_LIBRARIES})

# Disable optimization since it some cases was causing crashes.
# Disable warnings, since what has worked for 40 years...
# (see https://sft.its.cern.ch/jira/browse/ROOT-9179 for the warnings)
set_target_properties(minicern PROPERTIES COMPILE_FLAGS "-O0 -w")



