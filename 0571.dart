void main() {
    var dictionary = {"Key1": "Value1", "Key2": "Value2", "Key3": "Value3"};
    print(dictionary);
    print(dictionary["Key1"]);
    print(dictionary.values);
    print(dictionary.keys);
    print(dictionary.length);
    dictionary["Key4"] = "Value4";
    print(dictionary);
    dictionary.addAll({"Key5": "Value5", "Key6": "Value6"});
    print(dictionary);
    dictionary.remove("Key2");
    print(dictionary);
    dictionary.clear();
    if (dictionary.isEmpty) {
        print("Dictionary is empty.");
    } else {
        print(dictionary);
    }
}
