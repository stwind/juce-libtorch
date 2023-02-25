# juce-torchlib

## Build

### Prequisite

- CMake 3.25

### Download and build libtorch

Go to in any folder, e.g. `temp/pytorch`, may take ~2 hours

```sh
TORCH_VERSION=1.13.1

# download
wget https://github.com/pytorch/pytorch/releases/download/v1.13.1/pytorch-v${TORCH_VERSION}.tar.gz
tar -xf pytorch-v${TORCH_VERSION}.tar.gz

# Make a virtual env
conda create --name torch python=3.10 pyyaml typing_extensions
conda activate torch

# compile
mkdir libtorch build && cd build
cmake -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_BUILD_TYPE:STRING=Release -DPYTHON_EXECUTABLE:PATH=`which python3` -DCMAKE_INSTALL_PREFIX:PATH=../libtorch -USE_MPS=ON ../pytorch-v${TORCH_VERSION}
cmake --build . --target install
```

Now `temp/pytorch/libtorch` show be like

```sh
$ tree -L 1 temp/pytorch/libtorch
temp/pytorch/libtorch
├── bin
├── include
├── lib
└── share
```

### Download JUCE

Download [JUCE](https://juce.com/download/) and unzip to a folder, e.g. `temp/JUCE`

```sh
$ tree -L 1 /Users/stwindfy/temp/juce/JUCE
/Users/stwindfy/temp/juce/JUCE
├── BREAKING-CHANGES.txt
├── CMakeLists.txt
├── ChangeList.txt
├── DemoRunner.app
├── LICENSE.md
├── Projucer.app
├── README.md
├── docs
├── examples
├── extras
└── modules
```

### Build and run and test

Configure with CMake

```sh
$ cmake -B build -DTORCH_DIR=<TORCH_DIR> -DJUCE_DIR=<JUCE_DIR>
-- The C compiler identification is AppleClang 13.1.6.13160021
-- The CXX compiler identification is AppleClang 13.1.6.13160021
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Found Torch: /Users/stwindfy/temp/pytorch/libtorch/lib/libtorch.dylib
-- Configuring juceaide
-- Building juceaide
-- Exporting juceaide
-- Performing Test HAVE_FLAG__ffile_prefix_map__Users_stwindfy_projects_juce_libtorch_build__deps_catch2_src__
-- Performing Test HAVE_FLAG__ffile_prefix_map__Users_stwindfy_projects_juce_libtorch_build__deps_catch2_src__ - Success
-- Configuring done
-- Generating done
-- Build files have been written to:
```

Build the project

```sh
$ cd build
$ cmake --build .
```

Run the build target

```sh
$  src/main_artefacts/main
Hello JUCE!
```

run unit test

```sh
$ ctest
Test project juce-libtorch/build
    Start 1: libtorch
1/1 Test #1: libtorch .........................   Passed    0.39 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.40 sec
```

## References

- [sudara/pamplejuce: A JUCE Plugin CI template. JUCE 7 & Catch2 with macOS notarization and Windows EV code signing on Github Actions](https://github.com/sudara/pamplejuce)
- [microsoft/vscode-cmake-tools: CMake integration in Visual Studio Code](https://github.com/microsoft/vscode-cmake-tools)
