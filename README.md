# taco files parser

!!! Only prints file content to console !!!

## Building

`mkdir build && cd build && vcpkg install --triplet=x64-windows-static && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake" -G "Ninja" .. && cmake --build .`

## Usage

To parse .trl files:

`parser.exe --trail <path>`

To parse .xml files:

`parser.exe --marker <path>`
