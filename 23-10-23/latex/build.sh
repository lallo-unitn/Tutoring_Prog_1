#!/bin/sh

if [ $# -ne 1 ]; then
	echo "Wrong number of arguments"
	echo "The syntax is ./build.sh <name_file_tex>"
	echo "<name_file_tex> must be written without extension"
	exit 1
fi

if ! type pdflatex > /dev/null; then
	echo "Command pdflatex missing"
	exit 2
fi

if ! type biber > /dev/null; then
	echo "Command biber missing"
	exit 3
fi

#if ! type pandoc > /dev/null; then
#	echo "Command pandoc missing"
#	exit 4
#fi

pdflatex -shell-escape $1 -interaction=batchmode
# biber $1 
# pdflatex $1 -interaction=batchmode
pdflatex -shell-escape $1 -interaction=batchmode
# pandoc $1.tex --biblatex -s --toc -o ./$1.md

#Brute force to remove all files except .tex, .bib, .pdf, .sh, .md, .gitignore, LICENSE
#find . -maxdepth 1 -type f ! -name "*.bib" ! -name "*.sh" ! -name "*.tex" ! -name "*.pdf" ! -name '*.md' ! -name ".gitignore" ! -name "LICENSE" -exec rm {} \;

rm -f *.aux *.log *.nav *.out *.snm *.gz *.toc *.vrb *.bcf *.blg *.xml *.bbl #> /dev/null
