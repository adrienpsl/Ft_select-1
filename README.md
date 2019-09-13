# Ft_select [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

An implementation of an **in-shell file dialog** using termcaps [a 42 project].

This project aims to learn the very basics of using termcap library in C programming language.
Ft_select is an argument viewer in the terminal that returns the user selection on the standard output.

## Description

\[WARNING\]: ft_select uses deprecated and non POSIX compliant functions such as signal(2) and termcaps.
It may not properly work on your system.

Ft_select displays a list of arguments in the running terminal. Pressing arrow keys on the keyboard will move the cursor throug the list of arguments passed to ft_select.

For instance:
```shell=
./ft_select arg1 arg2 arg3 arg4 arg5
```

- Arrow keys will move the cursor through the circular list. The cursor underlines the file - appears as an underline font.

- Space key will select/un-select one or more choices in the displayed list. A selection positions the cursor on the next element in the list if it exists. A selected file appears overlined.

- Return key validates the selection. It displays the selection to the standard output. Other programs can take the output.

- Ft_select re-organizes the display on window resize or displays a blank screen if the list does not fit the window.

- ESC key exists the program.

- Delete and Backspace keys removes an element from the list.

[![ft_select display](https://user-images.githubusercontent.com/25576444/28504306-aa712164-6fc9-11e7-986d-de43d853c9eb.png)
(illustration)](user-images.githubusercontent.com/25576444/28504306-aa712164-6fc9-11e7-986d-de43d853c9eb.png)


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

- Run

```shell=
./ft_select ARG|...
```

