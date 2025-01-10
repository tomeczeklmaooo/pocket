# Pocket
A simple terminal program to track all your income and expenses.

Commands:
- `pocket add-inc <amount> <place: opt>`: add an entry for income, with `amount` and optionally `place`
- `pocket add-exp <amount> <place: opt>`: add an entry for expense, with `amount` and optionally `place`
- `pocket show`: show the full list of income and expenses
- `pocket status`: show whether the expenses value is greater, equal or less than income value
- `pocket about`: show about information

The `amount` value in `add-inc` and `add-exp` is a float value, with the decimal point being a dot.

Pocket will automatically create text files with income/expense entries as needed (when year changes in date).