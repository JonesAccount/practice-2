void main() {
    String a = "5", b = "2", c = "4";
    int resultI = int.parse(a) + int.parse(b) + int.parse(c);
    print("$resultI\n");

    String d = "0.3", e = "2.7", f = "1.1";
    double resultD = double.parse(d) + double.parse(e) + double.parse(f);
    print("$resultD\n");

    int g = 5, h = 2;
    double t = 0.5;
    String resultT = g.toString() + h.toString() + t.toString();
    print("$resultT\n");
}
