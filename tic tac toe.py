theBoard = {'top-l':' ', 'top-m':' ', 'top-r':' ',
            'mid-l':' ', 'mid-m':' ', 'mid-r':' ',
            'low-l':' ', 'low-m':' ', 'low-r':' '}

def printboard(board):
    print(board['top-l'] + '|' + board['top-m'] + '|' + board['top-r'])
    print('-+-+-')
    print(board['mid-l'] + '|' + board['mid-m'] + '|' + board['mid-r'])
    print('-+-+-')
    print(board['low-l'] + '|' + board['low-m'] + '|' + board['low-r'])

def check_win(board, player):
    win_conditions = [
        ['top-l', 'top-m', 'top-r'],
        ['mid-l', 'mid-m', 'mid-r'],
        ['low-l', 'low-m', 'low-r'],
        ['top-l', 'mid-l', 'low-l'],
        ['top-m', 'mid-m', 'low-m'],
        ['top-r', 'mid-r', 'low-r'],
        ['top-l', 'mid-m', 'low-r'],
        ['top-r', 'mid-m', 'low-l'],
    ]
    for condition in win_conditions:
        if all(board[pos] == player for pos in condition):
            return True
    return False

turn = 'X'
for i in range(9):
    printboard(theBoard)
    move = input(f"Turn for {turn}. Move on which space? ")

    # Validate input
    if move not in theBoard:
        print("Invalid move. Please choose a valid space like 'top-l', 'mid-m', etc.")
        continue
    if theBoard[move] != ' ':
        print("Space already taken. Choose another.")
        continue

    # Make the move
    theBoard[move] = turn

    # Check for win
    if check_win(theBoard, turn):
        printboard(theBoard)
        print(f"Player {turn} wins!")
        break  # Stop the game

    # Switch player
    turn = 'O' if turn == 'X' else 'X'
else:
    printboard(theBoard)
    print("It's a tie!")
