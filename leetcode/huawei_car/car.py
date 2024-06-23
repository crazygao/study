
# If you need to import additional packages or classes, please import here.

direction = (0, 1)

def turn(turn_char):
    global direction
    if (direction == (1, 0) and turn_char == 'L') or (direction == (-1, 0) and turn_char == 'R'):
        direction = (0, 1)
    elif (direction == (1, 0) and turn_char == 'R') or (direction == (-1, 0) and turn_char == 'L'):
        direction = (0, -1)
    elif (direction == (0, 1) and turn_char == 'L') or (direction == (0, -1) and turn_char == 'R'):
        direction = (-1, 0)
    elif (direction == (0, 1) and turn_char == 'R') or (direction == (0, -1) and turn_char == 'L'):
        direction = (1, 0)

def func():
    global direction
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    words = input().strip()
    cur_pos = (0, 0)
    for i in range(len(words)):
        if words[i] == 'L' or words[i] == 'R':
            turn(words[i])
        else:
            cur_pos = (cur_pos[0] + direction[0], cur_pos[1] + direction[1])
    print('(' + str(cur_pos[0]) + ',' + str(cur_pos[1]) + ')')

if __name__ == "__main__":
    func()
