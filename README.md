# Ft\_select [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

An implementation of an **in-shell file dialog** using termcaps [a 42 project].

This project aims to learn the very basics of using termcap library in C programming language.
Ft\_select is an argument viewer in the terminal that returns the user selection on the standard output.

## Description

[**WARNING**]: **ft_select uses deprecated and non POSIX compliant functions such as signal(2) and termcaps.
It may not properly work on your system.**

Ft_select displays a list of arguments in the running terminal. Pressing arrow keys on the keyboard will move the cursor throug the list of arguments passed to ft_select.

- `Arrow keys` will move the cursor through the circular list. The cursor underlines the file - appears as an underline font.

- `space` key will select/un-select one or more choices in the displayed list. A selection positions the cursor on the next element in the list if it exists. A selected file appears overlined.

- `return` key validates the selection. It displays the selection to the standard output. Other programs can take the output.

- Ft_select re-organizes the display on window resize or displays a blank screen if the list does not fit the window.

- `ESC` key exists the program.

- `delete` and `backspace` keys removes an element from the list.

- `Ctrl + z` suspends the process and move it in background. (fg will bring in back)

- `Ctrl + c` will end the program.

Authorized functions:

```shell=
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs
open
close
write
malloc
free
read
exit
signal
```


## Requirements

- Termcap library:

```shell=
sudo apt-get install libncurses5-dev
```

## Usage

- Clone the github repository

```shell=
git clone --recurse-submodules https://github.com/Ant0wan/Ft_select.git && cd Ft_select/ && make -j
```

- Build

```shell=
cd Ft_select && make -j
```

- Run, format ./ft_select + arguments

```shell=
./ft_select ARG|...
```
For instance:

```shell=
./ft_select Makefile README.md author ft_select ft_select.en.pdf libft src
```

Output:

<img width="238" alt="screen shot 2017-07-23 at 5 05 13 pm" src="https://user-images.githubusercontent.com/25576444/28504306-aa712164-6fc9-11e7-986d-de43d853c9eb.png">

