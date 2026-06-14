import 'dart:io';

void main() {
    var students = {"Alice":   "Genius",
                    "Bob":     "Smart",
                    "Charlie": "Middle",
                    "David":   "Stupid",
                    "Eve":     "Autism"};

    print("- GARWARD SCHOOL STUDENTS -\n");
    for (var student in students.keys) {
        print("$student: ${students[student]}");
    }
}
