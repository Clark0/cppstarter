set nocompatible
filetype off

let mapleader = " "
nnoremap <leader>i :vsp input.txt<cr>
map <leader>h <C-w>h
map <leader>l <C-w>l
map <leader>j <C-w>j
map <leader>k <C-w>k
autocmd filetype cpp nnoremap <leader>b :w <bar> !g++ -ulimit -Wall -Wno-unused-result -std=c++11   -O2   % -o %:r && ./%:r < ./input.txt <cr>
autocmd filetype cpp nnoremap <leader>v :w <bar> !g++ -ulimit -Wall -Wno-unused-result -std=c++11   -O2   % -o %:r && ./%:r <cr>

syntax on
set nu
set clipboard=unnamedplus
set mouse=a
set tabstop=2
set autoindent
set shiftwidth=2
set softtabstop=2
set smarttab
set expandtab
set backspace=indent,eol,start

autocmd BufWritePre * :%s/\s\+$//e
autocmd BufNewFile *.cpp 0r ./.template.cpp
