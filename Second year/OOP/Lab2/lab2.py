from enum import Enum
from typing import Self

COLORING = "\033[{}m\033[{}m{}"
PLACING = "\033[{};{}H{}"


class Color(Enum):
    TRANSPARENT = 0
    BLACK = 30
    RED = 31
    GREEN = 32
    YELLOW = 33
    BLUE = 34
    MAGENTA = 35
    CYAN = 36
    WHITE = 37


class Printer:
    _font: dict[str, list[str]] = {}
    _char_width: int = 5
    _char_height: int = 5

    def __init__(self, color: Color, position: tuple[int, int], symbol: str, background_color: Color = Color.TRANSPARENT) -> None:
        self.color = color
        self.background_color = background_color
        self.symbol = symbol
        self.initial_x, self.initial_y = position
        self.current_x, self.current_y = position


    @classmethod
    def load_font(cls, filename: str = "font.txt") -> None:
        try:
            with open(filename, "r") as file:
                cls._font.clear()
                cls._char_height = file.readline().count('|')
                cls._char_width = file.readline().count('_')
                cls._font[' '] = [' '*cls._char_width for _ in range(cls._char_height)]
                while True:
                    char = file.readline().replace('-', '').strip() #удаляем не нужное
                    if char == '':
                        break
                    cls._font[char] = []
                    for _ in range(cls._char_height):
                        line = file.readline()[:cls._char_width]
                        if '-' in line:
                            raise ValueError(f"Font file is not valid, character height is not consistent. List of correct characters: {cls._font.keys()}")
                        cls._font[char].append(line)
        except Exception as e:
            print(f"Error loading font file: {e}")
            raise FileNotFoundError

    @classmethod
    def print_(cls, text: str, color: Color, position: tuple[int, int], symbol: str,
               background_color: Color = Color.BLACK) -> None:
        if not cls._font:
            cls.load_font()

        x, y = position

        output_lines = []
        for _ in range(cls._char_height):
            output_lines.append("")

        for char in text.upper():
            if char not in cls._font:
                raise ValueError(f"Character {char} is not in the font file")


            for line_num in range(cls._char_height):
                if line_num < len(cls._font[char]):
                    rendered = cls._font[char][line_num].replace("*", symbol)
                    output_lines[line_num] += rendered + " "
                else:
                    output_lines[line_num] += " " * (cls._char_width + 1)


        for line_num, line in enumerate(output_lines):
            print(PLACING.format(y + line_num + 1, x + 1,
                                 COLORING.format(color.value, background_color.value + 10, line.rstrip())),
                  end="\n")

        print()

    def __enter__(self) -> Self:
        print(COLORING.format(self.color.value, self.background_color.value + 10, ''), end="")
        return self


    def __exit__(self, *args) -> None:
        print(COLORING.format(Color.TRANSPARENT.value, Color.TRANSPARENT.value + 10, ''), end="")



    def print(self, text: str) -> None:
        if not self._font:
            self.load_font()

        output_lines = []
        for _ in range(self._char_height):
            output_lines.append("")

        x_offset = 0
        for char in text.upper():
            if char not in self._font:
                continue

            for line_num in range(self._char_height):
                if line_num < len(self._font[char]):
                    rendered = self._font[char][line_num].replace("*", self.symbol)
                    output_lines[line_num] += rendered + " "
                else:
                    output_lines[line_num] += " " * self._char_width

            x_offset += self._char_width

        for line in output_lines:
            print(line)

        self.current_x += x_offset


if __name__ == "__main__":
    for _ in range(30):
        print()
    Printer.load_font(filename="font5.txt")
    Printer.print_("MEOW MEOW MEOW", Color.RED, (5, 2), "#", background_color=Color.TRANSPARENT)
    Printer.load_font(filename="font7.txt")
    with Printer(Color.GREEN, (0, 10), "@", background_color=Color.BLACK) as printer:
        printer.print("I love")
        printer.print('IKBFU')