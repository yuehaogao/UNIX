Build and test like this:

    mkdir build
    cd build
    cmake ..
    cmake --build .
    export PATH=$PATH:`pwd`
    sine-sweep | wav-write

UNIX philosophy is sortof like Max. We make lots of little programs that generate outputs and/or analyse or process inputs. We then wires these together to make more complex programs.

Complete empty code files:

- `impulse.cpp`
- `sawtooth.cpp`
- `square.cpp`
- `triangle.cpp`
- `impulse-sweep.cpp`
- `sawtooth-sweep.cpp`
- `square-sweep.cpp`
- `triangle-sweep.cpp`

and change `CMakeLists.txt` to add new executable targets.
