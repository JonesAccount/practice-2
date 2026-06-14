import 'dart:io';

void main() {
    Hello(String text, name1, [String? name2, String? name3]) {
        stdout.write("$text $name1");

        if (name2 != null) {
            if (name3 == null) {
                stdout.write(" and $name2");
            } else {
                stdout.write(", $name2 and $name3");
            }
            
        }

        print("!");
    }

    Hello("Hi", "Alice", "Bob", "Charlie");
}
