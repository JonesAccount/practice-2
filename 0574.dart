import 'dart:io';

void main() {
    changeName(String name, int length) {
        for (int i = 1; i < length; i++) {
            stdout.write(name[i]);
        }
    }

    String name = "";
    stdout.write("Enter your name: ");
    name = stdin.readLineSync()!;
    print("Your new name is: ");
    changeName(name, name.length);
}
