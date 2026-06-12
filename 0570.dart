import 'dart:io';

void clearScreen() {
  if (Platform.isWindows) {
    Process.runSync('cls', [], runInShell: true);
  } else {
    Process.runSync('clear', [], runInShell: true);
  }
}

void show_list(List students) {
  for (var student in students) {
    print(student);
  }
}

void menu() {
  var options = ['1. Add student', '2. Show students', '3. Exit'];

  print('Menu:');

  for (var option in options) {
    print(option);
  }
}

void main() {
  var Students = [];
  int choice = 0;

  while (true) {
    menu();
    print('Enter your choice:');

    if (choice != null) {
      choice = int.parse(stdin.readLineSync()!);
      clearScreen();
    }

    switch (choice) {
      case 1:
        Students.add('Jonh');
        break;
      case 2:
        print(Students);
        break;
      case 3:
        print('Exiting the program.');
        return;
      default:
        print('Invalid choice. Please try again.');
    }
  }
}
