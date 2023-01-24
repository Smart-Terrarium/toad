option(ENABLE_TESTS "Enable tests" ON)
if(${ENABLE_TESTS})
  include(CTest)
  enable_testing()

  find_package(GTest 1.11 REQUIRED)
  include(GoogleTest)
endif()
