void main() {

    newline() { print(""); }

    String text = "text";
    int integer = 10;
    double float = 5.5;
    var list = [];
    var dic = {};
    num number = 4.2;
    String? text2;
    bool booling = true;
    Set<int> nums = {1};
    Map<String, int> mappi = {"Something": 2};
    var v;
    dynamic d;

    newline();
    print(text.runtimeType);
    print(integer.runtimeType);
    print(float.runtimeType);
    print(list.runtimeType);
    print(dic.runtimeType);
    print(number.runtimeType);
    print(text2.runtimeType);
    print(booling.runtimeType);
    print(nums.runtimeType);
    print(mappi.runtimeType);
    print(v.runtimeType);
    print(d.runtimeType);
    newline();
}
