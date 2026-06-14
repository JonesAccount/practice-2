import 'dart:io';

void main() {
   int counter = 0;
   stdout.write("Enter a number: ");
   counter = int.parse(stdin.readLineSync()!);

   for (int i = 1; i <= counter; i++) {
        print("Number: $i");
   }

   var languages = ["Python", "Dart", "Java", "C++", "JavaScript"];
   for (var lang in languages) {
        print("Language: $lang");
   }

   var prices = {"Apple": 1.5, "Banana": 0.5, "Orange": 0.8};
   for (var price in prices.keys) {
        print("Price of $price: is ${prices[price]}");
   }

   while (counter > 0) {
        print("While: $counter");
        counter--;
   }
   
}
