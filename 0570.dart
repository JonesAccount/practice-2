import 'dart:io';

void main() {
    var Students = [];
    int choice = 0;

    while (true) {
        menu();
        stdout.write('\nEnter your choice: ');

        
            choice = int.parse(stdin.readLineSync()!);
          

        switch (choice) {
            case 1:  add_student(Students);         break;
            case 2:  show_students(Students);       break;
            case 3:  print('Exiting the program.'); return;
            default: print('Invalid choice. Please try again.');
        }
    }
}

void menu() {
    var options = ['1. Add student', '2. Show students', '3. Exit'];

    clearScreen();
    print('\n\nMenu:');

    for (var option in options) {
      print(option);
    }
}

void add_student(List students) {
    stdout.write('Enter student name: ');
    var name = stdin.readLineSync();
    
    if (name != null && name.isNotEmpty) {
        students.add(name);
        print('Student added successfully.');
    } else {
        print('Invalid name. Student not added.');
    }

    wait();
}

void show_students(List students) {

    if (students.isEmpty) {
        print('No students to show.');
    } else {
        for (var student in students) {
            print(student);
        }
    }

    wait();
}

void clearScreen() {
    stdout.write('\x1B[2J\x1B[H');
}

void wait() {
    stdin.readLineSync();
}
