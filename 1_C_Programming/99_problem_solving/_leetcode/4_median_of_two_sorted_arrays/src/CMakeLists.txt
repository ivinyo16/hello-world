add_executable(double_pointers_method 
    main.c
    utils_array.c
    double_pointers_method.c
)
target_link_libraries(double_pointers_method PRIVATE common_includes)

add_executable(bst_method 
    main.c
    utils_array.c
    double_pointers_method.c
)
target_link_libraries(bst_method PRIVATE common_includes)
