# printbin
Simple c++ util for print of file contents in binary format

## How use it?


```bash
printbin <file>
```

or

```bash
printbin <file> <max print byte>
```

```bash
# printbin_qnx_x86 file.bin
File: file.bin
File size: 20
B1 1A 90  0  2 4B 16 36 41 70 70 6C 69 63 61 74 69 6F 6E  0
#
# printbin_qnx_x86 file.bin 10
File: file.bin
File size: 20
10
Max printed size: 10
B1 1A 90  0  2 4B 16 36 41 70 70 6C
```