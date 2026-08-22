# antiwasm
[![codecov](https://codecov.io/gh/inigo-cobian/antiwasm/graph/badge.svg?token=PQ7N84VMQH)](https://codecov.io/gh/inigo-cobian/antiwasm)

An objdump for WebAssembly (WIP).

Current usage:
`antiwasm [args] --filename [file.wasm]`

Current args:

`--help`: displays help.

`--debug`: Debug mode.

`--verbose`: Verbose mode.

`--pedantic`: Pedantic mode

## Building with Conan

This project uses [Conan 2.x](https://conan.io/) for dependency management and CMake presets for build configuration.

### Prerequisites

- Conan 2.x (`pip install conan`)
- CMake 3.19 or higher
- A C++20 compatible compiler

### Build Steps

1. **Install dependencies** (generates CMake presets and toolchain files):

```bash
conan install . --output-folder=build --build=missing
```

2. **Configure the project** using the Conan-generated preset:

```bash
cmake --preset conan-release
```

3. **Build**:

```bash
cmake --build --preset conan-release
```

### Running Tests

After building, run the test executable:

```bash
cd build/Release
./test/Boost_Tests_run
```