N, M = 9,9
a_row = 5
n_players = 2
marks = ['B', 'W']
grid = [['.' for x in range(N)] for y in range(M)]

# This function prints the grid of Gomoku as the game progresses
def print_grid():
    for i in range(n_players):
        print('Player %d: %c  ' % (i + 1, marks[i]), end='')
        if i < n_players - 1:
            print('vs  ', end='')
    print()
    print('--' + '---' * M + '--')
    for i in range(N):
        print(end='|  ')
        for j in range(M):
            print(grid[i][j], end='  ')
        print(end='|')
        print()
        print('--' + '---' * M + '--')


# This function checks if the game has a win state or not
def check_win(i,j,mark):
    for i in range(N):
        count1 = count2 = count3 = 0
        for j in range(N):
            if grid[i][j] == mark:
                count1 += 1
                if count1 == 5:
                    return True

            if grid[j][i] == mark:
                count3 += 1
                if count3 == 5:
                    return True


                co1 = 0
                v = j   ; k = i  # dig right

                while j <= v <N and  i <= k<M :

                    if grid[k][v] == mark:
                      co1 += 1
                    else:
                      break
                    v += 1
                    k += 1
                f = j - 1
                x = i - 1
                while -1 < f <j  and  -1 < x <i :
                   if grid[x][f] == mark :
                    co1 += 1
                   else:
                      break
                   f -= 1
                   x -= 1
                if co1 >= 5:
                  return True


    co2 = 0 # dig left
    a = j ;  y = i


    while a < N and -1 < y :
      if grid[y][a] == mark:
        co2 += 1
      else:
        break
      a += 1
      y -= 1
    vc = j - 1
    vb = i + 1
    while -1 < vc and vb < M:
      if grid[vb][vc] == mark:
        co2 += 1
      else :
        break
      vc -= 1
      vb += 1
    if co2 >= 5:
      return True

    return False

# This function checks if the game has a tie state or not for the given mark
def check_tie_player(mark):
    for i in range(N):
        count1 = 0
        for j in range(M):
            if grid[i][j] == mark or grid[i][j] == '.':  # row
                count1 += 1
                if count1 == 5:
                    return False
                else:
                    break

    for j in range(M):
        count2 = 0
        for i in range(N):
            if grid[i][j] == mark or grid[i][j] == '.':  # column
                count2 += 1
                if count2 == 5:
                    return False
                else:
                    break

    for i in range(N // 2):
        for j in range(M):
            i += 1
            count3 = 0
            if grid[i][j] == mark or grid[i][j] == '.':  # d right
                count3 += 1
                if count3 == 5:
                    return False
            else:
                break

    for j in range(M//2+1):
        for i in range(N):
            j+=1
            count3=0
            if grid[i][j] == mark or grid[i][j] == '.' :
                count3 += 1
                if count3 == 5:
                    return False
            else:
                break

    for j in range(M // 2, M):
        for i in range(N):
            j -= 1
            count3 = 0
            if grid[i][j] == mark or grid[i][j] == '.':  # d left
                count3 += 1
                if count3 == 5:
                    return False
            else:
                break

    for i in range(N // 2):
        for j in range(M-1,0,-1):
            i+=1
            count3 = 0
            if grid[i][j] == mark or grid[i][j] == '.':  # d right
                count3 += 1
                if count3 == 5:
                    return False
            else:
                break
    return True

# This function checks if the game has a tie state or not
def check_tie():
    n_players=2
    all_tie = True
    for i in range(n_players):
        if not check_tie_player(marks[i]):
            all_tie = False
    return all_tie
    """for i in range(N):
        for j in range(M):
            if grid[i][j] == '.':
                return False
    return True"""


# This function checks if given cell is empty or not
def check_empty(i, j):
    empty = grid[i][j] == '.'
    return empty


# This function checks if given position is valid or not
def check_valid_position(i, j):
    valid = (0<=i < N and 0<=j < M)
    return valid


# This function sets the given mark to the given cell
def set_cell(i, j, mark):
    grid[i][j] = mark


# This function clears the game structures
def grid_clear():
   global grid
   grid = [['.' for x in range(N)] for y in range(M)]


# This function reads a valid position input
def read_input():
    i, j = map(int, input('Enter the row index and column index: ').split())
    while not check_valid_position(i, j) or not check_empty(i, j):
        i, j = map(int, input('Enter a valid row index and a valid column index: ').split())
    return i, j


# MAIN FUNCTION
def play_game():
    print("Gomoku Game!")
    print("Welcome...")
    print("============================")
    player = 0
    while True:
        # Prints the grid
        print_grid()
        # Read an input position from the player
        print('Player %s is playing now' % marks[player])
        i, j = read_input()
        # Set the player mark in the input position
        set_cell(i, j, marks[player])
        # Check if the grid has a win state
        if check_win(i,j,marks[player]):
            # Prints the grid
            print_grid()
            # Announcement of the final statement
            print('Congrats, Player %s is won!' % marks[player])
            break
        # Check if the grid has a tie state
        if check_tie():
            # Prints the grid
            print_grid()
            # Announcement of the final statement
            print("Woah! That's a tie!")
            break
        # Player number changes after each turn
        player = (player + 1) % n_players


while True:
    grid_clear()
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
