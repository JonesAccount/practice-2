void main() {
  var list = [1, 2, 3, 4, 5];
  print(list);
  print(list[0] + list[1] + list[2] + list[3] + list[4]);
  list[0] = 10;
  print(list);
  list[4] = 5 - 1;
  print(list);

  var emptyList = [];

  emptyList.add(15);
  emptyList.add(29);
  emptyList.addAll([23, 12, 10, 4]);
  emptyList.insert(1, emptyList[1] + 1);
  emptyList.insertAll(0, [1, 1, 1]);
  emptyList.insertAll(emptyList.length, [1, 1, 1]);


  if (emptyList.isEmpty) {
    print('The list is empty.');
  } else {
    print(emptyList);
  }

  var mixlist = [1, 'two', 3.0, true];
  print(mixlist);
  mixlist.remove(true);
  mixlist.add(false);
  print(mixlist);
  mixlist.removeAt(2);
  print(mixlist);

}
