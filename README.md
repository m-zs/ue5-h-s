# ue5-h-s

This repository contains proprietary source code.

All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

## Commands

### Formatting
```
$ Get-ChildItem -Path Source/h_s -Recurse -Include *.cpp,*.h | ForEach-Object { clang-format -i $_.FullName }
```
