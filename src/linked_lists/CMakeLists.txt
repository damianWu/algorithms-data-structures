add_library(linked_lists_lib ./linked_lists.cpp)                # .cpp file path

target_include_directories(linked_lists_lib PUBLIC .)       # path to catalog that contain
                                                        # .hpp file
                                                        # (not directly to .hpp file!)

# target_link_libraries(linked_list_lib)
