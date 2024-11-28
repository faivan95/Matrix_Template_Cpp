C++ project with templates and other newer functions

Visual studio standalone project without requiring external dependencies or plugins

**FOR CMAKE, MAKE SURE TO HAVE _target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)_ IN THE CMAKELISTS FILE**

^This is because some functions used were introduced in C++17 so it is advised to run at least C++ standard 20 or more recent as  shown above

As many things were explored before settling on the current version, the commented out trials using _type_traits_, _std::variants_ etc. are still in the run file of the "Type Fix" branch

The program can hopefully handle most inputs, whether it's matrices with strings or typical numerical data types
