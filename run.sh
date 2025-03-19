mkdir build
cd build || exit
cmake ..
bear -- make -j 16
./Exploration
