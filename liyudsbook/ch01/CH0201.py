from typing import List

board_list = [
    [0, 1, 0, 1, 1],
    [1, 0, 1, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 0, 0, 1, 1],
    [1, 1, 0, 1, 1],
]

board_list_new = [
    [0, 1, 0, 1, 1],
    [1, 0, 1, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 0, 0, 1, 1],
    [1, 1, 0, 1, 1],
]


def fany_not(n: int) -> int:
    if n == 1:
        return 0
    elif n == 0:
        return 1


def judge(board: List[List[int]]):
    for each in board[4]:
        if each == 1:
            return False
    return True


def toggle(board: List[List[int]], x: int, y: int) -> None:
    board[x][y] = fany_not(board[x][y])
    if x - 1 >= 0:
        board[x - 1][y] = fany_not(board[x - 1][y])
    if x + 1 < 5:
        board[x + 1][y] = fany_not(board[x + 1][y])
    if y - 1 >= 0:
        board[x][y - 1] = fany_not(board[x][y - 1])
    if y + 1 < 5:
        board[x][y + 1] = fany_not(board[x][y + 1])


count = 0
for i in range(0, 4):
    for j in range(0, 5):
        if board_list_new[i][j] == 1:
            count += 1
            toggle(board_list_new, i + 1, j)
            for each in board_list_new:
                print(each)
            print(count)
            print("================")
