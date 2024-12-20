BRACKETS_INFO = {
    ")": "(",
    "]": "[",
    "}": "{"
}


def printing_errors(string: str, position: int, print_correctness: bool, text="Incorrect bracket!") -> None:
            if print_correctness: print("Строка не существует!")
            print("An error occured While checking brackets")
            print(string)
            print("^".rjust(position + 1))
            print(text)


def check_brackets(brackets: str, BRACKETS_INFO: dict, print_correctness=True, print_errors=True, accept_num=False, accept_alpha=False) -> bool: 
    import queue
    lifo = queue.LifoQueue()
    for position, bracket in enumerate(brackets):
        if bracket in BRACKETS_INFO.values():
            lifo.put(bracket)
        elif bracket in BRACKETS_INFO.keys():
            if (lifo.empty()) or (BRACKETS_INFO[bracket] != lifo.get()):
                if print_errors: printing_errors(brackets, position, print_correctness)
                return False
        else:
            if (not accept_num) and (bracket in "0123456789+-/*."):
                if print_errors: printing_errors(brackets, position, print_correctness, text="Incorrect symbol! Expexted bracket, number or arithmerical operation.")
                return False
            if (not accept_alpha) and (bracket.isalpha()):
                if print_errors: printing_errors(brackets, position, print_correctness, text="Incorrect symbol! Expexted bracket or alpha.")
                return False
    else:
        if lifo.empty():
            if print_correctness: print("The string is correct")
            return True
        else:
            if print_errors: printing_errors(brackets, brackets.rfind(lifo.get()), print_correctness, text="The bracket was never closed!")
            return False