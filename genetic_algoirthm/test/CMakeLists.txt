find_package(GTest REQUIRED)
find_package(Boost 1.72.0 COMPONENTS ALL)

include_directories(testa ${Boost_INCLUDE_DIR})
include_directories(testa ${GTEST_INCLUDE_DIRS})

add_executable(testa test_nsga.cpp test_ga_tool.cpp test_selection_method.cpp
	../src/nsga.cpp ../src/nsga_chromosome.cpp
	../src/ga_problem.cpp ../src/ga_tool.cpp
	../src/selection_method.cpp
	)
target_link_libraries(testa ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(testa ${Boost_LIBRARIES})

##gtest_discover_tests(testa)
enable_testing()
add_test(me testa)
#add_test(m2 testb)


	
