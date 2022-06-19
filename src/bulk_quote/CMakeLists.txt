add_library(bulk_quote_lib ./bulk_quote.cpp)                # .cpp file path

target_include_directories(bulk_quote_lib PUBLIC .)       # path to catalog that contain
                                                        # .hpp file
                                                        # (not directly to .hpp file!)

target_link_libraries(bulk_quote_lib quote_lib)
