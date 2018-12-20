cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(alpha_hello VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(alpha_hello VERSION 0.0.777)
endif ()

if(UNIX AND NOT APPLE)
    find_package(Doxygen)

    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/doc")
    set(DOXYGEN_PROJECT_LOGO "${CMAKE_SOURCE_DIR}/logo-alpha.png")

    doxygen_add_docs(doc "${PROJECT_SOURCE_DIR}")
endif()

configure_file(version.h.in "${PROJECT_SOURCE_DIR}/version.h")

add_executable(${PROJECT_NAME} "main.cpp")

set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(sayhello SHARED "sayhello.cpp" "sayhello.h")

set_target_properties(${PROJECT_NAME} "sayhello" PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

if(UNIX)
  set_target_properties(${PROJECT_NAME} "sayhello" PROPERTIES
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
  )
endif()

target_link_libraries(${PROJECT_NAME} sayhello)

if(WIN32)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
	install(TARGETS "sayhello" RUNTIME DESTINATION .)
else()
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
	install(TARGETS "sayhello" LIBRARY DESTINATION lib)
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR DEB)
    message("Package for linux generated as DEB")
else()
    set(CPACK_GENERATOR ZIP)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dinsul2.0@gmail.com)

include (CPack)
