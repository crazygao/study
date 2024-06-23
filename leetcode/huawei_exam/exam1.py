
# If you need to import additional packages or classes, please import here.

def func():

    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    words = input()
    output = ""
    # please finish the function body here.
    # calculate word lengths
    for c in words:
        if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
            c = c.upper()
        elif c > 'A' and c <= 'Z' and c != 'E' and c != 'I' and c != 'O' and c != 'U':
            c = c.lower()
        output += c
    # please define the python3 output here. For example: print().
    # calculate average of word lengths, round to 2 decimal places
    print(output)

if __name__ == "__main__":
    func()
