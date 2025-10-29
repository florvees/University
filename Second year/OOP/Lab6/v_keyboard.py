from typing import Optional
import json
from commands import *
from memento import KeyboardMemento

class VirtualKeyboard:
    def __init__(self) -> None:
        self.key_bindings: dict[str, Command] = {}
        self.output = OutputState()
        self.history: list[Command] = []
        self.undo_stack: list[Command] = []

        self.init_default_bindings()
        
    def init_default_bindings(self) -> None:
        self.bind_key("a", PrintCharCommand("a", self.output))
        self.bind_key("b", PrintCharCommand("b", self.output))
        self.bind_key("c", PrintCharCommand("c", self.output))
        self.bind_key("d", PrintCharCommand("d", self.output))
        self.bind_key("ctrl++", VolumeUpCommand(self.output))
        self.bind_key("ctrl+-", VolumeDownCommand(self.output))
        self.bind_key("ctrl+p", MediaPlayerCommand(self.output))
        self.bind_key("undo", None)  
        self.bind_key("redo", None)  
        
    def bind_key(self, key: str, command: Optional[Command]) -> None:
        self.key_bindings[key] = command
        
    def press_key(self, key: str) -> str | None:
        if key == "undo":
            return self.undo()
        elif key == "redo":
            return self.redo()
            
        print(f"\033[33m{self.key_bindings}\033[0m")
        command = self.key_bindings.get(key)
        if command:
            result = command.execute()
            self.history.append(command)
            self.undo_stack.clear()  
            return result
        return f"Unknown key: {key}"
        
    def undo(self) -> str:
        if not self.history:
            return "Nothing to undo"
            
        command = self.history.pop()
        result = command.undo()
        self.undo_stack.append(command)
        return f"undo: {result}"
        
    def redo(self) -> str:
        if not self.undo_stack:
            return "Nothing to redo"
            
        command = self.undo_stack.pop()
        result = command.redo()
        self.history.append(command)
        return f"redo: {result}"
        
    def save_state(self, filename: str = "data/keyboard_state.json") -> None:
        memento = KeyboardMemento.from_keyboard(self)
        with open(filename, "w") as f:
            json.dump(memento.state, f)
            
    def load_state(self, filename: str = "data/keyboard_state.json") -> bool:
        try:
            with open(filename, "r") as f:
                state = json.load(f)

            class_names = {cls.__name__: cls for cls in Command.__subclasses__()}
            print(class_names)
                
            self.key_bindings = {}
            raw_key_bindings = state.get("key_bindings", {})
            for bind, command_data in raw_key_bindings.items():
                print(command_data)
                if command_data[0] is None:
                    self.key_bindings[bind] = None
                else:
                    command_data[1].update({"output": self.output})
                    command = class_names[command_data[0]](**command_data[1])
                    print(command)
                    self.key_bindings[bind] = command
            self.output.set_state(state.get("output_state", {}))
            return True
        except (FileNotFoundError, json.JSONDecodeError):
            return False
