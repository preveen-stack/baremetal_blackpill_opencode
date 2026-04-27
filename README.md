# Baremetal STM32 BlackPill LED Blink

Minimal baremetal project to blink PC13 LED on STM32F411CE (BlackPill).

## Build

```bash
make
```

Output: `build/blink.bin`

## Flash

```bash
st-flash erase
st-flash write build/blink.bin 0x08000000
```

## Changelog

### 2025-04-27 - Add README with changelog
- Added README with changelog in reverse chronological order

Co-authored-by: opencode[bot] <info@opencode.ai>
Model: big-pickle (opencode/big-pickle)

### 2025-04-27 - Use build directory and add .gitignore
- Added .gitignore
- Build outputs to build/ directory
- Removed compiled artifacts from repo

Co-authored-by: opencode[bot] <info@opencode.ai>
Model: big-pickle (opencode/big-pickle)

### 2025-04-27 - Initial commit
- Baremetal LED blink for STM32 BlackPill (PC13)
- startup.s with ARM Thumb vector/symbols
- main.c with GPIO configuration
- linker.ld for STM32F411
- Makefile build system

Co-authored-by: opencode[bot] <info@opencode.ai>
Model: big-pickle (opencode/big-pickle)