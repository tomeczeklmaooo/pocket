<p align="center">
	<img src="https://github.com/user-attachments/assets/ee2ecaa6-a6cb-45e9-925f-fb806cb5def4" width="384px">
</p>

<p align="center">A simple terminal program to track all your finances.</p>

<h2>Description</h2>
Simple and functional finance tracking terminal app, written in C with absolutely no dependencies.

One may look at the code and say it's not great, but I am aware of that fact, and will be working towards improving the codebase over time.

<h3>Features</h3>

- Writing income/expenses to a file
- Reading from the said file and pretty-printing it
- Automatic calculation of all income and expenses, with the difference between the two

<h2>Getting Started</h2>
<h3>Requirements</h3>

- any operating system (on Windows and Mac you might need to tinker with the source code to make it work)
- GCC (to compile)
- terminal with ANSI color code support

<h3>Installation / Building</h3>
You can only build it from source, I'm not providing any executables.

Use either the provided `make.sh` file, or use `gcc src/*.c -o bin/pocket -Wall -Werror -Wextra -std=c23` (make sure the `bin` directory exists)

<h3>Commands</h3>

| Command                                | Description                                                     |
|----------------------------------------|-----------------------------------------------------------------|
| `pocket add-inc <amount> <place: opt>` | add an entry for income, with `amount` and optionally `place`   |
| `pocket add-exp <amount> <place: opt>` | add an entry for expense, with `amount` and optionally `place`  |
| `pocket show`                          | show the full list of income and expenses                       |
| `pocket status`                        | show total value of all income and expenses, and the difference |
| `pocket about`                         | show about information                                          |

> The `amount` value in `add-inc` and `add-exp` is a float value, with the decimal point being a dot.

> When `place` is left empty (ie. omitted) it will result in it being displayed as `(null)` anywhere the file is parsed.

> Pocket will automatically create text files with income/expense entries as needed (when year changes in date).

<h2>Maintainers</h2>
<ul>
	<li>tomeczeklmaooo</li>
</ul>

<h2>License</h2>
This project is licensed under the MIT License - see the <code>LICENSE</code> file for details.