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
latex2img -font_size 12 -baselineskip 16 -bg "#000000" -fg "#111111" -file "filename" \
-output "output_name" -border 2 -preview 0
# If the expression is simple enough, it is more convenient to pass it as a string
latex2img -font_size 12 -baselineskip 16 -bg "#000000" -fg "#111111" -string "$\alpha = 2$" \
-output "output_name" -border 2 -preview 0
```
- `font_size`, `baselineskip` are defined in units of `pt` while `border` is defined in `cm`.
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
- `preview`: **0**. If it is set to 1, the images are generated in `preview` i.e., with equation number.
- Atleast one of `string`  or `file` must be specified.

## Preview vs Non-preview mode
### Preview mode
- If `preview` is set to 1, then images are generated in "preview" mode.
- In this case, to get equation number, wrap the code in `\begin{equation} ... \end{equation}`:
    ```tex
    \begin{equation}
        alpha = 2 \tag{10}
    \end{equation}
    ```
- `\tag{...}` can be used to set a specific equation number.
### Non-preview mode (default)
- If `preview` is set to 0
- In this case, wrap the code in `$ ... $`:
    ```tex
    $alpha = 2$
    ```

