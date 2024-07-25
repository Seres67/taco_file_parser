# taco files parser

!!! Only prints file content to console !!!

## Building

`vcpkg install --triplet=x64-windows-static && cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake"
`

## Usage

To parse .trl files:

`parser.exe --trail <path>`

To parse .xml files:

`parser.exe --marker <path>`
