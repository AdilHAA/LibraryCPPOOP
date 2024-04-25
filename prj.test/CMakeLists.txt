set(CMAKE_CXX_STANDARD 20)
add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)

target_link_libraries(test_rational rational)

add_executable(test_dynarr test_dynarr.cpp)

target_link_libraries(test_dynarr dynarr)

add_executable(test_stackarr test_stackarr.cpp)

target_link_libraries(test_stackarr stackarr)

target_link_libraries(test_stackarr complex)

add_executable(test_stacklst test_stacklst.cpp)

target_link_libraries(test_stacklst stacklst)

add_executable(test_queuelstpr test_queuelstpr.cpp)

target_link_libraries(test_queuelstpr queuelstpr)

add_executable(test_bitset test_bitset.cpp)

target_link_libraries(test_bitset bitset)

add_executable(test_stacklstt test_stacklstt.cpp)

target_link_libraries(test_stacklstt stacklstt)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_dynarr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stackarr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklst)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelstpr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_bitset)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklstt)

