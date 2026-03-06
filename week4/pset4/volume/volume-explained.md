# CS50 Week 4 — Volume

This program modifies the volume of a `.wav` file by multiplying each audio sample by a scaling factor.

---

# Code Walkthrough

```c
#include <stdint.h>
```
Provides fixed-width integer types such as `uint8_t` and `int16_t`.

```c
#include <stdio.h>
```
Provides functions for file input/output like `fopen`, `fread`, and `fwrite`.

```c
#include <stdlib.h>
```
Provides utility functions such as `atof()` to convert strings to floating-point numbers.

```c
const int HEADER_SIZE = 44;
```
Defines the size of the `.wav` header. WAV files always store **44 bytes of metadata** at the start of the file.

```c
int main(int argc, char *argv[])
```
The program accepts **command-line arguments**.

Example usage:

```
./volume input.wav output.wav 2.0
```

```c
if (argc != 4)
```
Ensures the program receives exactly **three arguments**: input file, output file, and scaling factor.

```c
FILE *input = fopen(argv[1], "r");
```
Opens the input audio file in **read mode**.

```c
if (input == NULL)
```
Checks whether the file failed to open.

```c
FILE *output = fopen(argv[2], "w");
```
Creates the output file where the modified audio will be written.

```c
float factor = atof(argv[3]);
```
Converts the scaling factor from a string to a floating-point number.

```c
uint8_t header[HEADER_SIZE];
```
Creates a buffer to temporarily store the **44-byte WAV header**.

```c
fread(header, HEADER_SIZE, 1, input);
```
Reads the header from the input file.

```c
fwrite(header, HEADER_SIZE, 1, output);
```
Writes the same header to the output file so the new file remains a valid `.wav`.

```c
int16_t buffer;
```
Declares a variable to store **one audio sample** at a time.

```c
while (fread(&buffer, sizeof(int16_t), 1, input))
```
Continuously reads audio samples until the file ends.

```c
buffer *= factor;
```
Multiplies the audio sample by the scaling factor to increase or decrease volume.

```c
fwrite(&buffer, sizeof(int16_t), 1, output);
```
Writes the modified sample to the output file.

```c
fclose(input);
fclose(output);
```
Closes both files to ensure all data is saved correctly.

---

# Compile

```
make volume
```

or

```
clang volume.c -o volume
```

Run the program:

```
./volume input.wav output.wav factor
```