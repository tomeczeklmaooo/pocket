# Pocket
A simple terminal program to track all your income and expenses.

Commands:
- `pocket init <year> <amount>`: start a new `year` and specify the initial `amount` of money
- `pocket add-inc <amount> <place: opt>`: add an entry for income, with `amount` and optionally `place` (where the money came from)
- `pocket add-exp <amount> <place: opt>`: add an entry for expense, with `amount` and optionally `place` (where the money was spent)
- `pocket show`: show the full list of income and expenses, pair with the `less` Linux command when the list is very long
- `pocket status`: show whether the expenses value is greater, equal or less than income value
- `pocket about`: show about information

The `amount` value in `add-inc` and `add-exp` is a float value, with the decimal point being a dot.