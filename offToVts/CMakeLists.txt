set(SOURCE_FILES "main.cpp")

add_executable(offToVTS
  main.cpp
  ${SOURCE_FILES}
  )
include_directories(${PROJECT_SOURCE_DIR}/inc)

