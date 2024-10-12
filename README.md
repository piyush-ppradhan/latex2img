# latex2img
**latex2img** is a simple tool to generate an image from latex expression, which can be easily embedded in presentations.

## Dependencies
- A C++ compiler.
- `pdflatex`

## Build Instructions
```bash
git clone https://github.com/piyush-ppradhan/latex2img
cd latex2img
mkdir build && cd build
cmake .. && make
```

## Usage Instructions
```bash
# If the latex expression is defined in a file
latex2img -font_size 12 -baselineskip 16 -bg "#000000" -fg "#111111" -file "filename" -output "output_name" -border 2
# If the expression is simple enough, it is more convenient to pass it as a string
latex2img -font_size 12 -baselineskip 16 -bg "#000000" -fg "#111111" -string "$\alpha = 2$" -output "output_name" -border 2
```
- Numeric values such as `font_size`, `baselineskip` and `border` are defined in units of `pt`
- `filename` must contain valid latex expression.
- If the binary and the file are not in same directory, the `filename` must include the fullpath.
- `output_name` must not include the file extension.
- The tool generates pdf files, which can be converted to any image format.

## Default Values
- `font_size`: **12**
- `baselineskip`: **font_size + 4**
- `bg`: **"#ffffff"**
- `fg`: **"#000000"**
- `border`: **0**
- `output`: **generated_expression**. This is the filename prefix for all files generated.
