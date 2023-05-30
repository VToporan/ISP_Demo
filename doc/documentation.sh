#!/bin/bash
mkdir build -p
pdflatex -output-directory build main.tex
biber ./build/main
pdflatex -output-directory build main.tex
pdflatex -output-directory build main.tex
