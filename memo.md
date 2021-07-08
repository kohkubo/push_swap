# push_swap

## 使える関数

- write
- read
- malloc
- free
- exit

## 実行結果

- 実行ファイル
  - checker
  - push_swap

## 目標

昇順の番号をスタックaにsortする


## 例

最初
2
1
3
6
5
8

最後
1
2
3
5
6
8

シンプルに考えるなら
一番大きい数からbに入れてpushし直す

順番の情報をもたせる
2
1
3
6
5
8

### sa

1
2
3
6
5
8

### pa pa pa

6 3
5 2
8 1

### sa pa pa pa

  8
  6
  5
  3
  2
  1

### pb pb pb pb pb pb

1
2
3
5
6
8
