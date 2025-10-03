```
DllDependencyTest/
├── CMakeLists.txt
├── mydll/
│   ├── CMakeLists.txt
│   ├── include/
│   │   └── mydll.h
│   └── src/
│       └── mydll.cpp
├── myapp/
│   ├── CMakeLists.txt
│   └── src/
│       └── main.cpp
└── build/
```

# Build
```
mkdir build  
cd build
cmake -G "MinGW Makefiles" ..
cmake -E time make -j
```
