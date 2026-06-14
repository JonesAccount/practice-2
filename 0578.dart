import 'dart:io';

void main() {
    stdout.write("\n\n\nEnter your name: ");
    String? name = stdin.readLineSync();

    stdout.write("Enter your age: ");
    String? input = stdin.readLineSync();
    int age = int.parse(input ?? "0");

    print("\nHello $name $age years old!\n\n\n");
}
