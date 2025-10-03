
# Build
```
mkdir build  
cd build
cmake -G "MinGW Makefiles" ..
cmake -E time make -j
```

# Single DLL
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

## Result
```
DLL Dependency Test Application
===============================
=== Testing Calculator Class ===
Calculator constructed!
Precision: 3
5.1234 + 3.4567 = 8.58
2.5 * 4.2 = 10.5
Calculator destroyed!

=== Testing C Interface ===
Calculator initialized via C interface!
Calculator constructed!
Calculator destroyed!
C interface sum: 30.8

Application finished successfully!
```

# Two DLLs