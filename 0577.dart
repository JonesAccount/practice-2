import 'dart:io';

void main() {
    stdout.write("Enter something: ");
    var something = stdin.readLineSync();
    print("Your input: $something");
}
