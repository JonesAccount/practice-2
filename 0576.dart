void main() {
    void foo(String name1, {String name2 = "Bob"}) {
        print("Hello $name1 and $name2");
    }

    foo("Alice");
}
