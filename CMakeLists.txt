cmake_minimum_required(VERSION 3.2)
project( nerpp )
aux_source_directory( src/. src_list )
add_executable( nerpp ${src_list} )